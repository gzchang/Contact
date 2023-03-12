#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

static void CheckCapacity(struct Contact* con);
void InitContact(struct Contact* con) {

	//memset(con->data,0,sizeof(con->data));//sizeof跟数组名 直接是这个数组的大小 单位是字节
	//con->Size = 0;

	con->data = (struct People*)malloc(sizeof(struct People) * 3);
	if (con->data == NULL)
		return;
	con->Size = 0;
	con->Capacity = DEFAULT_CAPACITY;
	//把文件存放的信息 加载到通讯录里面
	LoadContact(con);
}

void LoadContact(Contact* con) {
	FILE* pf = fopen("./contact.dat", "rb");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	// 读取文件 放到通讯录中
	People tmp = {0};
	while (fread(&tmp, sizeof(People), 1, pf)) {// 一个一个读，fread函数 返回实际读到的个数 读到0其实就是结束位置
		CheckCapacity(con);
		con->data[con->Size] = tmp;
		con->Size++;
	}

	fclose(pf);
	pf = NULL;
}

// 支持函数 接口不需要被暴露 static 修饰的函数只能在此源文件使用
static int FindByName(const struct Contact* con, char name[MaxName]) {
	int i = 0;
	for (i = 0; i < con->Size; i++) { 
		if (0 == strcmp(con->data[i].name, name)) {
			return i;
		}
	}
	return -1;
}

static void CheckCapacity(struct Contact* con) {
	if (con->Size == con->Capacity)
	{
		struct People* ptr = (People*)realloc(con->data, (con->Capacity + 2) * sizeof(struct People));
		if (ptr != NULL) {
			con->data = ptr;
			con->Capacity += 2;
			printf("增容成功！\n");
		}
		else {
			printf("增容失败\n");
		}
	}

}

void AddContact(struct Contact* con) {
	//满了就增容 不满不干
	CheckCapacity(con);//检测当前通讯录的容量
	// 增加数据
	printf("请输入名字：");
	scanf("%s", con->data[con->Size].name);
	printf("请输入年龄；");
	scanf("%d", &(con->data[con->Size].age));
	printf("请输入性别；");
	scanf("%s", (con->data[con->Size].sex));
	printf("请输入电话；");
	scanf("%s", (con->data[con->Size].tele));
	printf("请输入地址；");
	scanf("%s", (con->data[con->Size].addr));
	con->Size++;
	printf("添加成功!\n");
}

void ShowContact(const struct Contact* con) {
	if (con->Size == 0)
	{
		printf("通讯录为空");
	}
	else {
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
		for ( i = 0; i < con->Size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				con->data[i].name,
				con->data[i].age,
				con->data[i].sex,
				con->data[i].tele,
				con->data[i].addr);
		}
	}
}

void DelContact(struct Contact* con){
	printf("请输入要删除的人的名字");
	char name[MaxName];
	scanf("%s", name);
	//1.查找要删除的人的位置
	// 找到返回下标 找不到返回-1
	int pos = FindByName(con, name);
	//2.删除
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else {
		// 删除数据
		int j = 0;
		for (j = pos; j < con->Size-1; j++) {
			con->data[j] = con->data[j + 1];
		}
		con->Size--;
		printf("删除成功！\n");
	}
}

void SearchContact(const struct Contact* con) {
	char name[MaxName];
	printf("请输入你输入的名字");
	scanf("%s", name);
	int pos = FindByName(con, name);
	if (pos == -1)
	{
		printf("要查找的人不存在");
	}
	else {
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			con->data[pos].name,
			con->data[pos].age,
			con->data[pos].sex,
			con->data[pos].tele,
			con->data[pos].addr);
	}
}

void ModifyContact(struct Contact* con) {
	char name[MaxName];
	printf("请输入你想要修改人的名字");
	scanf("%s", name);
	int pos = FindByName(con, name);
	if (pos == -1)
	{
		printf("修改的人不存在");
	}
	else {
		printf("请输入名字：");
		scanf("%s", con->data[pos].name);
		printf("请输入年龄；");
		scanf("%d", &(con->data[pos].age));
		printf("请输入性别；");
		scanf("%s", (con->data[pos].sex));
		printf("请输入电话；");
		scanf("%s", (con->data[pos].tele));
		printf("请输入地址；");
		scanf("%s", (con->data[pos].addr));
		printf("修改成功!\n");
	}
}

void SortContact(struct Contact* con) {
	int i = 0;
	int j = 0;
	struct People tmp;
	for (i = 0; i < con->Size-1; i++) {
		for (j = i; j < con->Size - 1 - i; j++) {
			if (strcmp(con->data[j].name, con->data[j + 1].name)>0) {
				tmp = con->data[j];
				con->data[j] = con->data[j + 1];
				con->data[j + 1] = tmp;
			}
		}
	}
	printf("排序完毕\n");
	printf("***************\n");
	ShowContact(con);
}

void ExitContact(Contact* con) {
	free(con->data);
	con->data = NULL;
}

void SaveContact(Contact* con) {
	FILE* pf = fopen("./contact.dat", "wb");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return ;
	}
	// 写通讯录到文件中
	int i = 0;
	for (i = 0; i < con->Size; i++) {
		fwrite(&(con->data[i]), sizeof(People), 1, pf);
	}
	printf("保存成功!\n");
	fclose(pf);
	pf = NULL;
}