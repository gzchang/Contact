#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxName 20
#define MaxSex 5
#define MaxTele 12
#define MaxAddr 30
#define DEFAULT_CAPACITY 3

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


typedef struct People
{
	char name[MaxName];
	int age;
	char sex[MaxSex];
	char tele[MaxTele];
	char addr[MaxAddr];
} People;

typedef struct Contact
{
	struct People *data;
	int Size;//�Ѿ��е�Ԫ�ظ���
	int Capacity;//��ǰͨѶ¼���������
} Contact;

// ���� ���ܺ��� 
void InitContact(struct Contact* con);
void AddContact(struct Contact* con);
void ShowContact(const struct Contact* con);//ֻΪ����ʾ const����ָ�� ��ʾָ��ָ������ݲ������޸�
void DelContact(struct Contact* con);
void SearchContact(const struct Contact* con);
void ModifyContact(struct Contact* con);
void SortContact(struct Contact* con);
void ExitContact(Contact* con);