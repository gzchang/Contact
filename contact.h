#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxName 20
#define MaxSex 5
#define MaxTele 12
#define MaxAddr 30
#define DEFAULT_CAPACITY 3

// 增加枚举类型
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
	int Size;//已经有的元素个数
	int Capacity;//当前通讯录的最大容量
} Contact;

// 声明 功能函数 
void InitContact(struct Contact* con);
void AddContact(struct Contact* con);
void ShowContact(const struct Contact* con);//只为了显示 const修饰指针 表示指针指向的内容不允许被修改
void DelContact(struct Contact* con);
void SearchContact(const struct Contact* con);
void ModifyContact(struct Contact* con);
void SortContact(struct Contact* con);
void ExitContact(Contact* con);