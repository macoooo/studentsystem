#include"list.h"
int  main()
{
	int flag = 1, tag = 1;
	char cc[20], ex[20];
	while (flag) {
		printmenu();
		while (1) {
			printf("��������Ҫʵ�ֵ�: ");
			scanf("%s", ex);
			if (!strcmp(ex, "1")) {
				
				tag = login2();
				while (tag) {
					system("CLS");
					printf("\t\t    ******��ӭ����ѧ������ϵͳ******\n");
					printf("\t\t|---------------����Ա����-------------|\n");
					printf("\t\t|-------------2.¼��ѧ����Ϣ-----------|\n");
					printf("\t\t|-------------3.��ѯѧ����Ϣ-----------|\n");
					printf("\t\t|-------------4.�޸�ѧ����Ϣ-----------|\n");
					printf("\t\t|-------------5.�����µ�ѧ����Ϣ-------|\n");
					printf("\t\t|-------------6.ɾ��ѧ����Ϣ-----------|\n");
					printf("\t\t|-------------7.ͳ��ѧ����Ϣ-----------|\n");
					printf("\t\t|-------------8.����Ϣ����-------------|\n");
					printf("\t\t|------------�˳�����Ա��¼�밴0-------|\n");
					printf("\t ��ѡ����2-8:");
					while (1) {
						scanf("%s", cc);
			        	if (!strcmp(cc, "2")) {
							phead=luru();
							break;
						}
						else if (!strcmp(cc, "3")) {
							chazhao();
							break;
						}
						else if (!strcmp(cc, "4")) {
							repair();
							break;
						}
						else if (!strcmp(cc, "5")) {
							insert();
							break;
						}
						else if (!strcmp(cc, "6")) {
							delete();
							break;
						}
						else if (!strcmp(cc, "7")) {
							tongji();
							break;
						}
						else if (!strcmp(cc, "8")) {
							sort();
							break;
						}
						else if (!strcmp(cc, "0")) {
							printmenu();
							tag = 0;
							break;
						}
						else {
							printf("�������,���������룺\n ");
						}
					}
				}
			}
			else if (!strcmp(ex, "2")) {
				registers();
				break;
			}
			else if (!strcmp(ex, "3")) {
				login1();
				//find();
				break;
			}
			else if (!strcmp(ex, "0")){
				printf("\t\t--ллʹ�ã�--\n");
				flag = 0;
				break;
			}
			else {
				printf("�����������������: ");
			}
		}
	}
}



