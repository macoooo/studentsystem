#include"list.h"
int  main()
{
	int flag = 1, tag = 1;
	char cc[20], ex[20];
	while (flag) {
		printmenu();
		while (1) {
			printf("请输入想要实现的: ");
			scanf("%s", ex);
			if (!strcmp(ex, "1")) {
				
				tag = login2();
				while (tag) {
					system("CLS");
					printf("\t\t    ******欢迎进入学生管理系统******\n");
					printf("\t\t|---------------管理员操作-------------|\n");
					printf("\t\t|-------------2.录入学生信息-----------|\n");
					printf("\t\t|-------------3.查询学生信息-----------|\n");
					printf("\t\t|-------------4.修改学生信息-----------|\n");
					printf("\t\t|-------------5.插入新的学生信息-------|\n");
					printf("\t\t|-------------6.删除学生信息-----------|\n");
					printf("\t\t|-------------7.统计学生信息-----------|\n");
					printf("\t\t|-------------8.对信息排序-------------|\n");
					printf("\t\t|------------退出管理员登录请按0-------|\n");
					printf("\t 请选择功能2-8:");
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
							printf("输入错误,请重新输入：\n ");
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
				printf("\t\t--谢谢使用！--\n");
				flag = 0;
				break;
			}
			else {
				printf("输入错误，请重新输入: ");
			}
		}
	}
}



