#include"list.h"
void printmenu()
{
	system("CLS");
	printf("\t\t|---------------------------------------|\n");
	printf("\t\t|--------��ӭ����ѧ������ϵͳ-----------|\n");
	printf("\t\t|----------- ����Ա��¼�밴1------------|\n");
	printf("\t\t|------------ѧ��ע���밴2--------------|\n");
	printf("\t\t|------------ѧ����¼�밴3--------------|\n");
	printf("\t\t|------------�˳�ϵͳ�밴0--------------|\n");
}
List luru()//�����Ϣ
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
	printf("\t\t|      ѧ������ϵͳ        |\n");
	printf("\t\t|--------------------------|\n");
	printf("\t\t|                          |\n");
	printf("\t\t|        ����1���         |\n");
	printf("\t\t|        ����0�˳�         |\n");
	printf("\t\t|--------------------------|\n");
		printf("��������Ҫ��ӻ����˳���");
		do {
			scanf("%s", xx);
			while (getchar() != '\n')
				continue;
			if (strcmp(xx, "1") && strcmp(xx, "0")) {
				printf("�����������������: \n");
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
				printf("\t\t|      ѧ������ϵͳ        |\n");
				printf("\t\t|--------------------------|\n");
				printf("\t\t|                          |\n");
				printf("\t\t|        ����1���         |\n");
				printf("\t\t|        ����0�˳�         |\n");
				printf("\t\t|--------------------------|\n");
				printf("������ѧ�ţ�");
				
					do {
						scanf("%s", stu->item.id);
						while (strlen(stu->item.id) != 8) {
							printf("��,ѧ��Ӧ��Ϊ8λ�Ǹ�����������������Ŷ: ");
							scanf("%s", stu->item.id);
						}
						for (i = 0; i < 8; i++) {
							if (stu->item.id[i] < '0' || stu->item.id[i] > '9') {
								printf("ͬѧ,�������λ�Ǹ�����: ");
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
						printf("��ӵ�ѧ���Ѵ���,���������룺\n");
						do {
							scanf("%s", stu->item.id);
							while (strlen(stu->item.id) != 8) {
								printf("��,ѧ��Ӧ��Ϊ8λ�Ǹ�����������������Ŷ: ");
								scanf("%s", stu->item.id);
							}
							for (i = 0; i < 8; i++) {
								if (stu->item.id[i] < '0' || stu->item.id[i] > '9') {
									printf("ͬѧ,�������λ�Ǹ�����: ");
									break;
								}
								else {
									tag = 1;
									break;
								}
							}
						} while (tag == 0);
					}
				printf("������������");
				do {
					scanf("%s", stu->item.name);
					for (i = 0; i < strlen(stu->item.name); i++) {
						if (stu->item.name[i] >= '0' && stu->item.name[i] <= '9') {
							printf("�벻Ҫ�������֣����������룺");
							break;
						}
						else {
							lala = 1;
							break;
						}
					}
				} while (lala == 0);

				do {
					printf("���������ĳɼ�: ");  scanf("%d", &stu->item.chinese);
					while (getchar() != '\n')
						continue;
					printf("��������ѧ�ɼ�: ");  scanf("%d", &stu->item.math);
					while (getchar() != '\n')
						continue;
					printf("������Ӣ��ɼ�: ");  scanf("%d", &stu->item.english);
					while (getchar() != '\n')
						continue;
					if (stu->item.chinese < 0 || stu->item.chinese>100 || stu->item.math < 0 || stu->item.math>100 || stu->item.english < 0 || stu->item.english>100)
					{
						printf("\t\t______________________\n");
						printf("\t\t_�ɼ�������0-100֮��__\n");
						printf("\t\t______________________\n");
						printf("\t\t��������ɼ�\n");
					}
					else {
						break;
					}
				} while (1);
				p->next = stu;
				p = stu;
				fp = fopen("D:\\aa.txt", "a+");
				fprintf(fp, "%s %d %d %d %s\n", stu->item.id, stu->item.chinese, stu->item.math, stu->item.english, stu->item.name);

				printf("���������밴1���˳��밴0��\n");
				do {
					scanf("%s", xx);
					while (getchar() != '\n')
						continue;
					if (strcmp(xx, "1") && strcmp(xx, "0")) {
						printf("�����������������: ");
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
void savefile(List phead)//����Ϣ�����ļ�
{
	List stu;
	FILE *fp;
	if ((fp = fopen("aa.txt", "w" ))== NULL) {
		printf("д�ļ�������������˳�");
		//getchar();
		exit(0);
	}
		for (stu = phead->next; stu != NULL; stu = stu->next) {
			fprintf(fp, "%s %d %d %d %s\n", stu->item.id, stu->item.chinese, stu->item.math, stu->item.english, stu->item.name);
		}
	fclose(fp);
	//printf("�ļ��ѳɹ����棬����������أ�");
	//getchar();
}
List readfile()//����Ϣ���ļ��ж���������
{
	List prev, p, phead;
	phead = (List)malloc(LEN);
	//p = phead;
	prev = phead;
	FILE * fp;
	if ((fp = fopen("D:\\aa.txt", "r") ) == NULL) {
		printf("��ʧ�ܣ�");
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
	//printf("�ļ���Ϣ�ѳɹ�����������������أ�");
	//getchar();
	return phead;
}
void find()//����ѧ����Ϣ
{
	List  m, phead;
	phead = readfile();
	char  timp[20],xf[20];
	int flag = 0;
	do{
		printf("������Ҫ���ҵ�ѧ��ѧ��: ");
		scanf("%s", timp);
		for (m = phead->next; m != NULL; m = m->next)
		{
			if (!strcmp(m->item.id, timp))
			{
				printf("\t\t�Ѿ��鵽��ѧ������Ϣ\n");
				flag = 0;
				break;
			}
			else
				flag = 1;
		}
		if (flag == 1)
			printf("\t\t��Ǹ��û�в鵽��ѧ������Ϣ\n");
		if (flag == 0)
		{
			printf("\t\t��ѧ������Ϣ����\n");
			printf("\t\tѧ�ţ�%s\n", m->item.id);
			printf("\t\t���ģ�%d\n", m->item.chinese);
			printf("\t\t��ѧ��%d\n", m->item.math);
			printf("\t\tӢ�%d\n", m->item.english);
			printf("\t\t������%s\n", m->item.name);
		}
		printf("���������밴1���˳��밴0\n");
		printf("��ѡ��������һ����˳���");
		scanf("%s", xf);
	} while (!strcmp(xf, "1"));
	
}
void repair()//�޸�ѧ����Ϣ
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
			printf("������Ҫ���ҵ�ѧ��ѧ��: ");
			scanf("%s", timp);
			for (m = phead->next; m != NULL; m = m->next)
			{
				if (!strcmp(m->item.id, timp))
				{
					printf("\t\t�Ѿ��鵽��ѧ������Ϣ\n");
					flag = 0;
					break;
				}
				else
					flag = 1;
			}
			if (flag == 1)
				printf("\t\t��Ǹ��û�в鵽��ѧ������Ϣ\n");
			if (flag == 0)
			{
				printf("\t\t��ѧ������Ϣ����\n");
				printf("\t\tѧ�ţ�%s\n", m->item.id);
				printf("\t\t���ģ�%d\n", m->item.chinese);
				printf("\t\t��ѧ��%d\n", m->item.math);
				printf("\t\tӢ�%d\n", m->item.english);
				printf("\t\t������%s\n", m->item.name);
			}
		do {
			printf("��������ȷ��ѧ�ţ�");
			scanf("%s", m->item.id);
			while (strlen(m->item.id) != 8) {
				printf("��,ѧ��Ӧ��Ϊ8λ�Ǹ�����������������Ŷ: ");
				scanf("%s", m->item.id);
			}
			for (i = 0; i < 8; i++) {
				if (m->item.id[i] < '0' && m->item.id[i] > '9') {
					printf("ͬѧ,�������λ�Ǹ�����: ");
					break;
				}
				else {
					tag = 1;
					//break;
				}
			}
		} while (tag == 0);
		do {
			printf("������������");
			scanf("%s", m->item.name);
			for (i = 0; i < strlen(m->item.name); i++) {
				if (m->item.name[i] >= '0' && m->item.name[i] <= '9') {
					printf("�벻Ҫ�������֣����������룺");
					break;
				}
				else {
					lala = 1;
					break;
				}
			}
		} while (lala == 0);

		do {
			printf("���������ĳɼ�: ");  scanf("%d", &m->item.chinese);
			printf("��������ѧ�ɼ�: ");  scanf("%d", &m->item.math);
			printf("������Ӣ��ɼ�: ");  scanf("%d", &m->item.english);
			if (m->item.chinese < 0 || m->item.chinese>100 || m->item.math < 0 || m->item.math>100 || m->item.english < 0 || m->item.english>100)
			{
				printf("\t\t______________________\n");
				printf("\t\t_�ɼ�������0-100֮��__\n");
				printf("\t\t______________________\n");
				printf("\t\t��������ɼ�\n");
			}
			else {
				break;
			}
		} while (1);
		printf("\t\t��ѧ����Ϣ���޸�\n");
		printf("�����޸��밴1���˳��밴0\n");
		printf("��ѡ������޸Ļ����˳���");
		scanf("%s", xrr);
		if (!strcmp(xrr, "0")) {
			break;
		}
	} while (!strcmp(xrr,"1"));
	savefile(phead);
}
void delete()//ɾ��ѧ����Ϣ
{
	List phead, stu1,p,m,t;
	phead = readfile();
	stu1 = (List)malloc(LEN);
	char stux[20],xd[20];
	int flag = 0;
	do {
		system("CLS");
		printf("\t\t____________________________________________________\n");
		printf("\t\t|______________ɾ��ѧ����Ϣ_________________________|\n");
		printf("\t\t|______________�����밴1���˳��밴0_________________|\n");
		printf("\t\t������Ҫɾ����ѧ��ѧ�ţ�");
		scanf("%s", stux);
		p = phead;
		for (m = phead->next; m != NULL; m = m->next) {
			if (!strcmp(m->item.id, stux)) {
				printf("\t\t�Ѿ��鵽��ѧ������Ϣ\n");
				flag = 0;
				break;
			}
			else {
				flag = 1;
			}
		}
		if (flag == 1)
			printf("\t\t��Ǹ��û�в鵽��ѧ������Ϣ\n");
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
			printf("\t\t��ѧ����Ϣ��ɾ��\n");
			printf("����ɾ���밴1���˳��밴0\n");
			printf("��ѡ�����ɾ�������˳���");
			scanf("%s", xd);
			if (!strcmp(xd, "0")) {
				break;
			}
		}
	} while (!strcmp(xd, "1"));
	savefile(phead);
}
void chazhao()//���Ҳ˵�
{
	int flag = 1,tag = 1;
	char xcc[20],xc1[20];
	while (flag) {
		do {
			system("CLS");
			printf("\t\t-----------------------------\n");
			printf("\t\t------��ѧ�Ų����밴1--------\n");
			printf("\t\t------�����������밴2--------\n");
			printf("\t\t------�����밴1���˳��밴0---\n");
			int x;
			printf("����������Ҫ��ʲĪ���ң�");
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
					printf("���������룺");
				}
			} while (tag);
			printf("���������밴1���˳��밴0!\n");
			printf("��ѡ����������˳���");
			scanf("%s", xcc);
		} while (!strcmp(xcc, "1"));
		flag = 0;
	}
}
int chazhaoid()//��ѧ�Ų���
{
	
	List p, pph, yf;
	int flag = 1,tag = 1;
	pph = readfile();
	char id[20],xci[20];
		do {
			p = pph->next;
			printf("����������Ҫ���ҵ�ѧ��ѧ��:");
			scanf("%s", id);
			getchar();
			while (p != NULL) {
				if (!strcmp(p->item.id, id))
				{
					printf("\t\t�Ѿ��鵽��ѧ������Ϣ\n");
					flag = 0;
					break;
				}
				p = p->next;
			}
			if (flag == 1) {
				printf("\t\t��Ǹ��û�в鵽��ѧ������Ϣ\n");
			}
			if (flag == 0)
			{
				printf("\t\t��ѧ������Ϣ����\n");
				printf("\t\tѧ�ţ�%s\n", p->item.id);
				printf("\t\t���ģ�%d\n", p->item.chinese);
				printf("\t\t��ѧ��%d\n", p->item.math);
				printf("\t\tӢ�%d\n", p->item.english);
				printf("\t\t������%s\n", p->item.name);
			}
			printf("������ѧ�Ų����밴1���˳��밴0\n");
			printf("��ѡ�������ѧ�Ų��һ����˳���");
			scanf("%s", xci);
		} while (!strcmp(xci, "1"));
		return 0;
}
int chazhaona()//����������
{
	List p, ph, yf;
	int flag = 0;
	char xcn[20];
	ph = readfile();
	p = ph;
	char  name[20];
	do{
		p = ph->next;
		printf("����������Ҫ���ҵ�ѧ������:");
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
			printf("\t\t��Ǹ��û�в鵽��ѧ������Ϣ\n");
			return 0;
		}
		if (flag == 1) {
			printf("���ҵ���ѧ������Ϣ����:\n");
			printf("ѧ��   ����    ����    ��ѧ     Ӣ��\n");
			printf("%s %s %d %d %d\n", yf->item.id, yf->item.name, yf->item.chinese, yf->item.math, yf->item.english);
		}
		printf("���������������밴1���˳��밴0\n");
		printf("��ѡ��������������һ����˳���");
		scanf("%s", xcn);
	} while (!strcmp(xcn, "1"));
	return 0;
}
List2 registers()//�û�ע��
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
	printf("\t\t|      ѧ������ϵͳ        |\n");
	printf("\t\t|--------------------------|\n");
	printf("\t\t|                          |\n");
	printf("\t\t|        ����1ע��         |\n");
	printf("\t\t|        ����0�˳�         |\n");
	printf("\t\t|--------------------------|\n");
	printf("��������Ҫע�ỹ���˳���");
	do {
		scanf("%s", xr);
		while (getchar() != '\n')
			continue;
		if (strcmp(xr, "1") && strcmp(xr, "0")) {
			printf("�����������������: \n");
		}
		if (!strcmp(xr, "1") || !strcmp(xr, "0")) {
			break;
		}
	} while (1);
	if (!strcmp(xr, "1")) {
		do {
			system("CLS");
			printf("\t\t|--------------------------------------|\n");
			printf("\t\t|             ѧ������ϵͳ             |\n");
			printf("\t\t|---------------�û�ע��---------------|\n");
			printf("\t\t|------����ע���밴1���˳���0----------|\n");
			user = (List2)malloc(LEN2);
			head = outputfile();
			q = head->next;
			printf("����������˺ţ�");
			do {
				scanf("%s", user->item.count);
				while (getchar() != '\n')
					continue;
				if (strlen(user->item.count) > 16) {
					printf("����ĳ��ȹ���,ֻ������16λ������������Ŷ!\n");
					tag = 0;
				}
				for (i = 0; i < strlen(user->item.count); i++) {
					if (user->item.count[i]<'0' || user->item.count[i]>'9') {
						printf("�˺�ֻ����������Ŷ,���������룺\n");
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
				printf("��ӵ��˺��Ѵ���,���������룺\n");
				
				flag = 0;
			}
		//} while (!flag);
		printf("������������룺");
		scanf("%s", user->item.password);
		q2->next = user;
		q2 = user;
		fq = fopen("userList.txt", "a+");
		fprintf(fq, "%s %s", user->item.count, user->item.password);
		printf("ע��ɹ���\n");
		printf("���������밴1���˳��밴0��\n");
		do {
			scanf("%s", xr);
			while (getchar() != '\n')
				continue;
			if (strcmp(xr, "1") && strcmp(xr, "0")) {
				printf("�����������������: ");
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
void creataccount(List2 qhead)//���û�ע����Ϣ�����ļ�
{
	FILE *fq;
	List2  user, q;
	if (fq = fopen("users.txt", "w" == NULL)) {
		printf("д�ļ�������������˳�");
		getch();
		exit(1);
	}
	for (q = qhead->next; q != NULL; q = q->next) {
		fprintf(fq,"%s %s", q->item.count, q->item.password);
	}
	printf("�ѳɹ�������");
	getch();
	fclose(fq);
}
List2 outputfile()//���ļ���ȡ���û���Ϣ
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
	//printf("�ļ���Ϣ�ѳɹ�����\n");
	return(head);
}
void login1()//�û���½
{
	List2 q, qhead, user;
	int flag = 0 , count = 0;
	char count1[20], password1[20];
	qhead=outputfile();
	while (1) {
		printf("����������˺�: ");
		scanf("%s", count1);
		for (q = qhead->next; q != NULL; q = q->next) {
			if (!strcmp(q->item.count, count1)) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			printf("����������: ");
			secretword(password1);
			for (q = qhead->next; q != NULL; q = q->next) {
				if (!strcmp(q->item.password, password1)) {
					printf("��½�ɹ���\n");
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
			printf("�˺Ų����ڣ������¼�������ע��!�������3��Ŷ\n ");
			count++;
		}

	}
}
void managefile()//����Ա��Ϣ�ļ�
{
	Item2 manager = { .count = 863139668,
					 .password =" 13220075013qst "};
	FILE *ft = fopen("E:\\manager.txt", "w");
	fprintf(ft, "%s\n%s", manager.count, manager.password);
	fclose(ft);
}
int login2()//����Ա��¼
{
	int count = 0;
	char mcount[20], mpass[20];
	char mcount1[20], mpass1[20];
	FILE *ft = fopen("E:\\manager.txt", "r");
	fscanf(ft, "%s\n%s", mcount1, mpass1);
	while (1) {
		printf("����������˺�: ");
		scanf("%s", mcount);
		printf("�������������: ");
		secretword(mpass);
		if (!strcmp(mcount, mcount1) && !strcmp(mpass, mpass1)) {
			printf("��½�ɹ���");
			//menu();
			break;
		}
		else {
			count++;
			if (count > 3) {
				return 0;
			}
			printf("�˺Ż������������������,��������Ĵ�Ŷ\n");
			
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
void insert()//����˵�
{
	int flag = 1,in = 1;
	char xi[20];
	while (1) {
			system("CLS");
			printf("\t\t----------------------------\n");
			printf("\t\t----ͷ���밴1��β���밴2----\n");
			printf("\t\t----�м�尴3���˳�����0----\n");
			printf("����������Ҫ�����λ�ã�");
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
				printf("���������룺");
			}
		}
}
List inserthead()//��ͷ������
{
	int tag = 0, i, lala = 0, wf = 1;
	List pnew, head, p;
	head = readfile();
	pnew = (List)malloc(LEN);
	while(1){
		p = head->next;
		do {
		printf("������ѧ�ţ�");
		scanf("%s", pnew->item.id);
		while (strlen(pnew->item.id) != 8) {
			printf("��,ѧ��Ӧ��Ϊ8λ�Ǹ�����������������Ŷ: ");
			scanf("%s", pnew->item.id);
		}
		for (i = 0; i < 8; i++) {
			if (pnew->item.id[i] < '0' || pnew->item.id[i] > '9') {
				printf("ͬѧ,�������λ�Ǹ�����: ");
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
		printf("�����ѧ���Ѵ���,���������룺\n");
		}
		else {
			break;
		}
	}
	printf("������������");
	do {
		scanf("%s", pnew->item.name);
		for (i = 0; i < strlen(pnew->item.name); i++) {
			if (pnew->item.name[i] >= '0' && pnew->item.name[i] <= '9') {
				//�ĳ� &&
				printf("�벻Ҫ�������֣����������룺");
				break;
			}
			else {
				lala = 1;
				break;
			}
		}
	} while (lala == 0);

	do {
		printf("���������ĳɼ�: ");  scanf("%d", &pnew->item.chinese);
		while (getchar() != '\n')
			continue;
		printf("��������ѧ�ɼ�: ");  scanf("%d", &pnew->item.math);
		while (getchar() != '\n')
			continue;
		printf("������Ӣ��ɼ�: ");  scanf("%d", &pnew->item.english);
		while (getchar() != '\n')
			continue;
		if (pnew->item.chinese < 0 || pnew->item.chinese>100 || pnew->item.math < 0 || pnew->item.math>100 || pnew->item.english < 0 || pnew->item.english>100)
		{
			printf("\t\t______________________\n");
			printf("\t\t_�ɼ�������0-100֮��__\n");
			printf("\t\t______________________\n");
			printf("\t\t��������ɼ�\n");
		}
		else {
			break;
		}
	} while (1);
	pnew->next = head;
	head = pnew;
	return head;
}
List insertend()//��β������
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
			printf("������ѧ�ţ�");
			scanf("%s", pnew->item.id);
			while (strlen(pnew->item.id) != 8) {
				printf("��,ѧ��Ӧ��Ϊ8λ�Ǹ�����������������Ŷ: ");
				scanf("%s", pnew->item.id);
			}
			for (i = 0; i < 8; i++) {
				if (pnew->item.id[i] < '0' || pnew->item.id[i] > '9') {
					printf("ͬѧ,�������λ�Ǹ�����: ");
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
			printf("�����ѧ���Ѵ���,���������룺\n");
		}
		else {
			break;
		}
	}
		printf("������������");
		do {
			scanf("%s", pnew->item.name);
			for (i = 0; i < strlen(pnew->item.name); i++) {
				if (pnew->item.name[i] >= '0' && pnew->item.name[i] <= '9') {
					//�ĳ� &&
					printf("�벻Ҫ�������֣����������룺");
					break;
				}
				else {
					lala = 1;
					break;
				}
			}
		} while (lala == 0);

		do {
			printf("���������ĳɼ�: ");  scanf("%d", &pnew->item.chinese);
			while (getchar() != '\n')
				continue;
			printf("��������ѧ�ɼ�: ");  scanf("%d", &pnew->item.math);
			while (getchar() != '\n')
				continue;
			printf("������Ӣ��ɼ�: ");  scanf("%d", &pnew->item.english);
			while (getchar() != '\n')
				continue;
			if (pnew->item.chinese < 0 || pnew->item.chinese>100 || pnew->item.math < 0 || pnew->item.math>100 || pnew->item.english < 0 || pnew->item.english>100)
			{
				printf("\t\t______________________\n");
				printf("\t\t_�ɼ�������0-100֮��__\n");
				printf("\t\t______________________\n");
				printf("\t\t��������ɼ�\n");
			}
			else {
				break;
			}
		} while (1);
	pnew->next = NULL;
	return head;
}
List insertmiddle()//���м����
{
	int i, tag = 0, lala = 0, wf = 1;
	char ww[20];
	List p , head, pnew;
	head = readfile();
	p = head->next;
	while(1){
	printf("\t\t����������Ҫ�����ĸ�ѧ�ź�: ");
	scanf("%s", ww);
	while (p&&!strcmp(p->item.id, ww)) {
		p = p->next;
	}
	pnew = (List)malloc(LEN);
	do {
		printf("������ѧ�ţ�");
		scanf("%s", pnew->item.id);
		while (strlen(pnew->item.id) != 8) {
			printf("��,ѧ��Ӧ��Ϊ8λ�Ǹ�����������������Ŷ: ");
			scanf("%s", pnew->item.id);
		}
		for (i = 0; i < 8; i++) {
			if (pnew->item.id[i] < '0' || pnew->item.id[i] > '9') {
				printf("ͬѧ,�������λ�Ǹ�����: ");
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
		printf("�����ѧ���Ѵ���,���������룺\n");
	}
	else {
		break;
	}
}
	printf("������������");
	do {
		scanf("%s", pnew->item.name);
		for (i = 0; i < strlen(pnew->item.name); i++) {
			if (pnew->item.name[i] >= '0' && pnew->item.name[i] <= '9') {
				//�ĳ� &&
				printf("�벻Ҫ�������֣����������룺");
				break;
			}
			else {
				lala = 1;
				break;
			}
		}
	} while (lala == 0);

	do {
		printf("���������ĳɼ�: ");  scanf("%d", &pnew->item.chinese);
		while (getchar() != '\n')
			continue;
		printf("��������ѧ�ɼ�: ");  scanf("%d", &pnew->item.math);
		while (getchar() != '\n')
			continue;
		printf("������Ӣ��ɼ�: ");  scanf("%d", &pnew->item.english);
		while (getchar() != '\n')
			continue;
		if (pnew->item.chinese < 0 || pnew->item.chinese>100 || pnew->item.math < 0 || pnew->item.math>100 || pnew->item.english < 0 || pnew->item.english>100)
		{
			printf("\t\t______________________\n");
			printf("\t\t_�ɼ�������0-100֮��__\n");
			printf("\t\t______________________\n");
			printf("\t\t��������ɼ�\n");
		}
		else {
			break;
		}
	} while (1);
	pnew->next = p->next;
	p->next = pnew;
	return head;
}
void sort()//����˵�
{
	int flag = 1;
	system("CLS");
	char xs[20];
	char xss[20];
	while (flag) {
		do {
			system("CLS");
		printf("\t\t|-----------------------------------------|\n");
		printf("\t\t|-----------��Ҫ��ѡ������----------------|\n");
		printf("\t\t|----1.�����ĳɼ�����  2.����ѧ�ɼ�����---|\n");
		printf("\t\t|--------------3.��Ӣ��ɼ�����  ---------|\n");
		printf("\t\t|---------����1ѡ������0�˳�------------|\n");
			printf("����������Ҫ��ʲĪ����");
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
				printf("�����������������ѡ��:\n ");
			}
			printf("���������밴1���˳��밴0:");
			scanf("%s", xss);

			if (!strcmp(xss, "0")) {
				flag = 0;
			}
		} while (!strcmp(xss, "1"));
	}
}
List sortfile()//���ļ��е���Ϣ����ṹ������
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
void chinesest()//�����ĳɼ�����
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
		printf("\t\t           ��������             \n");
		printf("\t\t%10s%10s%10s%10s%10s\n", "ѧ��", "����", "����", "��ѧ", "Ӣ��");
		printf("\t\t--------------------------------------------------------------\n");
		for (t = head->next; t != NULL; t = t->next) {
			printf("\t\t%10s%10s%10d%10d%10d\n", t->item.id, t->item.name, t->item.chinese, t->item.math, t->item.english);
		}
		printf("���������Ƿ���Ҫ�˳���\n");
		printf("�˳��밴0�������鿴�밴1��");
		scanf("%s", ys);
		if (!strcmp(ys, "0")) {
			break;
		}
	} while (!strcmp(ys, "1"));
	
}
void mathst()//����ѧ�ɼ�����
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
		printf("\t\t            ��ѧ����             \n");
		printf("\t\t%10s%10s%10s%10s%10s\n", "ѧ��", "����", "����", "��ѧ", "Ӣ��");
		printf("\t\t--------------------------------------------------------------\n");
		for (t = phead->next; t != NULL; t = t->next) {
			printf("\t\t%10s%10s%10d%10d%10d\n", t->item.id, t->item.name, t->item.chinese, t->item.math, t->item.english);
		}
		printf("���������Ƿ���Ҫ�˳���\n");
		printf("�˳��밴0�������鿴�밴1��");
		scanf("%s", ys);
		if (!strcmp(ys, "0")) {
			break;
		}
	} while (!strcmp(ys, "1"));
}
void englishst()//��Ӣ��ɼ�����
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
		printf("\t\t            Ӣ������             \n");
		printf("\t\t%10s%10s%10s%10s%10s\n", "ѧ��", "����", "����", "��ѧ", "Ӣ��");
		printf("\t\t--------------------------------------------------------------\n");
		for (t = phead->next; t != NULL; t = t->next) {
			printf("\t\t%10s%10s%10d%10d%10d\n", t->item.id, t->item.name, t->item.chinese, t->item.math, t->item.english);
		}
		printf("���������Ƿ���Ҫ�˳���\n");
		printf("�˳��밴0�������鿴�밴1��");
		scanf("%s", ys);
		if (!strcmp(ys, "0")) {
			break;
		}
	} while (!strcmp(ys, "1"));
	
}
int cmp(const void *a, const void *b)//qsort��������
{
	Item *aa = (Item *)a;
	Item *bb = (Item *)b;
	return(((aa->zongfen)>(bb->zongfen))?1:-1);  //���� 
									//return(*(int *)b-*(int *)a); //���� 
}
void zongfen()//���ܳɼ�����
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
void tongji()//ͳ��ѧ����Ϣ
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
		printf("\t\t|______________ѧ���ɼ�����_________________________|\n");
		printf("\t\t|___________________________________________________|\n");
		printf("\t\tһ��¼����%d��ѧ���ɼ�\n", n);
		printf("\t\t���ļ�������Ϊ%d\n", chi);
		printf("\t\t��ѧ��������Ϊ%d\n", mat);
		printf("\t\tӢ�Ｐ������Ϊ%d\n", eng);
		printf("\t\t�������\n");
		printf("�˳��밴0��");
		scanf("%s", xt);
	}while (!strcmp(xt, "1"));
}

