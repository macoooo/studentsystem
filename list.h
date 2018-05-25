#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define LEN sizeof(Node)
#define LEN2 sizeof(Node2)
#ifndef LIST
#define LIST
//Ñ§Éú
typedef struct data {
	char name[20];
	char id[20];
	int math;
	int english;
	int chinese;
	int zongfen;
}Item;
typedef  struct student {
	Item item;
	struct student * next;
} * List,Node;
//ÕË»§
typedef struct account{
	char count[20];
	char password[20];
} Item2;
typedef struct data2{
	Item2 item;
	struct data * next;
} * List2,Node2;
//List == struct student *
//List == Nodea*;
List phead;
void printmenu();
List luru();
void coutinue();
void savefile(List phead);
List readfile();
void find();
void repair();
void delete();
void add();
void chazhao();
int chazhaoid();
int chazhaona();
void use();
List2 registers();
void creataccount(List2 qhead);
List2 outputfile();
void login1();
void managefile();
int login2();
void secretword(char key[]);
void insert();
List inserthead();
List insertend();
List insertmiddle();
void sort();
List sortfile();
void chinesest();
void mathst();
void englishst();
int cmp(const void *a, const void *b);
void zongfen();
void tongji();
#endif