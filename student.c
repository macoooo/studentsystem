#include"list.h"
void printmenu()
{
	system("CLS");
	printf("\t\t|---------------------------------------|\n");
	printf("\t\t|--------欢迎进入学生管理系统-----------|\n");
	printf("\t\t|----------- 管理员登录请按1------------|\n");
	printf("\t\t|------------学生注册请按2--------------|\n");
	printf("\t\t|------------学生登录请按3--------------|\n");
	printf("\t\t|------------退出系统请按0--------------|\n");
}
List luru()//添加信息
{
	FILE *fp;
	int i, tag = 0,lala = 0, wf = 1;
	List phead, p, stu, q, head;
	phead = (List)malloc(LEN);
	p = phead;
	phead->next = NULL;
	char  xx[20];
	int flag = 1;
	printf("\t\t|--------------------------|\n");
	printf("\t\t|      学生管理系统        |\n");
	printf("\t\t|--------------------------|\n");
	printf("\t\t|                          |\n");
	printf("\t\t|        输入1添加         |\n");
	printf("\t\t|        输入0退出         |\n");
	printf("\t\t|--------------------------|\n");
		printf("请输入想要添加还是退出：");
		do {
			scanf("%s", xx);
			while (getchar() != '\n')
				continue;
			if (strcmp(xx, "1") && strcmp(xx, "0")) {
				printf("输入错误，请重新输入: \n");
			}
			if (!strcmp(xx, "1") || !strcmp(xx, "0")) {
				break;
			}
		} while (1);
		if (!strcmp(xx, "1")) {
			//system("CLS");
			do {
				head = readfile();
				q = head->next;
				system("CLS");
				stu = (List)malloc(LEN);
				printf("\t\t|--------------------------|\n");
				printf("\t\t|      学生管理系统        |\n");
				printf("\t\t|--------------------------|\n");
				printf("\t\t|                          |\n");
				printf("\t\t|        输入1添加         |\n");
				printf("\t\t|        输入0退出         |\n");
				printf("\t\t|--------------------------|\n");
				printf("请输入学号：");
				
					do {
						scanf("%s", stu->item.id);
						while (strlen(stu->item.id) != 8) {
							printf("亲,学号应该为8位非负整数，请重新输入哦: ");
							scanf("%s", stu->item.id);
						}
						for (i = 0; i < 8; i++) {
							if (stu->item.id[i] < '0' || stu->item.id[i] > '9') {
								printf("同学,请输入八位非负整数: ");
								break;
							}
							else {
								tag = 1;
								break;
							}
						}
					} while (tag == 0);
					while (q != NULL) {
						if (!strcmp(q->item.id, stu->item.id)) {
							wf = 0;
							break;
						}
						q = q->next;
					}
					if (wf == 0) {
						printf("添加的学生已存在,请重新输入：\n");
						do {
							scanf("%s", stu->item.id);
							while (strlen(stu->item.id) != 8) {
								printf("亲,学号应该为8位非负整数，请重新输入哦: ");
								scanf("%s", stu->item.id);
							}
							for (i = 0; i < 8; i++) {
								if (stu->item.id[i] < '0' || stu->item.id[i] > '9') {
									printf("同学,请输入八位非负整数: ");
									break;
								}
								else {
									tag = 1;
									break;
								}
							}
						} while (tag == 0);
					}
				printf("请输入姓名：");
				do {
					scanf("%s", stu->item.name);
					for (i = 0; i < strlen(stu->item.name); i++) {
						if (stu->item.name[i] >= '0' && stu->item.name[i] <= '9') {
							printf("请不要输入数字！请重新输入：");
							break;
						}
						else {
							lala = 1;
							break;
						}
					}
				} while (lala == 0);

				do {
					printf("请输入语文成绩: ");  scanf("%d", &stu->item.chinese);
					while (getchar() != '\n')
						continue;
					printf("请输入数学成绩: ");  scanf("%d", &stu->item.math);
					while (getchar() != '\n')
						continue;
					printf("请输入英语成绩: ");  scanf("%d", &stu->item.english);
					while (getchar() != '\n')
						continue;
					if (stu->item.chinese < 0 || stu->item.chinese>100 || stu->item.math < 0 || stu->item.math>100 || stu->item.english < 0 || stu->item.english>100)
					{
						printf("\t\t______________________\n");
						printf("\t\t_成绩请输入0-100之间__\n");
						printf("\t\t______________________\n");
						printf("\t\t重新输入成绩\n");
					}
					else {
						break;
					}
				} while (1);
				p->next = stu;
				p = stu;
				fp = fopen("D:\\aa.txt", "a+");
				fprintf(fp, "%s %d %d %d %s\n", stu->item.id, stu->item.chinese, stu->item.math, stu->item.english, stu->item.name);

				printf("继续输入请按1，退出请按0：\n");
				do {
					scanf("%s", xx);
					while (getchar() != '\n')
						continue;
					if (strcmp(xx, "1") && strcmp(xx, "0")) {
						printf("输入错误，请重新输入: ");
					}
					if (!strcmp(xx, "1") || !strcmp(xx, "0")) {
						break;
					}
				} while (1);
			} while (!strcmp(xx, "1"));
			p->next = NULL;
		}
		else {
			return;
		}
	fclose(fp);
	return (phead);
}
void savefile(List phead)//将信息存入文件
{
	List stu;
	FILE *fp;
	if ((fp = fopen("aa.txt", "w" ))== NULL) {
		printf("写文件出错，按任意键退出");
		//getchar();
		exit(0);
	}
		for (stu = phead->next; stu != NULL; stu = stu->next) {
			fprintf(fp, "%s %d %d %d %s\n", stu->item.id, stu->item.chinese, stu->item.math, stu->item.english, stu->item.name);
		}
	fclose(fp);
	//printf("文件已成功保存，按任意键返回！");
	//getchar();
}
List readfile()//将信息从文件中读出到链表
{
	List prev, p, phead;
	phead = (List)malloc(LEN);
	//p = phead;
	prev = phead;
	FILE * fp;
	if ((fp = fopen("D:\\aa.txt", "r") ) == NULL) {
		printf("打开失败！");
		exit(0);
	}
	while (!feof(fp)) {
		p = (List)malloc(LEN);
		p->next = NULL;
		prev->next = p;
		fscanf(fp,"%s %d %d %d %s\n", p->item.id, &p->item.chinese, &p->item.math, &p->item.english, p->item.name);
		//printf("%s %d %d %d %s\n", p->item.id, p->item.chinese, p->item.math, p->item.english, p->item.id);
		prev = p;
		p = p->next;
	}
	fclose(fp);
	//printf("文件信息已成功读出，按任意键返回！");
	//getchar();
	return phead;
}
void find()//查找学生信息
{
	List  m, phead;
	phead = readfile();
	char  timp[20],xf[20];
	int flag = 0;
	do{
		printf("请输入要查找的学生学号: ");
		scanf("%s", timp);
		for (m = phead->next; m != NULL; m = m->next)
		{
			if (!strcmp(m->item.id, timp))
			{
				printf("\t\t已经查到改学生的信息\n");
				flag = 0;
				break;
			}
			else
				flag = 1;
		}
		if (flag == 1)
			printf("\t\t抱歉，没有查到该学生的信息\n");
		if (flag == 0)
		{
			printf("\t\t该学生的信息如下\n");
			printf("\t\t学号：%s\n", m->item.id);
			printf("\t\t语文：%d\n", m->item.chinese);
			printf("\t\t数学：%d\n", m->item.math);
			printf("\t\t英语：%d\n", m->item.english);
			printf("\t\t姓名：%s\n", m->item.name);
		}
		printf("继续查找请按1，退出请按0\n");
		printf("请选择继续查找还是退出：");
		scanf("%s", xf);
	} while (!strcmp(xf, "1"));
	
}
void repair()//修改学生信息
{
	int i, flag = 0, tag = 0, lala = 0;
	char xrr[20];
	List m, phead;
	phead = readfile();
	m = (List)malloc(LEN);
	do {
		system("CLS");
		phead = readfile();
		char  timp[20], xf[20];
		int flag = 0;
			printf("请输入要查找的学生学号: ");
			scanf("%s", timp);
			for (m = phead->next; m != NULL; m = m->next)
			{
				if (!strcmp(m->item.id, timp))
				{
					printf("\t\t已经查到改学生的信息\n");
					flag = 0;
					break;
				}
				else
					flag = 1;
			}
			if (flag == 1)
				printf("\t\t抱歉，没有查到该学生的信息\n");
			if (flag == 0)
			{
				printf("\t\t该学生的信息如下\n");
				printf("\t\t学号：%s\n", m->item.id);
				printf("\t\t语文：%d\n", m->item.chinese);
				printf("\t\t数学：%d\n", m->item.math);
				printf("\t\t英语：%d\n", m->item.english);
				printf("\t\t姓名：%s\n", m->item.name);
			}
		do {
			printf("请输入正确的学号：");
			scanf("%s", m->item.id);
			while (strlen(m->item.id) != 8) {
				printf("亲,学号应该为8位非负整数，请重新输入哦: ");
				scanf("%s", m->item.id);
			}
			for (i = 0; i < 8; i++) {
				if (m->item.id[i] < '0' && m->item.id[i] > '9') {
					printf("同学,请输入八位非负整数: ");
					break;
				}
				else {
					tag = 1;
					//break;
				}
			}
		} while (tag == 0);
		do {
			printf("请输入姓名：");
			scanf("%s", m->item.name);
			for (i = 0; i < strlen(m->item.name); i++) {
				if (m->item.name[i] >= '0' && m->item.name[i] <= '9') {
					printf("请不要输入数字！请重新输入：");
					break;
				}
				else {
					lala = 1;
					break;
				}
			}
		} while (lala == 0);

		do {
			printf("请输入语文成绩: ");  scanf("%d", &m->item.chinese);
			printf("请输入数学成绩: ");  scanf("%d", &m->item.math);
			printf("请输入英语成绩: ");  scanf("%d", &m->item.english);
			if (m->item.chinese < 0 || m->item.chinese>100 || m->item.math < 0 || m->item.math>100 || m->item.english < 0 || m->item.english>100)
			{
				printf("\t\t______________________\n");
				printf("\t\t_成绩请输入0-100之间__\n");
				printf("\t\t______________________\n");
				printf("\t\t重新输入成绩\n");
			}
			else {
				break;
			}
		} while (1);
		printf("\t\t该学生信息已修改\n");
		printf("继续修改请按1，退出请按0\n");
		printf("请选择继续修改还是退出：");
		scanf("%s", xrr);
		if (!strcmp(xrr, "0")) {
			break;
		}
	} while (!strcmp(xrr,"1"));
	savefile(phead);
}
void delete()//删除学生信息
{
	List phead, stu1,p,m,t;
	phead = readfile();
	stu1 = (List)malloc(LEN);
	char stux[20],xd[20];
	int flag = 0;
	do {
		system("CLS");
		printf("\t\t____________________________________________________\n");
		printf("\t\t|______________删除学生信息_________________________|\n");
		printf("\t\t|______________继续请按1，退出请按0_________________|\n");
		printf("\t\t请输入要删除的学生学号：");
		scanf("%s", stux);
		p = phead;
		for (m = phead->next; m != NULL; m = m->next) {
			if (!strcmp(m->item.id, stux)) {
				printf("\t\t已经查到改学生的信息\n");
				flag = 0;
				break;
			}
			else {
				flag = 1;
			}
		}
		if (flag == 1)
			printf("\t\t抱歉，没有查到该学生的信息\n");
		if (flag == 0) {
			if (!strcmp(phead->item.id, stux)) {
				phead = phead->next;
			}
			else {
				while (strcmp(p->item.id, stux) && p->next != NULL)
				{
					t = p;
					p = p->next;
				}
				if (!strcmp(p->item.id, stux))
				{
					t->next = p->next;
				}
			}
			printf("\t\t该学生信息已删除\n");
			printf("继续删除请按1，退出请按0\n");
			printf("请选择继续删除还是退出：");
			scanf("%s", xd);
			if (!strcmp(xd, "0")) {
				break;
			}
		}
	} while (!strcmp(xd, "1"));
	savefile(phead);
}
void chazhao()//查找菜单
{
	int flag = 1,tag = 1;
	char xcc[20],xc1[20];
	while (flag) {
		do {
			system("CLS");
			printf("\t\t-----------------------------\n");
			printf("\t\t------按学号查找请按1--------\n");
			printf("\t\t------按姓名查找请按2--------\n");
			printf("\t\t------继续请按1，退出请按0---\n");
			int x;
			printf("请输入你想要按什莫查找：");
			do {
				scanf("%s", xc1);
				/*while (getchar() != '\n')
					continue;*/
				if (!strcmp(xc1, "1")) {
					tag=chazhaoid();
				}
				else if (!strcmp(xc1, "2")) {
					tag=chazhaona();
					//break;
				}
				else if(!strcmp(xc1,"0")){
					flag = 0;
					break;
				}
				else {
					printf("请重新输入：");
				}
			} while (tag);
			printf("继续查找请按1，退出请按0!\n");
			printf("请选择继续还是退出：");
			scanf("%s", xcc);
		} while (!strcmp(xcc, "1"));
		flag = 0;
	}
}
int chazhaoid()//按学号查找
{
	
	List p, pph, yf;
	int flag = 1,tag = 1;
	pph = readfile();
	char id[20],xci[20];
		do {
			p = pph->next;
			printf("请输入你想要查找的学生学号:");
			scanf("%s", id);
			getchar();
			while (p != NULL) {
				if (!strcmp(p->item.id, id))
				{
					printf("\t\t已经查到改学生的信息\n");
					flag = 0;
					break;
				}
				p = p->next;
			}
			if (flag == 1) {
				printf("\t\t抱歉，没有查到该学生的信息\n");
			}
			if (flag == 0)
			{
				printf("\t\t该学生的信息如下\n");
				printf("\t\t学号：%s\n", p->item.id);
				printf("\t\t语文：%d\n", p->item.chinese);
				printf("\t\t数学：%d\n", p->item.math);
				printf("\t\t英语：%d\n", p->item.english);
				printf("\t\t姓名：%s\n", p->item.name);
			}
			printf("继续按学号查找请按1，退出请按0\n");
			printf("请选择继续按学号查找还是退出：");
			scanf("%s", xci);
		} while (!strcmp(xci, "1"));
		return 0;
}
int chazhaona()//按姓名查找
{
	List p, ph, yf;
	int flag = 0;
	char xcn[20];
	ph = readfile();
	p = ph;
	char  name[20];
	do{
		p = ph->next;
		printf("请输入你想要查找的学生姓名:");
		scanf("%s", name);
		while (p!= NULL) {
			if (!strcmp(p->item.name, name)) {
				flag = 1;
				yf = p;
				break;
			}
			p = p->next;
		}
		if (flag == 0) {
			printf("\t\t抱歉，没有查到该学生的信息\n");
			return 0;
		}
		if (flag == 1) {
			printf("已找到该学生，信息如下:\n");
			printf("学号   姓名    语文    数学     英语\n");
			printf("%s %s %d %d %d\n", yf->item.id, yf->item.name, yf->item.chinese, yf->item.math, yf->item.english);
		}
		printf("继续按姓名查找请按1，退出请按0\n");
		printf("请选择继续按姓名查找还是退出：");
		scanf("%s", xcn);
	} while (!strcmp(xcn, "1"));
	return 0;
}
List2 registers()//用户注册
{
	int wr = 1, tag = 1, i, flag = 1;
	List2 q2, qhead, user, head, q;
	FILE *fq;
	char xr[20];
	char password[20], count[20];
	qhead = (List2)malloc(LEN2);
	q2 = qhead;
	qhead->next = NULL;
	printf("\t\t|--------------------------|\n");
	printf("\t\t|      学生管理系统        |\n");
	printf("\t\t|--------------------------|\n");
	printf("\t\t|                          |\n");
	printf("\t\t|        输入1注册         |\n");
	printf("\t\t|        输入0退出         |\n");
	printf("\t\t|--------------------------|\n");
	printf("请输入想要注册还是退出：");
	do {
		scanf("%s", xr);
		while (getchar() != '\n')
			continue;
		if (strcmp(xr, "1") && strcmp(xr, "0")) {
			printf("输入错误，请重新输入: \n");
		}
		if (!strcmp(xr, "1") || !strcmp(xr, "0")) {
			break;
		}
	} while (1);
	if (!strcmp(xr, "1")) {
		do {
			system("CLS");
			printf("\t\t|--------------------------------------|\n");
			printf("\t\t|             学生管理系统             |\n");
			printf("\t\t|---------------用户注册---------------|\n");
			printf("\t\t|------继续注册请按1，退出按0----------|\n");
			user = (List2)malloc(LEN2);
			head = outputfile();
			q = head->next;
			printf("请输入你的账号：");
			do {
				scanf("%s", user->item.count);
				while (getchar() != '\n')
					continue;
				if (strlen(user->item.count) > 16) {
					printf("输入的长度过长,只能输入16位，请重新输入哦!\n");
					tag = 0;
				}
				for (i = 0; i < strlen(user->item.count); i++) {
					if (user->item.count[i]<'0' || user->item.count[i]>'9') {
						printf("账号只能输入数字哦,请重新输入：\n");
						tag = 0;
						break;
					}
				}
			} while (tag == 0);
			while (q != NULL) {
				if (!strcmp(q->item.count, user->item.count)) {
					wr = 0;
					break;
				}
				q = q->next;
			}
			if (wr == 0) {
				printf("添加的账号已存在,请重新输入：\n");
				
				flag = 0;
			}
		//} while (!flag);
		printf("请输入你的密码：");
		scanf("%s", user->item.password);
		q2->next = user;
		q2 = user;
		fq = fopen("userList.txt", "a+");
		fprintf(fq, "%s %s", user->item.count, user->item.password);
		printf("注册成功！\n");
		printf("继续输入请按1，退出请按0：\n");
		do {
			scanf("%s", xr);
			while (getchar() != '\n')
				continue;
			if (strcmp(xr, "1") && strcmp(xr, "0")) {
				printf("输入错误，请重新输入: ");
				//continue;
			}
			if (!strcmp(xr, "1") || !strcmp(xr, "0")) {
				break;
				}
			} while (1);
		} while (!strcmp(xr, "1"));
		q2->next = NULL;
	}
	else {
		return;
	}
	fclose(fq);
	return (qhead);		
}
void creataccount(List2 qhead)//将用户注册信息存入文件
{
	FILE *fq;
	List2  user, q;
	if (fq = fopen("users.txt", "w" == NULL)) {
		printf("写文件出错，按任意键退出");
		getch();
		exit(1);
	}
	for (q = qhead->next; q != NULL; q = q->next) {
		fprintf(fq,"%s %s", q->item.count, q->item.password);
	}
	printf("已成功创建！");
	getch();
	fclose(fq);
}
List2 outputfile()//从文件读取出用户信息
{
	List2 prev, p, head;
	head = (List2)malloc(LEN);
	p = head->next;
	prev = head;
	FILE * fq;
	if ((fq = fopen("userList.txt", "rt")) == NULL) {
		exit(0);
	}
	while (!feof(fq)) {
		p = (List2)malloc(LEN);
		p->next = NULL;
		prev->next = p;
		fscanf(fq,"%s %s",p->item.count,p->item.password);
		//printf("%s %s\n", p->item.count, p->item.password);
		prev = p;
		p = p->next;
	}
	fclose(fq);
	//printf("文件信息已成功读出\n");
	return(head);
}
void login1()//用户登陆
{
	List2 q, qhead, user;
	int flag = 0 , count = 0;
	char count1[20], password1[20];
	qhead=outputfile();
	while (1) {
		printf("请输入你的账号: ");
		scanf("%s", count1);
		for (q = qhead->next; q != NULL; q = q->next) {
			if (!strcmp(q->item.count, count1)) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			printf("请输入密码: ");
			secretword(password1);
			for (q = qhead->next; q != NULL; q = q->next) {
				if (!strcmp(q->item.password, password1)) {
					printf("登陆成功！\n");
					find();
					break;
				}
			}
			break;
		}
		else {
			if (count > 3) {
				return;
			}
			printf("账号不存在，请重新检查输入或注册!最多输入3次哦\n ");
			count++;
		}

	}
}
void managefile()//管理员信息文件
{
	Item2 manager = { .count = 863139668,
					 .password =" 13220075013qst "};
	FILE *ft = fopen("E:\\manager.txt", "w");
	fprintf(ft, "%s\n%s", manager.count, manager.password);
	fclose(ft);
}
int login2()//管理员登录
{
	int count = 0;
	char mcount[20], mpass[20];
	char mcount1[20], mpass1[20];
	FILE *ft = fopen("E:\\manager.txt", "r");
	fscanf(ft, "%s\n%s", mcount1, mpass1);
	while (1) {
		printf("请输入你的账号: ");
		scanf("%s", mcount);
		printf("请输入你的密码: ");
		secretword(mpass);
		if (!strcmp(mcount, mcount1) && !strcmp(mpass, mpass1)) {
			printf("登陆成功！");
			//menu();
			break;
		}
		else {
			count++;
			if (count > 3) {
				return 0;
			}
			printf("账号或密码错误，请重新输入,最多输入四次哦\n");
			
		}
		
	}
	return 1;
}
void secretword(char key[]) {
	unsigned char c;
	int i = 0;
	while ((c = getch()) != '\r') {
		if (i<20 && isprint(c)) {
			key[i] = c;
			i++;
			putchar('*');
		}
		else if (i>0 && c == '\b') {
			i--;
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
	}
	printf("\n");
	key[i] = '\0';
}
void insert()//插入菜单
{
	int flag = 1,in = 1;
	char xi[20];
	while (1) {
			system("CLS");
			printf("\t\t----------------------------\n");
			printf("\t\t----头插请按1，尾插请按2----\n");
			printf("\t\t----中间插按3，退出插入0----\n");
			printf("请输入你想要插入的位置：");
			scanf("%s", xi);
			if (!strcmp(xi, "1")) {
				inserthead();
				break;
			}
			else if (!strcmp(xi, "2")) {
				insertend();
				break;
			}
			else if (!strcmp(xi, "3")) {
				insertmiddle();
				break;
			}
			else if (!strcmp(xi, "0")) {
				break;
			}
			else {
				printf("请重新输入：");
			}
		}
}
List inserthead()//从头部插入
{
	int tag = 0, i, lala = 0, wf = 1;
	List pnew, head, p;
	head = readfile();
	pnew = (List)malloc(LEN);
	while(1){
		p = head->next;
		do {
		printf("请输入学号：");
		scanf("%s", pnew->item.id);
		while (strlen(pnew->item.id) != 8) {
			printf("亲,学号应该为8位非负整数，请重新输入哦: ");
			scanf("%s", pnew->item.id);
		}
		for (i = 0; i < 8; i++) {
			if (pnew->item.id[i] < '0' || pnew->item.id[i] > '9') {
				printf("同学,请输入八位非负整数: ");
				break;
			}
			else {
				tag = 1;
				break;
			}
		}
	} while (tag == 0);
	while (p != NULL) {
		if (!strcmp(p->item.id, pnew->item.id)){
			wf = 0;
			break;
		}
		p = p->next;
	}
		if (wf == 0) {
		printf("插入的学生已存在,请重新输入：\n");
		}
		else {
			break;
		}
	}
	printf("请输入姓名：");
	do {
		scanf("%s", pnew->item.name);
		for (i = 0; i < strlen(pnew->item.name); i++) {
			if (pnew->item.name[i] >= '0' && pnew->item.name[i] <= '9') {
				//改成 &&
				printf("请不要输入数字！请重新输入：");
				break;
			}
			else {
				lala = 1;
				break;
			}
		}
	} while (lala == 0);

	do {
		printf("请输入语文成绩: ");  scanf("%d", &pnew->item.chinese);
		while (getchar() != '\n')
			continue;
		printf("请输入数学成绩: ");  scanf("%d", &pnew->item.math);
		while (getchar() != '\n')
			continue;
		printf("请输入英语成绩: ");  scanf("%d", &pnew->item.english);
		while (getchar() != '\n')
			continue;
		if (pnew->item.chinese < 0 || pnew->item.chinese>100 || pnew->item.math < 0 || pnew->item.math>100 || pnew->item.english < 0 || pnew->item.english>100)
		{
			printf("\t\t______________________\n");
			printf("\t\t_成绩请输入0-100之间__\n");
			printf("\t\t______________________\n");
			printf("\t\t重新输入成绩\n");
		}
		else {
			break;
		}
	} while (1);
	pnew->next = head;
	head = pnew;
	return head;
}
List insertend()//从尾部插入
{
	int tag = 0, i, lala = 0, wf = 1;
	List p , head, pnew;
	head = readfile();
	p = head->next;
	while (p&&p->next != NULL) {
		p = p->next;
	}
	pnew = (List)malloc(LEN);
	while (1) {
		p = head->next;
		do {
			printf("请输入学号：");
			scanf("%s", pnew->item.id);
			while (strlen(pnew->item.id) != 8) {
				printf("亲,学号应该为8位非负整数，请重新输入哦: ");
				scanf("%s", pnew->item.id);
			}
			for (i = 0; i < 8; i++) {
				if (pnew->item.id[i] < '0' || pnew->item.id[i] > '9') {
					printf("同学,请输入八位非负整数: ");
					break;
				}
				else {
					tag = 1;
					break;
				}
			}
		} while (tag == 0);
		while (p != NULL) {
			if (!strcmp(p->item.id, pnew->item.id)) {
				wf = 0;
				break;
			}
			p = p->next;
		}
		if (wf == 0) {
			printf("插入的学生已存在,请重新输入：\n");
		}
		else {
			break;
		}
	}
		printf("请输入姓名：");
		do {
			scanf("%s", pnew->item.name);
			for (i = 0; i < strlen(pnew->item.name); i++) {
				if (pnew->item.name[i] >= '0' && pnew->item.name[i] <= '9') {
					//改成 &&
					printf("请不要输入数字！请重新输入：");
					break;
				}
				else {
					lala = 1;
					break;
				}
			}
		} while (lala == 0);

		do {
			printf("请输入语文成绩: ");  scanf("%d", &pnew->item.chinese);
			while (getchar() != '\n')
				continue;
			printf("请输入数学成绩: ");  scanf("%d", &pnew->item.math);
			while (getchar() != '\n')
				continue;
			printf("请输入英语成绩: ");  scanf("%d", &pnew->item.english);
			while (getchar() != '\n')
				continue;
			if (pnew->item.chinese < 0 || pnew->item.chinese>100 || pnew->item.math < 0 || pnew->item.math>100 || pnew->item.english < 0 || pnew->item.english>100)
			{
				printf("\t\t______________________\n");
				printf("\t\t_成绩请输入0-100之间__\n");
				printf("\t\t______________________\n");
				printf("\t\t重新输入成绩\n");
			}
			else {
				break;
			}
		} while (1);
	pnew->next = NULL;
	return head;
}
List insertmiddle()//从中间插入
{
	int i, tag = 0, lala = 0, wf = 1;
	char ww[20];
	List p , head, pnew;
	head = readfile();
	p = head->next;
	while(1){
	printf("\t\t请输入你想要插入哪个学号后: ");
	scanf("%s", ww);
	while (p&&!strcmp(p->item.id, ww)) {
		p = p->next;
	}
	pnew = (List)malloc(LEN);
	do {
		printf("请输入学号：");
		scanf("%s", pnew->item.id);
		while (strlen(pnew->item.id) != 8) {
			printf("亲,学号应该为8位非负整数，请重新输入哦: ");
			scanf("%s", pnew->item.id);
		}
		for (i = 0; i < 8; i++) {
			if (pnew->item.id[i] < '0' || pnew->item.id[i] > '9') {
				printf("同学,请输入八位非负整数: ");
				break;
			}
			else {
				tag = 1;
				break;
			}
		}
	} while (tag == 0);
	while (p != NULL) {
		if (!strcmp(p->item.id, pnew->item.id)) {
			wf = 0;
			break;
		}
		p = p->next;
	}
	if (wf == 0) {
		printf("插入的学生已存在,请重新输入：\n");
	}
	else {
		break;
	}
}
	printf("请输入姓名：");
	do {
		scanf("%s", pnew->item.name);
		for (i = 0; i < strlen(pnew->item.name); i++) {
			if (pnew->item.name[i] >= '0' && pnew->item.name[i] <= '9') {
				//改成 &&
				printf("请不要输入数字！请重新输入：");
				break;
			}
			else {
				lala = 1;
				break;
			}
		}
	} while (lala == 0);

	do {
		printf("请输入语文成绩: ");  scanf("%d", &pnew->item.chinese);
		while (getchar() != '\n')
			continue;
		printf("请输入数学成绩: ");  scanf("%d", &pnew->item.math);
		while (getchar() != '\n')
			continue;
		printf("请输入英语成绩: ");  scanf("%d", &pnew->item.english);
		while (getchar() != '\n')
			continue;
		if (pnew->item.chinese < 0 || pnew->item.chinese>100 || pnew->item.math < 0 || pnew->item.math>100 || pnew->item.english < 0 || pnew->item.english>100)
		{
			printf("\t\t______________________\n");
			printf("\t\t_成绩请输入0-100之间__\n");
			printf("\t\t______________________\n");
			printf("\t\t重新输入成绩\n");
		}
		else {
			break;
		}
	} while (1);
	pnew->next = p->next;
	p->next = pnew;
	return head;
}
void sort()//排序菜单
{
	int flag = 1;
	system("CLS");
	char xs[20];
	char xss[20];
	while (flag) {
		do {
			system("CLS");
		printf("\t\t|-----------------------------------------|\n");
		printf("\t\t|-----------按要求选择排序----------------|\n");
		printf("\t\t|----1.按语文成绩排序  2.按数学成绩排序---|\n");
		printf("\t\t|--------------3.按英语成绩排序  ---------|\n");
		printf("\t\t|---------输入1选择，输入0退出------------|\n");
			printf("请输入你想要按什莫排序：");
			scanf("%s", xs);
			if (!strcmp(xs, "1")) {
				system("CLS");
				chinesest();
				break;
			}
			else if (!strcmp(xs, "2")) {
				system("CLS");
				mathst();
				break;
			}
			else if (!strcmp(xs, "3")) {
				system("CLS");
				englishst();
				break;
			}
			/*else if (!strcmp(xs, "4")) {
				system("CLS");
				zongfen();
			}*/
			else {
				printf("输入错误，请重新输入选择:\n ");
			}
			printf("继续输入请按1，退出请按0:");
			scanf("%s", xss);

			if (!strcmp(xss, "0")) {
				flag = 0;
			}
		} while (!strcmp(xss, "1"));
	}
}
List sortfile()//将文件中的信息读入结构体数组
{
	int i;
	FILE *fp;
	Item stu[100];
	if(fp=fopen("aa.txt","rb")==NULL){
		printf("can't open file!");
		return;
	}
	else {
		for (i = 0; i < 100; i++) {
			fread(&stu[i], sizeof(Item), 1, fp);
		}
	}
	fclose(fp);
}
void chinesest()//按语文成绩排序
{
	char ys[20];
	List p, pre, tail, t, head;
	tail = NULL;
	head = readfile();
	pre = head;
	while ((head->next->next )!= tail) {
		p = head->next;
		pre = head;
		while (p->next != tail) {
			if (p->next->item.chinese < p->item.chinese) {
				pre->next = p->next;
				p->next = p->next->next;
				pre->next->next = p;
				p = pre->next;
			}
			p = p->next;
			pre = pre->next;
		}
		tail = p;
	}
	do {
		printf("\t\t           语文排序             \n");
		printf("\t\t%10s%10s%10s%10s%10s\n", "学号", "姓名", "语文", "数学", "英语");
		printf("\t\t--------------------------------------------------------------\n");
		for (t = head->next; t != NULL; t = t->next) {
			printf("\t\t%10s%10s%10d%10d%10d\n", t->item.id, t->item.name, t->item.chinese, t->item.math, t->item.english);
		}
		printf("请输入你是否想要退出：\n");
		printf("退出请按0，继续查看请按1：");
		scanf("%s", ys);
		if (!strcmp(ys, "0")) {
			break;
		}
	} while (!strcmp(ys, "1"));
	
}
void mathst()//按数学成绩排序
{
	char ys[20];
	List p, pre, tail,t;
	tail = NULL;
	phead = readfile(phead);
	pre = phead;
	while (phead->next != tail) {
		p = phead->next;
		pre = phead;
		while (p->next != tail) {
			if (p->next->item.math < p->item.math) {
				pre->next = p->next;
				p->next = p->next->next;
				pre->next->next = p;
				p = pre->next;
			}
			p = p->next;
			pre = pre->next;
		}
		tail = p;
	}
	do {
		printf("\t\t            数学排序             \n");
		printf("\t\t%10s%10s%10s%10s%10s\n", "学号", "姓名", "语文", "数学", "英语");
		printf("\t\t--------------------------------------------------------------\n");
		for (t = phead->next; t != NULL; t = t->next) {
			printf("\t\t%10s%10s%10d%10d%10d\n", t->item.id, t->item.name, t->item.chinese, t->item.math, t->item.english);
		}
		printf("请输入你是否想要退出：\n");
		printf("退出请按0，继续查看请按1：");
		scanf("%s", ys);
		if (!strcmp(ys, "0")) {
			break;
		}
	} while (!strcmp(ys, "1"));
}
void englishst()//按英语成绩排序
{
	char ys[20];
	List p, pre, tail,t;
	tail = NULL;
	phead = readfile(phead);
	pre = phead;
	while (phead->next != tail) {
		p = phead->next;
		pre = phead;
		while (p->next != tail) {
			if (p->next->item.english < p->item.english) {
				pre->next = p->next;
				p->next = p->next->next;
				pre->next->next = p;
				p = pre->next;
			}
			p = p->next;
			pre = pre->next;
		}
		tail = p;
	}
	do {
		printf("\t\t            英语排序             \n");
		printf("\t\t%10s%10s%10s%10s%10s\n", "学号", "姓名", "语文", "数学", "英语");
		printf("\t\t--------------------------------------------------------------\n");
		for (t = phead->next; t != NULL; t = t->next) {
			printf("\t\t%10s%10s%10d%10d%10d\n", t->item.id, t->item.name, t->item.chinese, t->item.math, t->item.english);
		}
		printf("请输入你是否想要退出：\n");
		printf("退出请按0，继续查看请按1：");
		scanf("%s", ys);
		if (!strcmp(ys, "0")) {
			break;
		}
	} while (!strcmp(ys, "1"));
	
}
int cmp(const void *a, const void *b)//qsort函数调用
{
	Item *aa = (Item *)a;
	Item *bb = (Item *)b;
	return(((aa->zongfen)>(bb->zongfen))?1:-1);  //升序 
									//return(*(int *)b-*(int *)a); //降序 
}
void zongfen()//按总成绩排序
{
	int i;
	Item stu[100];
	sortfile();
	for (i = 0; i < 100 ; i++) {
		stu[i].zongfen = stu[i].chinese + stu[i].math + stu[i].english;
	}
	qsort(stu, 100, sizeof(stu[0]), cmp);
	for (i = 0; i < 100; i++) {
		printf("%s   %s%5d%5d%5d\n", stu[i].name, stu[i].id, stu[i].zongfen);
	}
}
void tongji()//统计学生信息
{
	List p, q, phead, t, m;
	int flag = 0, chi = 0, mat = 0, eng = 0, timp = 0;
	int n = 0;
	char xt[20];
	phead = readfile();
	p = phead->next;
		for (t = p->next; t != NULL; t = t->next) {
			n++;
			if (t->item.chinese >= 60) {
				chi++;
			}
			if (t->item.math >= 60) {
				mat++;
			}
			if (t->item.english >= 60) {
				eng++;
			}
		}
	do {
		printf("\t\t____________________________________________________\n");
		printf("\t\t|______________学生成绩分析_________________________|\n");
		printf("\t\t|___________________________________________________|\n");
		printf("\t\t一共录入了%d个学生成绩\n", n);
		printf("\t\t语文及格人数为%d\n", chi);
		printf("\t\t数学及格人数为%d\n", mat);
		printf("\t\t英语及格人数为%d\n", eng);
		printf("\t\t分析完毕\n");
		printf("退出请按0：");
		scanf("%s", xt);
	}while (!strcmp(xt, "1"));
}

