#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

static void CheckCapacity(struct Contact* con);
void InitContact(struct Contact* con) {

	//memset(con->data,0,sizeof(con->data));//sizeof�������� ֱ�����������Ĵ�С ��λ���ֽ�
	//con->Size = 0;

	con->data = (struct People*)malloc(sizeof(struct People) * 3);
	if (con->data == NULL)
		return;
	con->Size = 0;
	con->Capacity = DEFAULT_CAPACITY;
	//���ļ���ŵ���Ϣ ���ص�ͨѶ¼����
	LoadContact(con);
}

void LoadContact(Contact* con) {
	FILE* pf = fopen("./contact.dat", "rb");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	// ��ȡ�ļ� �ŵ�ͨѶ¼��
	People tmp = {0};
	while (fread(&tmp, sizeof(People), 1, pf)) {// һ��һ������fread���� ����ʵ�ʶ����ĸ��� ����0��ʵ���ǽ���λ��
		CheckCapacity(con);
		con->data[con->Size] = tmp;
		con->Size++;
	}

	fclose(pf);
	pf = NULL;
}

// ֧�ֺ��� �ӿڲ���Ҫ����¶ static ���εĺ���ֻ���ڴ�Դ�ļ�ʹ��
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
			printf("���ݳɹ���\n");
		}
		else {
			printf("����ʧ��\n");
		}
	}

}

void AddContact(struct Contact* con) {
	//���˾����� ��������
	CheckCapacity(con);//��⵱ǰͨѶ¼������
	// ��������
	printf("���������֣�");
	scanf("%s", con->data[con->Size].name);
	printf("���������䣻");
	scanf("%d", &(con->data[con->Size].age));
	printf("�������Ա�");
	scanf("%s", (con->data[con->Size].sex));
	printf("������绰��");
	scanf("%s", (con->data[con->Size].tele));
	printf("�������ַ��");
	scanf("%s", (con->data[con->Size].addr));
	con->Size++;
	printf("��ӳɹ�!\n");
}

void ShowContact(const struct Contact* con) {
	if (con->Size == 0)
	{
		printf("ͨѶ¼Ϊ��");
	}
	else {
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
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
	printf("������Ҫɾ�����˵�����");
	char name[MaxName];
	scanf("%s", name);
	//1.����Ҫɾ�����˵�λ��
	// �ҵ������±� �Ҳ�������-1
	int pos = FindByName(con, name);
	//2.ɾ��
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else {
		// ɾ������
		int j = 0;
		for (j = pos; j < con->Size-1; j++) {
			con->data[j] = con->data[j + 1];
		}
		con->Size--;
		printf("ɾ���ɹ���\n");
	}
}

void SearchContact(const struct Contact* con) {
	char name[MaxName];
	printf("�����������������");
	scanf("%s", name);
	int pos = FindByName(con, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����");
	}
	else {
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("����������Ҫ�޸��˵�����");
	scanf("%s", name);
	int pos = FindByName(con, name);
	if (pos == -1)
	{
		printf("�޸ĵ��˲�����");
	}
	else {
		printf("���������֣�");
		scanf("%s", con->data[pos].name);
		printf("���������䣻");
		scanf("%d", &(con->data[pos].age));
		printf("�������Ա�");
		scanf("%s", (con->data[pos].sex));
		printf("������绰��");
		scanf("%s", (con->data[pos].tele));
		printf("�������ַ��");
		scanf("%s", (con->data[pos].addr));
		printf("�޸ĳɹ�!\n");
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
	printf("�������\n");
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
	// дͨѶ¼���ļ���
	int i = 0;
	for (i = 0; i < con->Size; i++) {
		fwrite(&(con->data[i]), sizeof(People), 1, pf);
	}
	printf("����ɹ�!\n");
	fclose(pf);
	pf = NULL;
}