#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

void InitContact(struct Contact* con) {
	memset(con->data,0,sizeof(con->data));//sizeof�������� ֱ�����������Ĵ�С ��λ���ֽ�
	con->Size = 0;

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

void AddContact(struct Contact* con) {
	if (con->Size==MaxSize)
	{
		printf("ͨѶ¼�����������޷�����\n");
	}
	else {
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
	for (i = 0; i < con->Size-1; i++) {
		for (j = i; j < con->Size - 1 - i; j++) {
			if (strcmp(con->data[j].name, con->data[j + 1].name)) {
				struct People tmp;
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