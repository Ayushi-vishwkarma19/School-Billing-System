#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
struct dat//for month,day
{
 int d,m;
};
int checkclass();//(1-12)
struct stu
{
struct dat dt;
float f,total,due;//f=fee
char n[100];
int roll,Class;
}stud;
struct teacher
{
struct dat dt;
char n[100];
float sal,adv,total;
int id,no;
}tech;
int checkdat(int,int);//check date
void add(int);//add record
void mod(int);//modify record
void search(int);//search record
void del(int);//delete record
void salary(int);//calculation of salary
void fee(int);
void start();
FILE *fs,*ft;//fs=student,ft=teacher
int month,day;
void exit();
void main()
{
clrscr();
int i;
for(i=0;i<80;i++)
{
printf("\xdb");
}
printf("\n");
for(i=0;i<80;i++)
{
printf("\xdb");
}
printf("\t____________________________________\n");
printf("\t|                                  |\n");
printf("\t| WELCOME TO SCHOOL BILLING SYSTEM |\n");
printf("\t|                                  |\n");
printf("\t____________________________________\n");
printf("Enter any key to continue");
for(i=0;i<5;i++)
{
printf(".");
delay(500);//after printing one dot anothe comes after 0.5 seconds
}
getch();
system("cls");//clear screen
printf("\n");
for(i=0;i<80;i++)
{
printf("\xdb");
}
printf("\n");
for(i=0;i<80;i++)
{
printf("\xdb");
}
printf("\n\tPlease Enter a key to start\n");
for(i=0;i<5;i++)
{
printf(".");
delay(500);
}
fflush(stdin);
getch();
system("cls");
printf("\n\tEnter today's date");
scanf("%d",&month,&day);
start();
}
void start()
{
int choice1,choice;//choice=select account type
system("cls");
printf("\n\t Enter Account type.\n Press 1:Student\n press 2:Teacher\npress 3: For exit\n");
fflush(stdin);
scanf("%d",&choice);
switch(choice)
{
case 1: system("cls");
	while(1)
	{
	printf("\t\tEnter your choice\n");
	printf("\t\t press 1: Add record\n");
	printf("\t\t press 2: Search record\n");
	printf("\t\t press 3: Delete record\n");
	printf("\t\t press 4: Calculate fees\n");
	printf("\t\t press 5: Exit\n");
	printf("\t\tEnter choice");
	fflush(stdin);
	scanf("%d",&choice1);
	switch(choice1)
	{
	case 1: add(choice);
		start();
	case 2: search(choice);
		start();
	case 3:	del(choice);
		start();
	case 4: fee(month);
		start();
	case 5: exit(0);
	default:
		{
		printf("\t\tInvalid entry !");
		system("pause");
		start();
		}

	}
	}
case 2: system("cls");
	while(1)
	{
	printf("\t\tEnter your choice\n");
	printf("\t\t press 1: Add record\n");
	printf("\t\t press 2: Search record\n");
	printf("\t\t press 3: Delete record\n");
	printf("\t\t press 4: Calculate salary\n");
	printf("\t\t press 5: Exit\n");
	printf("\t\tEnter choice");
	fflush(stdin);
	scanf("%d",&choice1);
	switch(choice1)
	{
	case 1: add(choice);
		start();
	case 2: search(choice);
		start();
	case 3:	del(choice);
		start();
	case 4: salary(month);
		start();
	case 5: exit(0);
	default:
		{
		printf("\t\tInvalid entry !");
		system("pause");
		start();
		}

	  }
	  }
case 3: exit(0);
}
}
void add(int choice)
{
int dif,cleardat,duedat;
float ff;
char ch='Y';
system("cls");
printf("\t----------------------------------------------------\n");
printf("\t---------------------ADD RECORD---------------------\n");
printf("\t----------------------------------------------------\n");
if(choice==1)
{
 while(ch=='Y')
 {
 printf("\t\tEnter the name of student\n");
 fflush(stdin);
 scanf("%[^\n]",stud.n);
 printf("\n\t\tEnter the class\n");
 fflush(stdin);
 stud.Class=checkclass();
 printf("\t\tEnter the Roll no.\n");
 fflush(stdin);
 scanf("%d",&stud.roll);
 printf("\t\tEnter month and day till which fee is paid:\n");
 fflush(stdin);
 scanf("%d%d",&cleardat,&duedat);
 cleardat=checkdat(cleardat,duedat);
 stud.dt.m=cleardat;
 ff=stud.Class;
 stud.f=1000*(1+ff);//diffrent classes fee
 dif=month-stud.dt.m;//month of fee left to be paid
 stud.due=(dif)*stud.f;//due fee
 if(dif==0)
 {
  stud.total=stud.f;
 }
 else
 {
 stud.total=stud.due;
 }
 fs=fopen("student.txt","w");
 fprintf(fs,"Name: %s\t Class: %d\t Roll: %d\t fee: %f\t duefee: %f\t Total : %f\n",stud.n,stud.Class,stud.roll,stud.f,stud.due,stud.total);
 fclose(fs);
 printf("\t\tDo you want to continue Y/N\n");
 fflush(stdin);
 ch=getch();
 }
 getch();
}
if(choice==2)
{
  while(ch=='Y')
 {
 printf("\t\tEnter the name of Teacher\n");
 fflush(stdin);
 scanf("%[^\n]",tech.n);
 printf("\t\tEnter the teacher id\n");
 fflush(stdin);
 scanf("%d",&tech.id);
 printf("\t\tEnter the class per month:\n");
 fflush(stdin);
 scanf("%d",&tech.no);
 printf("\t\t Enter the month and day till which salary is paid;\n");
 scanf("%d%d",&tech.dt.m,&tech.dt.d);
 cleardat=checkdat(cleardat,duedat);
 tech.dt.m=cleardat;
 tech.sal=tech.no*1000;
 tech.adv=(tech.dt.m-month-1)*tech.sal;
 tech.total=tech.sal;
 ft=fopen("teacher.txt","w");
 fprintf(ft,"Name: %s\t ID: %d\t No. of classes: %d\t,Salary: %f\t,Total: %f\t Advance: %f\t",tech.n,tech.id,tech.no,tech.sal,tech.total,tech.adv);
 fclose(ft);
 printf("\t\tDo you want to continue Y/N\n");
 fflush(stdin);
 ch=getch();
 }
 fflush(stdin);
 printf("\n\n");
 system("pause");
}
}
void search(int choice)
{
 char ch;
 char name[100];
 char name1[100];
 int a;
 if(choice==1)
 {
  int a=0;
  system("cls");
  printf("\t----------------------------------------------------\n");
  printf("\t------------------SEARCH RECORD---------------------\n");
  printf("\t----------------------------------------------------\n");
  printf("\t\tEnter Name.\n");
  fflush(stdin);
  scanf("%[^\n],",name);
  fs=fopen("student.txt","r");
  while(fscanf(fs,"%s",stud.n)!=0)
  {
   if(strcmp(stud.n,name)==0)
   {
   printf("name=%s\n",stud.n);
   printf("class=%d",stud.Class);
   printf("roll no.=%d\n",stud.roll);
   printf("monthly fee= %2f\n",stud.f);
   printf("Due fee=%2f\n",stud.due);
   printf("total=%2f\n",stud.total);
   a++;
   }
  }
  if(a==0)
  {
  printf("Record is not found\n");
  }
  //system("pause");
  fclose(fs);
  getch();
}
if(choice==2)
{
 while(ch=='Y')
 {
  a=0;
  printf(" Enter teacher name.\n");
  fflush(stdin);
  scanf("%[^\n]",name1);
  ft=fopen("teacher.txt","r");
  while(fscanf(ft,"%s",tech.n)!=0)
  {
   if(strcmp(tech.n,name1)==0)
   {
   printf("name=%s\n",tech.n);
   printf("Id= %d\n",tech.id);
   printf("monthly salary=%2f\n",tech.sal);
   printf("advance salary=%2f\n",tech.adv);
   a++;
   }
  }
  if(a==0)
  {
  printf("record is not found\n");
  }
  system("pause");
  fclose(ft);
  printf("Do you want to continue Y/N");
  fflush(stdin);
  ch=getch();
  }
  getch();
 }
}
void del(int choice)
{
system("cls");
printf("\t-------------------------------------------------------\n");
printf("\t--------------------DELETE RECORD----------------------\n");
printf("\t-------------------------------------------------------\n");
FILE *temp,*t1;
int a;
char ch='Y';
char name[50],name1[50];
if(choice==1)
{
 while(ch=='Y')
 {
 a=1;
  printf("Enter the name of student to delete record\n");
  fflush(stdin);
  scanf("%[^\n]",name);
  fs=fopen("student.txt","r");
  temp=fopen("tempfile","w");
   while(fscanf(fs,"%s",stud.n)!=0)
    {
     if(strcmp(stud.n,name)==0)
     {
     a=0;
     continue;
     }
     else
     {
     fwrite(&stud,sizeof(stud),1,temp);
     }
    }
    if(a==1)
    {
    printf("Record not found\n");
    }
    else
    {
    printf("Record is deleted successfully\n");
    system("pause");
    fflush(stdin);
    fclose(fs);
    fclose(temp);
    system("del student.txt");
    system("ren tempfile,student.txt");//renaming temp to student
    printf("Do you want to continue Y/N\n");
    fflush(stdin);
    ch=getch();
    }
    getch();
 }
}
if(choice==2)
{
  while(ch=='Y')
 {
  a=1;
  printf("Enter the name of teacher to delete record\n");
  fflush(stdin);
  scanf("%[^\n]",name1);
  fs=fopen("teacher.txt","r");
  temp=fopen("tempfile1","w");
   while(fscanf(ft,"%s",tech.n)!=0)
    {
     if(strcmp(tech.n,name)==0)
     {
     a=0;
     continue;
     }
     else
     {
     fwrite(&tech,sizeof(tech),1,t1);
     }
    }
    if(a==1)
    {
    printf("Record not found\n");
    }
    else
    {
    printf("Record is deleted successfully\n");
    system("pause");
    fflush(stdin);
    fclose(fs);
    fclose(temp);
    system("del teacher.txt");
    system("ren tempfile1,teacher.txt");//renaming t1 to teacher
    printf("Do you want to continue Y/N\n");
    fflush(stdin);
    ch=getch();
    }
    getch();
 }
}
}
int checkdat(int mnt,int dnt)
{
int mon,dy;
if(mnt>12||mnt<1||dnt<1||dnt>32)
{
printf("Invalid date!\nenter again\n");
fflush(stdin);
scanf("%d%d",&mon,&dy);
mon=checkdat(mon,dy);
}
return(mnt);
}
int checkclass()
{
 int cl,C;
 fflush(stdin);
 scanf("%d",&cl);
 if(cl>12||cl<1)
 {
 printf("Invalid class!\nEnter again\n");
 fflush(stdin);
 scanf("%d",&cl);
 }
 return cl;

}
void salary(int month)
{
system("cls");
printf("\t-------------------------------------------------------\n");
printf("\t------------------------SALARY-------------------------\n");
printf("\t-------------------------------------------------------\n");
FILE *f,*t;
int a,dy;
char name[50],ch='Y';
int mm,diff,I;
 while(ch=='Y')
 {
 a=1;
 fflush(stdin);
 printf("Enter name:");
 scanf("%[^\n]",name);
 printf("Enter ID:");
 scanf("%d",&I);
 f=fopen("teacher.txt","rb+");
 t=fopen("te","wb+");
 while(fscanf(f,"%s",tech.n)!=0)
 {
  if(strcmp(tech.n,name)==0)
  {
  float lsal;
  a=0;
  printf("Enter the month till which salary is to be paid\n");
  fflush(stdin);
  scanf("%d",&mm);
  mm=checkdat(mm,dy);
  tech.adv=(mm-month-1)*tech.sal;
  if(tech.adv<0)
  {
  tech.adv=0;
  }
  lsal=month-tech.dt.m;//months of salary left to be paid;
  if(lsal<0)
  {
  lsal=0;
  }
  tech.total=tech.adv+tech.sal*(1+lsal);
  if(mm==tech.dt.m)
  {
  tech.total=0;
  }
  printf("monthly salary left to be paid: %2f",lsal);
  printf("\n total: %2f\n",tech.total);
  printf(" advance: %2f\n",tech.adv);
  tech.dt.m=mm;
  fwrite(&tech,sizeof(tech),1,t);
  fclose(f);
  fclose(t);
 }
}
  if(a==1)
  {
  printf("Record is not found\n");
  }
  printf("\n\n");
  system("pause");
  fflush(stdin);
  system("del teacher.txt");
  system("ren te,teacher.txt");
 printf("Do you want to continue Y/N\n");
 fflush(stdin);
 ch=getch();
 }
}
void fee(int month)
{
FILE *f,*s;
int a,dif;
char name[50],ch='Y';
int R,M;
while(ch=='Y')
{
int a=1;
printf("Enter name:\n");
fflush(stdin);
scanf("%[^\n]",name);
printf("Enter Roll:\n");
fflush(stdin);
scanf("%d",&R);
f=fopen("student.txt" ,"rb+");
s=fopen("st","wb");
while(fscanf(f,"%s",stud.n)!=0)
{
 if(strcmp(stud.n,name)==0)
 {
 a=0;
 printf("Enter month till which fee is to be paid");
 fflush(stdin);
 scanf("%d",&M);
 dif=month-stud.dt.m; //stud.dt.m=till which fee is paid
 stud.due=(dif)*stud.f;
 if(stud.due<0) stud.due=0;
 stud.total=stud.f;
 printf("Due: %2f\n",stud.due);
 printf("total: %2f\n",stud.total);
 printf("Fee: %2f\n",stud.f);
 fwrite(&stud,sizeof(stud),1,s);
 }
}
if(a==1)
{
printf("Record is not found\n");
}
system("pause");
fflush(stdin);
fclose(f);
fclose(s);
system("del student.txt");
system("ren st ,student.txt");
printf("Do you want to continue Y/N\n");
fflush(stdin);
ch=getch();
}
getch();
}