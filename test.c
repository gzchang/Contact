#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"


void menu() {
	printf("**********************************\n");
	printf("***** 1.add\t\t2.del\t****\n");
	printf("***** 3.search\t\t4.modify\t****\n");
	printf("***** 5.show\t\t6.sort\t****\n");
	printf("***** 7.save\t\t0.exit\t****\n");
	printf("**********************************\n");
}

int main(){
	int input = 0;
	//����ͨѶ¼
	struct Contact con;//con����ͨѶ¼�����������dataָ�롢size��capacity
	InitContact(&con);

	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d",&input);
		switch (input){
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);//��Ȼ�ǲ��� ���Ǹ���ַЧ�ʸ�
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
			printf("�˳�ͨѶ¼��\n");
			SaveContact(&con);
			ExitContact(&con);
			exit(0);
			break;
		case SAVE:
			SaveContact(&con);
			break;
		default:
			printf("ѡ�����\n");
		}
	} while (1);

	return 0;
}