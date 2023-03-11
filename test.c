#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"


void menu() {
	printf("**********************************\n");
	printf("***** 1.add\t\t2.del\t****\n");
	printf("***** 3.search\t\t4.modify\t****\n");
	printf("***** 5.show\t\t6.sort\t****\n");
	printf("***** 0.exit\t\t\t****\n");
	printf("**********************************\n");
}

int main(){
	int input = 0;
	//创建通讯录
	struct Contact con;//con就是通讯录，里面包含：1000个元素和当前个数
	InitContact(&con);

	do {
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch (input){
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);//虽然是查找 但是给地址效率高
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("退出通讯录！\n");
			exit(0);
			break;
		default:
			printf("选择错误！\n");
		}
	} while (1);

	return 0;
}