#include <stdio.h>
#include <string.h>

#define MaxSize 10
#define MaxName 20
#define MaxSex 5
#define MaxTele 12
#define MaxAddr 30

// ����ö������
enum Option {
	EXIT,//0
	ADD,//1
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};


struct People
{
	char name[MaxName];
	int age;
	char sex[MaxSex];
	char tele[MaxTele];
	char addr[MaxAddr];
};

struct Contact
{
	struct People data[MaxSize];
	int Size;//�Ѿ��е�Ԫ�ظ���
};

// ���� ���ܺ��� 
void InitContact(struct Contact* con);
void AddContact(struct Contact* con);
void ShowContact(const struct Contact* con);//ֻΪ����ʾ const����ָ�� ��ʾָ��ָ������ݲ������޸�
void DelContact(struct Contact* con);
void SearchContact(const struct Contact* con);
void ModifyContact(struct Contact* con);
void SortContact(struct Contact* con);