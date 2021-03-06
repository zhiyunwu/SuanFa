#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>

#define MD_1 "e:\\1\\mingdan.txt" //手动录入信息时保存到此处
#define M_S "e:\\1\\xuesheng.txt"//存储学生密码的文件
#define M_T "e:\\1\\jiaoshi.txt"//存储教师账号密码的文件 
//temp 只是个过渡 

void Show1();
struct student *Input();
void Tofile(struct student *pHead);
void Zhuce();
void Wrire(int a);
void Findkey(int a);
void Output(struct student *pHead);
void Insert(struct student *pHead);
void Delete(struct student *pHead);
void Change(struct student *pHead);
void Seek(struct student *pHead);
void Sort(struct student *pHead,int a,int b);
void Analysis(struct student *pHead);
void Save_1(struct student *pHead);
void Show3();
void Fstudent(struct student *pHead);
void Show4();
void Tanal(struct student *pHead);
void Steacher(struct student *pHead);
void Show5();
void Manager();
void Luru();
void Student();
void Teacher();
void Manager();
void Putcode();
void Changecode(int c,char u[]);
void Changecode_ex();

 
struct student {
	int No;//排名 
	char name[50];//姓名 
	char num[50];//学号 
	char classes[20];//班级 
	char score[100]; 
	struct student *next;//指针域 
};
struct student *pHead;
int iCount; 
char u[50];//学生登陆时的账号 

typedef struct {//账号 和 密码 
	char user[200];
	char code[20];
	char tel[50];
}Users; 
Users pe;

void Wrire();

int main(int argc, char *argv[]) {
	char flag[50];
	system("color 8F");
	while(1) {
		system("cls");
		Show1();
		fflush(stdin);
		scanf("%s",flag);
		switch(flag[0]) {
			case '1':Student();break;//学生登陆 
			case '2':Teacher();break;//教师登陆 
			case '3':Manager();break;//管理员登陆 
			case '4':Zhuce();break;//注册账号 
			case '5':
				{
					char k[50];
					printf("\t\t\t\t您的身份是：1.学生		2.教师\n");
					fflush(stdin);
					scanf("%s",&k);
					if(k[0]=='1') {
						Findkey(1);
					} else {
						Findkey(2);
					}
				};break;//找回密码 
			case '0':exit(0);break;//退出 
			default :printf("\t\t\t\t输入有误，请重新输入！\n");break;
		}
		printf("\t\t\t\t请按任意键进行下一步操作！\n");
		getch(); 
	}
	return 0;
}

void Show1(){
	printf("\t\t\t\t||===============欢迎使用学生成绩管理系统================||\n");
	printf("\t\t\t\t||\t\t\t*1.学生登陆\t\t\t ||\n");
	printf("\t\t\t\t||\t\t\t*2.教师登陆\t\t\t ||\n");
	printf("\t\t\t\t||\t\t\t*3.管理员登陆\t\t\t ||\n");
	printf("\t\t\t\t||\t\t\t*4.注册账号\t\t\t ||\n");
	printf("\t\t\t\t||\t\t\t*5.找回密码\t\t\t ||\n");
	printf("\t\t\t\t||\t\t\t*0.退出\t\t\t\t ||\n");
	printf("\t\t\t\t||请输入相应的数字进行操作！(0-5)\t\t\t ||\n");
	printf("\t\t\t\t||=======================================================||\n\t\t\t\t"); 
  }

struct student *Fromfile() {//学生链表信息从文件获取 
	char p[50];
	struct student *pHead,*pNew,*pEnd;
	FILE *fp,*ftp;
	char ch;
	iCount=0;
	pHead=(struct student *)malloc(sizeof(struct student));
	pHead->next=NULL;
	pEnd=pHead;
	fp=fopen(MD_1,"rt");
	ftp=fopen("e:\\1\\temp.txt","wt");
	if(fp==NULL || ftp==NULL) {
		printf("\t\t\t\t文件打开失败！\n");
		exit(1);
	}
	while((ch=fgetc(fp))!=EOF) {
		ch-=5;
		fputc(ch,ftp);
	}
	fclose(fp);
	fclose(ftp);
	fp=fopen("E:\\1\\temp.txt","rt");
	while(1) {
		pNew=(struct student *)malloc(sizeof(struct student));
		fscanf(fp,"%s %s %s %s",pNew->name,pNew->num,pNew->classes,pNew->score );
		pEnd->next =pNew;
		pEnd=pNew;
		iCount++;
		if(feof(fp)) {
			break;//文件读取完毕则停止读取 
		}
	 
	}
	pNew->next =NULL;
	fclose(fp);
	return pHead;
}


struct student *Input() {//手动录入学生信息 
	struct student *pHead=NULL,*pNew,*pEnd,*pt;
	FILE *fp,*ftp;
	int i,sum=0;
	iCount=0;
	char ch; 
	fp=fopen(MD_1,"rt");
	ftp=fopen("e:\\1\\temp.txt","wt");
	if(fp== NULL ||ftp==NULL ){
		printf("文件打开失败！\n");
		exit(1);
	}
	while((ch=fgetc(fp))!=EOF) {
		ch-=5;
		fputc(ch,ftp);
	}
	fclose(fp);
	fclose(ftp);
	fp=fopen("e:\\1\\temp.txt","rt");
	if(fp==NULL) {
		printf("文件打开失败！\n");
		exit(1);
	}
	pHead=(struct student *)malloc(sizeof(struct student));
	pHead->next =NULL;
	pEnd=pHead;
	while(1) {
		pNew=(struct student *)malloc(sizeof(struct student));
		fscanf(fp,"%s %s %s %s",pNew->name,pNew->num,pNew->classes,pNew->score );
		pEnd->next =pNew;
		pEnd=pNew;
		iCount++;
		if(feof(fp)) {
			break;//文件读取完毕则停止读取 
		}
	}
	pt=pHead->next ;
	while(1) {
		pNew=(struct student *)malloc(sizeof(struct student));
		printf("\t\t\t\t请输入姓名：\n\t\t\t\t");
		fflush(stdin);
		gets(pNew->name);
		printf("\t\t\t\t请输入学号：\n\t\t\t\t");
		fflush(stdin);
		gets(pNew->num);
		while(pt) {
			if(strcmp(pt->num ,pNew->num )==0) {
				printf("该学生信息已存在！\n");
				exit(1);
			}
			pt=pt->next ;
		}
		printf("\t\t\t\t请输入班级：\n\t\t\t\t");
		fflush(stdin);
		gets(pNew->classes);
		while(1) {
			sum=0;
			printf("\t\t\t\t请输入成绩：\n\t\t\t\t");
			fflush(stdin);	
			scanf("%s",pNew->score );
			{
				for(i=0;i<strlen(pNew->score );i++) {
					if(pNew->score [i]>='0' && pNew->score [i]<='9' ) {
						sum=sum*10+(pNew->score [i]-'0');
					} else {
						printf("\t\t\t\t输入有误请重新输入！\n\t\t\t\t");
						continue;
					}
				}
				if(sum>100) {
					printf("\t\t\t\t输入有误请重新输入！\n");
					continue;
				} else {
					break;
				}
			}
		}
		iCount++;
		pEnd->next=pNew;
		pNew->next=NULL;
		pEnd=pNew;			 
		
		printf("\t\t\t\t是否继续？(y/n)\n\t\t\t\t");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='n'||ch=='N') {
			break;
		}
	}
	return pHead;
}

void Tofile(struct student *pHead) {//把信息存储到文件中 
	struct student *pt=pHead;
	FILE *fp,*ftp;
	int i;
	char ch;
	ftp=fopen("e:\\1\\temp.txt","wt");
	//fp=fopen(MD_1,"wt");
	if(ftp==NULL) {
		printf("\t\t\t\t文件打开失败！\n");
		exit(1);
	} 
	pt=pt->next ; 
	while(pt!=NULL) {
		fprintf(ftp,"%s %s %s %s\n",pt->name,pt->num,pt->classes,pt->score );	
		pt=pt->next;
	}
	fclose(ftp);
	fp=fopen(MD_1,"wt");
	ftp=fopen("e:\\1\\temp.txt","rt");
	while((ch=fgetc(ftp))!=EOF) {
		ch+=5;
		fputc(ch,fp);
	}
	fclose(fp);
	fclose(ftp);
	printf("\t\t\t\t写入成功！\n");
}

void Write();
void Fingkey(int a);
void Zhuce() {//注册账号 
	system("cls");
	char temp[20],m[50],t[50],k[50];//注册的账号 密码 电话 
	int j;
	FILE *fp;
	char flag; 
	printf("\t\t\t\t||===============用户注册================||\n");
	printf("\t\t\t\t||1.我是学生		2.我是教师:\t ||\n\t\t\t\t");
	fflush(stdin);
	scanf("%c",&flag);
	switch(flag) {
			case '1':
				{
					system("cls");
					do {
					printf("\t\t\t\t请输入学号：\n\t\t\t\t");
					fflush(stdin);
					scanf("%s",temp );
					fp=fopen(M_S ,"r");
					if(fp==NULL) {
						printf("\t\t\t\t文件打开失败！\n");
						fclose(fp);
						exit(1);
						} 
					while(!feof(fp)) {
						fflush(stdin);
						fscanf(fp,"%s %s %s",pe.user  ,pe.code  ,pe.tel  );
						if(strcmp(pe.user ,temp)==0) {//判断是否被注册 
							printf("\t\t\t\t用户名已注册，是否继续？(y-继续注册，n-找回密码)\n\t\t\t\t");
							if(getch()=='y' || getch()=='Y') {
								return Zhuce();
							} else {
								Findkey(1); 
							}
						}
					}
					strcpy(pe.user ,temp);
					printf("\t\t\t\t请输入密码:\n\t\t\t\t");
					fflush(stdin);
						for(j=0;k[j-1]!=13;j++)//密码的星号显示 
						{
							k[j]=getch();
							if(k[j]==8 && j>0)
								printf("\b \b",j-=2);	
							else if(j>=0)
								printf("*");
							else
								printf(" ");
						}
						printf("\n");
						k[j-1]='\0';
							
					strcpy(pe.code ,k);
					printf("\t\t\t\t请再次输入密码：\n\t\t\t\t");
					fflush(stdin);
					for(j=0;m[j-1]!=13;j++)//密码的星号显示 
					{
						m[j]=getch();
						if(m[j]==8 && j>0)
							printf("\b \b",j-=2);	
						else if(j>=0)
							printf("*");
						else
							printf(" ");
					}
					printf("\n");
					m[j-1]='\0';	
					if(strcmp(pe.code ,m)) {
						printf("\t\t\t\t两次密码不一致，请重新输入密码！\n\t\t\t\t");
						fflush(stdin);
						for(j=0;m[j-1]!=13;j++)//密码的星号显示 
						{
							m[j]=getch();
							if(m[j]==8 && j>0)
								printf("\b \b",j-=2);	
							else if(j>=0)
								printf("*");
							else
								printf(" ");
						}
						printf("\n");
						m[j-1]='\0';	
					}
					printf("\t\t\t\t请输入手机号码：\n\t\t\t\t");
					fflush(stdin);
					scanf("%s",pe.tel );
					printf("\t\t\t\t请再次输入手机号码：\n\t\t\t\t");
					fflush(stdin);
					scanf("%s",t);
					if(strcmp(pe.tel ,t)) {
						printf("\t\t\t\t两次输入手机号不一致，请重新输入：\n\t\t\t\t");
						fflush(stdin);
						scanf("%s",t);
					}
				} while(strcmp(pe.code ,m)!=0 || strcmp(pe.tel ,t)!=0);
				
			
				system("cls");
				Write(1);//将用户信息写入文件，存储信息 
				//跳转到哪里 
				return ; 
				} break;
			case '2':
			{
					system("cls");
					do {
					printf("\t\t\t\t请输入工号：\n\t\t\t\t");
					fflush(stdin);
					scanf("%s",temp );
					fp=fopen(M_T ,"r");
					if(fp==NULL) {
						printf("\t\t\t\t文件打开失败！\n");
						fclose(fp);
						exit(1);
						} 
					while(!feof(fp)) {
						fflush(stdin);
						fscanf(fp,"%s %s %s",pe.user  ,pe.code  ,pe.tel  );
						if(strcmp(pe.user ,temp)==0) {//判断是否被注册 
							printf("\t\t\t\t用户名已注册，是否继续？(y-继续注册，n-找回密码)\n\t\t\t\t");
							if(getch()=='y' || getch()=='Y') {
								return Zhuce();
							} else {
								Findkey(2); 
							}
						}
					}
					strcpy(pe.user ,temp);
					printf("\t\t\t\t请输入密码:\n\t\t\t\t");
					for(j=0;k[j-1]!=13;j++)//密码的星号显示 
					{
						k[j]=getch();
						if(k[j]==8 && j>0)
							printf("\b \b",j-=2);	
						else if(j>=0)
							printf("*");
						else
							printf(" ");
					}
					printf("\n");
					k[j-1]='\0';	
					strcpy(pe.code ,k);
					printf("\t\t\t\t请再次输入密码：\n\t\t\t\t");
					fflush(stdin);
					for(j=0;m[j-1]!=13;j++)//密码的星号显示 
					{
						m[j]=getch();
						if(m[j]==8 && j>0)
							printf("\b \b",j-=2);	
						else if(j>=0)
							printf("*");
						else
							printf(" ");
					}
					printf("\n");
					m[j-1]='\0';	
					if(strcmp(pe.code ,m)) {
						printf("\t\t\t\t两次密码不一致，请重新输入密码！\n\t\t\t\t");
						fflush(stdin);
						for(j=0;m[j-1]!=13;j++)//密码的星号显示 
						{
							m[j]=getch();
							if(m[j]==8 && j>0)
								printf("\b \b",j-=2);	
							else if(j>=0)
								printf("*");
							else
								printf(" ");
						}
						printf("\n");
						m[j-1]='\0';	
					}
					printf("\t\t\t\t请输入手机号码：\n\t\t\t\t");
					fflush(stdin);
					scanf("%s",pe.tel );
					printf("\t\t\t\t请再次输入手机号码：\n\t\t\t\t");
					fflush(stdin);
					scanf("%s",t);
					if(strcmp(pe.tel ,t)) {
						printf("\t\t\t\t两次输入手机号不一致，请重新输入：\n\t\t\t\t");
						fflush(stdin);
						scanf("%s",t);
					}
				} while(strcmp(pe.code ,m)!=0 || strcmp(pe.tel ,t)!=0);
				
			
				system("cls");
				Write(2);//将用户信息写入文件，存储信息 
				//跳转到哪里 
				return ; 
				} break;
			default :printf("\t\t\t\t输入有误，请重新输入！\n");break;
			}
} 

void Write(int a) {//用户信息写入文件 
	FILE *fp,*ftp;
	char ch;
	if(a==1)//学生信息写入文件 
	{
		//fp=fopen(M_S ,"a+");
		ftp=fopen("e:\\1\\temp.txt","wt"); 
		if(ftp==NULL) {
			fclose(ftp);
			printf("\t\t\t\t密码写入文件时打开失败！\n");
			exit(1);
		}
		 if(fprintf(ftp,"%s %s %s\n",pe.user ,pe.code ,pe.tel )==EOF) {
		 	fclose(ftp);
		 	printf("\t\t\t\t文件写入错误！\n");
		 	exit(1); 
		 }//写入错误则退出程序 
		 fclose(ftp);
		 fp=fopen(M_S,"a+");
		 ftp=fopen("e:\\1\\temp.txt","rt");
		 if(fp==NULL || ftp==NULL) {
		 	printf("\t\t\t\t文件打开失败！\n");
		 	exit(1);
		 }
		 while((ch=fgetc(ftp))!=EOF) {
		 	ch+=5;
		 	fputc(ch,fp);
		 }
		 fclose(fp);
		 fclose(ftp);
		 printf("\t\t\t\t注册成功！\n");
	}
	else {
		
		//fp=fopen(M_S ,"a+");
		ftp=fopen("e:\\1\\temp.txt","wt"); 
		if(ftp==NULL) {
			fclose(ftp);
			printf("\t\t\t\t密码写入文件时打开失败！\n");
			exit(1);
		}
		 if(fprintf(ftp,"%s %s %s\n",pe.user ,pe.code ,pe.tel )==EOF) {
		 	fclose(ftp);
		 	printf("\t\t\t\t文件写入错误！\n");
		 	exit(1); 
		 }//写入错误则退出程序 
		 fclose(ftp);
		 fp=fopen(M_T,"a+");
		 ftp=fopen("e:\\1\\temp.txt","rt");
		 if(fp==NULL || ftp==NULL) {
		 	printf("\t\t\t\t文件打开失败！\n");
		 	exit(1);
		 }
		 while((ch=fgetc(ftp))!=EOF) {
		 	ch+=5;
		 	fputc(ch,fp);
		 }
		 fclose(fp);
		 fclose(ftp);
		 printf("\t\t\t\t注册成功！\n");
	}
} 

char *Denglu(int b) {//登陆 
	char a[20],temp[20];
	int flag=0;
	int j;
	FILE *fp,*ftp;
	char ch;
	system("cls");
	printf("\t\t\t\t||===============用户登陆===============||\n");
	if(b==1) //学生登陆 
	{
		fp=fopen(M_S,"rt");
		ftp=fopen("e:\\1\\temp.txt","wt");
		if(fp==NULL || ftp==NULL) {
			printf("\t\t\t\t文件打开失败！\n");
			exit(1);
		}
		printf("\t\t\t\t请输入账号：\n\t\t\t\t");
		fflush(stdin);
		scanf("%s",u);
		while((ch=fgetc(fp))!=EOF) {
			ch-=5;
			fputc(ch,ftp);
		}
		fclose(fp);
		fclose(ftp);
		fp=fopen("e:\\1\\temp.txt","rt");
		if(fp==NULL) {
			printf("文件打开失败！\n");
			exit(1);
		}
		while(!feof(fp)) {
			fflush(stdin);
			fscanf(fp,"%s %s %s",pe.user ,pe.code ,pe.tel );
			if(strcmp(pe.user ,u)==0) {
				flag=1;
				break;
			}
		}
		if(flag==0) {
			printf("\t\t\t\t该账号未注册，是否注册？(y/n)\n\t\t\t\t");
			if(getch()=='y' || getch()=='Y') {
				Zhuce();
			} else {
				Denglu(2); 
			}
		}
	 
		do {//检验密码是否正确 
		fflush(stdin);
		printf("\t\t\t\t请输入密码：\n\t\t\t\t");
		
		for(j=0;a[j-1]!=13;j++)//密码的星号显示 
		{
			a[j]=getch();
			if(a[j]==8 && j>0)
				printf("\b \b",j-=2);	
			else if(j>=0)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
		a[j-1]='\0';	
	 		
		if(strcmp(pe.code ,a)!=0) {//对比输入密码和设置密码 
			printf("\t\t\t\t密码输入不正确！\n");
			printf("\t\t\t\t1.退出  2.继续输入\n");
			fflush(stdin);
			temp[0]=getch();
			if(temp[0]=='1') {
				fclose(fp);
				return Denglu(2);
			}
			else if(temp[0]!='2') {
				printf("\t\t\t\t输入有误请重新输入！\n");
				Sleep(800);
				Denglu(2);
			}
		}
	} while(strcmp(pe.code ,a)!=0);
			
	}
	if(b==2) //教师登陆 
	{
		fp=fopen(M_T,"rt");
		ftp=fopen("e:\\1\\temp.txt","wt");
		if(fp==NULL || ftp==NULL) {
			printf("\t\t\t\t文件打开失败！\n");
			exit(1);
		}
		printf("\t\t\t\t请输入账号：\n\t\t\t\t");
		fflush(stdin);
		scanf("%s",u);
		while((ch=fgetc(fp))!=EOF) {
			ch-=5;
			fputc(ch,ftp);
		}
		fclose(fp);
		fclose(ftp);
		fp=fopen("e:\\1\\temp.txt","rt");
		if(fp==NULL) {
			printf("文件打开失败！\n");
			exit(1);
		}
		while(!feof(fp)) {
			fflush(stdin);
			fscanf(fp,"%s %s %s",pe.user ,pe.code ,pe.tel );
			if(strcmp(pe.user ,u)==0) {
				flag=1;
				break;
			}
		}
		if(flag==0) {
			printf("\t\t\t\t该账号未注册，是否注册？(y/n)\n\t\t\t\t");
			if(getch()=='y' || getch()=='Y') {
				Zhuce();
			} else {
				Denglu(2); 
			}
		}
	 
		do {//检验密码是否正确 
		fflush(stdin);
		printf("\t\t\t\t请输入密码：\n\t\t\t\t");
		
		for(j=0;a[j-1]!=13;j++)//密码的星号显示 
		{
			a[j]=getch();
			if(a[j]==8 && j>0)
				printf("\b \b",j-=2);	
			else if(j>=0)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
		a[j-1]='\0';	
	 		
		if(strcmp(pe.code ,a)!=0) {//对比输入密码和设置密码 
			printf("\t\t\t\t密码输入不正确！\n");
			printf("\t\t\t\t1.退出  2.继续输入\n");
			fflush(stdin);
			temp[0]=getch();
			if(temp[0]=='1') {
				fclose(fp);
				return Denglu(2);
			}
			else if(temp[0]!='2') {
				printf("\t\t\t\t输入有误请重新输入！\n");
				Sleep(800);
				Denglu(2);
			}
		}
	} while(strcmp(pe.code ,a)!=0);
			
	}
	if(b==3) {//管理员登陆 
		fp=fopen("E:\\1\\manager.txt","rt");
		ftp=fopen("e:\\1\\temp.txt","wt");
		if(fp==NULL || ftp==NULL) {
			printf("\t\t\t\t文件打开失败！\n");
			exit(1);
		}
		while((ch=fgetc(fp))!=EOF) {
			ch-=5;
			fputc(ch,ftp);
		}
		fclose(fp);
		fclose(ftp);
		fp=fopen("e:\\1\\temp.txt","rt");
		if(fp==NULL) {
			printf("文件打开失败！\n");
			exit(1);
		}
		fscanf(fp,"%s",u);
		fclose(fp);
		do {//检验密码是否正确 
		fflush(stdin);
		printf("\t\t\t\t请输入密码：\n\t\t\t\t");
		
		for(j=0;a[j-1]!=13;j++)//密码的星号显示 
		{
			a[j]=getch();
			if(a[j]==8 && j>0)
				printf("\b \b",j-=2);	
			else if(j>=0)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
		a[j-1]='\0';	
	 		
		if(strcmp(u,a)!=0) {//对比输入密码和设置密码 
			printf("\t\t\t\t密码输入不正确！\n");
			printf("\t\t\t\t1.退出  2.继续输入\n");
			fflush(stdin);
			temp[0]=getch();
			if(temp[0]=='1') {
				fclose(fp);
				return Denglu(3);
			}
			else if(temp[0]!='2') {
				printf("\t\t\t\t输入有误请重新输入！\n");
				Sleep(800);
				Denglu(3);
			}
		}
	
	} while(strcmp(u ,a)!=0);
	
	getch();
	} 
	return u;
}

//找回密码
void Findkey(int a) {
	system("cls");
	char u[50],m[50], t[50];
	FILE *fp,*ftp; 
	char ch;
	int flag=0;
	if(a==1)//学生 
	{
		printf("\t\t\t\t请输入您的账号：\n\t\t\t\t");
		scanf("%s",u);
		fp=fopen(M_S,"rt");
		ftp=fopen("e:\\1\\temp.txt","wt");
		if(fp==NULL || ftp==NULL) {
			printf("\t\t\t\t文件打开失败!\n");
			exit(1);
		}
		while((ch=fgetc(fp))!=EOF) {
			ch-=5;
			fputc(ch,ftp);
		}
		fclose(fp);
		fclose(ftp);
		fp=fopen("e:\\1\\temp.txt","rt");
		while(!feof(fp)) {
			fscanf(fp,"%s %s %s",&pe.user ,&pe.code ,&pe.tel );
			if(strcmp(pe.user ,u)==0) {
				flag=1;
				break;
			}
		}
		fclose(fp);
		if(flag==0) {
			printf("\t\t\t\t该账号未注册，是否注册？(y/n)\n\t\t\t\t");
			if(getch()=='y' || getch()=='Y') {
				return Zhuce(1);
			} else {
				return ;
			}
		}
		else {
			do {
				printf("\t\t\t\t请输入您的预留手机号：\n\t\t\t\t");
				fflush(stdin);
				scanf("%s",t);
				if(strcmp(pe.tel ,t)==0) {
					printf("\t\t\t\t您的密码是：%s\n\t\t\t\t",pe.code );
					break;
				} else {
					printf("\t\t\t\t您输入的手机号跟预留手机号不一致，是否继续输入手机号？(y/n)\n\t\t\t\t");
				}
			}while(getch()=='y' || getch()=='Y');
		}
	}
	if(a==2)//教师 
	{
		printf("\t\t\t\t请输入您的账号：\n\t\t\t\t");
		scanf("%s",u);
		fp=fopen(M_T,"rt");
		ftp=fopen("e:\\1\\temp.txt","wt");
		if(fp==NULL || ftp==NULL) {
			printf("\t\t\t\t文件打开失败!\n");
			exit(1);
		}
		while((ch=fgetc(fp))!=EOF) {
			ch-=5;
			fputc(ch,ftp);
		}
		fclose(fp);
		fclose(ftp);
		fp=fopen("e:\\1\\temp.txt","rt");
		while(!feof(fp)) {
			fscanf(fp,"%s %s %s",&pe.user ,&pe.code ,&pe.tel );
			if(strcmp(pe.user ,u)==0) {
				flag=1;
				break;
			}
		}
		fclose(fp);
		if(flag==0) {
			printf("\t\t\t\t该账号未注册，是否注册？(y/n)\n\t\t\t\t");
			if(getch()=='y' || getch()=='Y') {
				return Zhuce(1);
			} else {
				return ;
			}
		}
		else {
			do {
				printf("\t\t\t\t请输入您的预留手机号：\n\t\t\t\t");
				fflush(stdin);
				scanf("%s",t);
				if(strcmp(pe.tel ,t)==0) {
					printf("\t\t\t\t您的密码是：%s\n\t\t\t\t",pe.code );
					break;
				} else {
					printf("\t\t\t\t您输入的手机号跟预留手机号不一致，是否继续输入手机号？(y/n)\n\t\t\t\t");
				}
			}while(getch()=='y' || getch()=='Y');
		}
	}
}

void Output(struct student *pHead) {//输出 所有学生信息 
	struct student *pt;
	pt=pHead->next ;
	printf("\t\t\t\t名单一共有%d名学生\n",iCount);
	printf("\t\t\t\t姓名\t学号\t班级\t成绩\n");//没有排名 
	while(pt->next !=NULL)
	{
		printf("\t\t\t\t%s\t%s\t%s\t%s\n",pt->name,pt->num,pt->classes,pt->score );
		pt=pt->next;
	}
	getch();
}

void Insert(struct student *pHead) {//插入信息 
	int i,sum=0;
	char a[20];
	struct student *pNew,*pt,*p;
	p=pHead;
	printf("\t\t\t\t请输入您想要插入的位置：(请输入一个学号，表示插在该学生后)\n\t\t\t\t"); 
	fflush(stdin);
	scanf("%s",a);
	while(p->next && strcmp(p->num ,a)!=0) {
		p=p->next;
	} 
	if(p->next==NULL&&strcmp(p->num,a)!=0)
	{
		printf("\t\t\t\t未找到此人!\n");
		return ;//不确定怎么写 
	}	
	pt=pHead->next ;
	pNew=(struct student *)malloc(sizeof(struct student)); 
	printf("\t\t\t\t请输入姓名：");
	scanf("%s",pNew->name);
	printf("\t\t\t\t请输入学号：");
	scanf("%s",pNew->num);
	while(pt) {
		if(strcmp(pt->num ,pNew->num )==0) {
			printf("\t\t\t\t该学生信息已存在！\n");
			return;
		}
		pt=pt->next ;
	}
	printf("\t\t\t\t请输入班级：");
	scanf("%s",pNew->classes);
	while(1) {
			sum=0;
			printf("\t\t\t\t请输入成绩：\n\t\t\t\t");
			fflush(stdin);	
			scanf("%s",pNew->score );
			{
				for(i=0;i<strlen(pNew->score );i++) {
					if(pNew->score [i]>='0' && pNew->score [i]<='9' ) {
						sum=sum*10+(pNew->score [i]-'0');
					} else {
						printf("\t\t\t\t输入有误请重新输入！\n");
						continue;
					}
				}
				if(sum>100) {
					printf("\t\t\t\t输入有误请重新输入！\n");
					continue;
				} else {
					break;
				}
			}
		}
	
	pNew->next=pHead->next;
	pHead->next=pNew;
	iCount++;
} 

void Delete(struct student *pHead) {//删除学生信息 
	char a[20];
	struct student *pt=pHead;
	//pHead=pHead->next;
	printf("\t\t\t\t请输入您想删除的学生的学号：\n");
	scanf("%s",a);
	while(pHead && strcmp(pHead->num,a)!=0) {
		pt=pHead;
		pHead=pHead->next;
	} 
	if(pHead==NULL && strcmp(pHead->num,a)!=0)
		printf("\t\t\t\t查无此人！\n");
	else {
		pt->next=pHead->next;
		free(pHead);
		iCount--;
		printf("\t\t\t\t已删除！\n");
	}
} 

void Change(struct student *pHead) {//修改学生信息
	int i,sum=0; 
	char a[20];
	printf("\t\t\t\t请输入你想修改学生的学号\n\t\t\t\t");
	scanf("%s",a);
	while(pHead&&strcmp(pHead->num,a))
		pHead=pHead->next;
	if(pHead==NULL)
		printf("\t\t\t\t未找到此人\n");	
	else 
	{
		printf("\t\t\t\t请输入姓名：");
		scanf("%s",pHead->name);
		printf("\t\t\t\t请输入学号：");
		scanf("%s",pHead->num);
		printf("\t\t\t\t请输入班级：");
		scanf("%s",pHead->classes);
		while(1) {
			sum=0;
			printf("\t\t\t\t请输入成绩：\n\t\t\t\t");
			fflush(stdin);	
			scanf("%s",pHead->score );
			{
				for(i=0;i<strlen(pHead->score );i++) {
					if(pHead->score [i]>='0' && pHead->score [i]<='9' ) {
						sum=sum*10+(pHead->score [i]-'0');
					} else {
						printf("\t\t\t\t输入有误请重新输入！\n");
						continue;
					}
				}
				if(sum>100) {
					printf("\t\t\t\t输入有误请重新输入！\n");
					continue;
				} else {
					break;
				}
			}
		}
		printf("\t\t\t\t修改成功！\n");
	}
} 

void Seek(struct student *pHead) {//查询学生信息 
	char c[20];
	printf("\t\t\t\t请输入你想查询学生的学号\n\t\t\t\t");
	scanf("%s",c);
	while(pHead && strcmp(pHead->num,c)!=0)
		pHead=pHead->next;
	if(pHead==NULL)
		printf("\t\t\t\t未找到此人\n");	 
	else 
	{
		printf("姓名\t学号\t班级\t成绩\n");
		//printf("%d\t",pHead->No); 
		printf("\t\t\t\t%s\t\t%s\t\t%s\t\t%s\n",pHead->name,pHead->num,pHead->classes,pHead->score );
	}		
}

void Seek_1(struct student *pHead,char c[]) {//查询学生信息 
	while(pHead && strcmp(pHead->num,c)!=0)
		pHead=pHead->next;
	if(pHead==NULL)
		printf("\t\t\t\t您的成绩信息不存在！\n");	 
	else 
	{
		printf("\t\t\t\t姓名\t学号\t班级\t成绩\n\t\t\t\t");
		printf("%s\t%s\t%s\t%s\n",pHead->name,pHead->num,pHead->classes,pHead->score );
	}		
}

void Save_1();
void Sort(struct student *pHead,int a,int b) {//排序 降序  (算出排名) b控制输出或文件写入 
	struct student *f,*p,*x,*y,*pt=pHead ;
	int i,sum1,sum2;
	f=NULL;
	if(pt->next==NULL || pt->next->next==NULL) {
		return;
	}
	if(a==1)//按平均分排 
	{
		while(pt->next->next!=f) {
		for(p=pt ;p->next ->next!=f;p=p->next ) {
			sum1=sum2=0;
			for(i=0;i<strlen(p->next ->score);i++)
			{
				sum1=sum1*10+(p->next ->score[0]-'0');
			}
			for(i=0;i<strlen(p->next->next->score);i++)
			{
				sum2=sum2*10+(p->next->next ->score[0]-'0');
			}
			if(sum1 < sum2) {
				x=p->next;
				y=p->next ->next;
				p->next =y;
				x->next =y->next ;
				y->next =x;
			}
		}
		f=p->next ;
	}
	}
	if(a==2)//按学号排 
	{
		while(pt->next->next!=f) {
		for(p=pt ;p->next ->next!=f;p=p->next ) {
			if(strcmp(p->next ->num , p->next ->next->num)>0) {
				x=p->next;
				y=p->next ->next;
				p->next =y;
				x->next =y->next ;
				y->next =x;
			}
		}
		f=p->next ;
	}
	}
	if(b==1) {
		Output(pHead);//输出 
	}
	if(b==2) {
		Tofile(pHead);//文件写入 
	} 
}

void Analysis(struct student *pHead)
{
	struct student *pt=pHead;
	Sort(pHead,1,0); //按平均分排
	pt=pHead->next;
	int max=0,min=110,sum=0,i;
	while(pt->next !=NULL)
	{
		sum=0;
		for(i=0;i<strlen(pt->score );i++) {
			sum=sum*10+(pt->score [i]-'0');
		}
		if(max<sum)
		{
			max=sum;
		}
		if(min>sum)
		{
			min=sum;
		}
		pt=pt->next ;
	}
	printf("\t\t\t\t你们班最高分为：%d,最低分为：%d\n",max,min);
}


void Save_1(struct student *pHead) {//文件写入 
	FILE *fp;
	struct student *pt;
	pt=pHead->next ;
	char filename[100]; 
	char Biaoti[4][20]={"姓名","学号","班级","成绩"};
	printf("\t\t\t\t请输入文件路径及文件名："); 
	fflush(stdin);
	scanf("%s",filename); 
	fp=fopen(filename,"wt");
	if(fp==NULL)
	{
		printf("\t\t\t\t不能打开文件");
		exit(1); 
	}
	fprintf(fp,"%s\t%s\t%s\t%s\n",Biaoti[0],Biaoti[1],Biaoti[2],Biaoti[3]);
	while(pt)
	{

		fprintf(fp,"%s\t%s\t%s\t%s\n",pt->name,pt->num,pt->classes,pt->score );
		pHead=pHead->next;
		
		pt=pt->next ;
	}
	printf("\t\t\t\t下载成功！\n");
	fclose(fp);
} 

void Show3() {
	printf("\t\t\t\t||=================欢迎登陆学生端=======================||\n");
	printf("\t\t\t\t||请选择要进行的操作：（0-4）\t\t\t\t||\n");
	printf("\t\t\t\t||\t\t\t*1.个人成绩查询\t\t\t||\n");
	printf("\t\t\t\t||\t\t\t*2.查询本班成绩\t\t\t||\n");
	printf("\t\t\t\t||\t\t\t*3.查看平均分\t\t\t||\n");
	printf("\t\t\t\t||\t\t\t*4.修改密码\t\t\t||\n");
	printf("\t\t\t\t||\t\t\t*5.返回上一层\t\t\t||\n");
	printf("\t\t\t\t||\t\t\t*0.退出\t\t\t\t||\n");
	printf("\t\t\t\t||======================================================||\n\t\t\t\t");
}


void Fstudent(struct student *pHead)//根据Show3 下边的操作 
{
	char flag; 
	while(1)
	{
		system("cls");
		Show3();
		fflush(stdin);
		scanf("%c",&flag);
		switch(flag)
		{
			case '1':pHead=Fromfile();Seek_1(pHead,u);break;//查询个人成绩 
			case '2':Output(pHead);break;//查询班级成绩 
			case '3': pHead=Fromfile();Analysis(pHead);break; //分析个人成绩 
			case '4':Changecode(1,u);break;
			case '5':return;break; 
			case '0':exit(0);break;
			default :printf("\t\t\t\t输入有误请重新输入\n");break; 
		}
		printf("\t\t\t\t按任意键进行下一步操作\n\t\t\t\t");
		getch();
	}
}

void Show4()//教师端显示页面 
{
	printf("\t\t\t\t||================欢迎登陆教师端================||\n");
	printf("\t\t\t\t||请输入相应的数字 (0-9) \t\t\t||\n"); 	
	printf("\t\t\t\t||*1.增加新的学生信息\t\t*2.删除学生信息 ||\n");
	printf("\t\t\t\t||*3.修改学生信息\t\t*4.查询学生信息 ||\n");
	printf("\t\t\t\t||*5.输出成绩 \t\t\t*6.修改密码\t||\n");
	printf("\t\t\t\t||*7.成绩统计\t\t\t*8.保存到文件\t||\n "); 
	printf("\t\t\t\t||*9.返回上一层\t\t\t* 0.退出\t||\n");
	printf("\t\t\t\t|| =============================================||\n\t\t\t\t");
}

//对于教师的成绩分析
//找最高分 和 最低分 和 统计每个分数段的人 
void Tanal(struct student *pHead) {
	struct student *pt;
	pt=pHead->next ;
	int i,sum;
	int num1=0,num2=0,num3=0,num4=0;
	int max=0,min=200;
	while(pt->next !=NULL)
	{
		sum=0;
		for(i=0;i<strlen(pt->score );i++) {
			sum=sum*10+(pt->score [i]-'0');
		}
		if(sum >max)	
			max=sum ;
		if(sum <min)
			min=sum;
		if(sum>90)//90分以上 
			num1++;
		else if(sum >80)
			num2++;//80分以上 
		else if(sum>70)
			num3++;//70分以上 
		else if(sum>=60)
			num4++; //60分以上 
		pt=pt->next;			
	}
	printf("\t\t\t\t最高分为：%d\n",max);
	printf("\t\t\t\t最低分为：%d\n",min);
	printf("\t\t\t\t分数在90分以上的人数为：%d\n",num1);
	printf("\t\t\t\t分数在80~90分以上的人数为：%d\n",num2);
	printf("\t\t\t\t分数在70~80分以上的人数为：%d\n",num3);
	printf("\t\t\t\t分数在60分以上的人数为：%d\n",num4);
}

void Steacher(struct student *pHead)//对应教师端的操作 
{
	pHead=Fromfile();
	char flag; 
	while(1)
	{
		system("cls");
		Show4();
		fflush(stdin);
		scanf("%c",&flag);
		switch(flag) 
		{
			case '1':Insert(pHead);Output(pHead);Tofile(pHead);break;
			case '2':Delete(pHead);Tofile(pHead);break;
			case '3':Change(pHead);Output(pHead);Tofile(pHead);break; 
			case '4':Seek(pHead);break;
			case '5':Output(pHead);break;
			case '6':Changecode(2,u);break;
			case '7':Tanal(pHead);break;
			case '8':Save_1(pHead);break;
			case '9':return;break; 
			case '0':exit(0);break;
			default :printf("\t\t\t\t输入有误请重新输入\n");break; 
		}
		printf("\t\t\t\t按任意键进行下一步操作\n");
		getch();
	}
}

void Show5()//管理员端 
{
	printf("\t\t\t\t||================欢迎登陆管理员端==============||\n");
	printf("\t\t\t\t||请选择您要进行的操作（0-6）\t\t\t||\n"); 	
	printf("\t\t\t\t||*1.进入教师端\t\t\t*2.修改账号密码\t||\n");
	printf("\t\t\t\t||*3.输出账号密码\t\t*4.录入学生信息\t||\n"); 
	printf("\t\t\t\t||*5.输出所有学生信息\t\t6.返回上一级\t||\n");
	printf("\t\t\t\t||*0.退出\t\t\t\t\t||\n"); 
	printf("\t\t\t\t||==============================================||\n\t\t\t\t");
} 

void Smanager() {
	struct student *pHead;
	char flag;
	while(1) {
		system("cls");
		Show5();
		fflush(stdin);
		scanf("%c",&flag);
		switch(flag) {
			case '1':
				Teacher();
				break;
			case '2':Changecode_ex();break;
			case '3':Putcode();break;
			case '4':Luru();break;
			case '5':pHead=Fromfile();Output(pHead);break;
			case '6':return ;break;
			case '0':exit(0);
			default :printf("\t\t\t\t输入有误，请重新输入！\n");break; 
		}
		printf("\t\t\t\t请按任意键继续！\n");
		getch();
	}
}

void Luru() {
	system("cls");
	char flag;
	printf("\t\t\t\t请选择录入方式：\n");
	printf("\t\t\t\t1.手动录入        2.从文件录入\n");
	fflush(stdin);
	scanf("%c",&flag);
	system("cls");
	switch(flag) {
		case '1':pHead=Input();Tofile(pHead);break;  
		case '2':pHead=Fromfile(2);Tofile(pHead);break;
		default :printf("\t\t\t\t输入有误，请重新输入！\n");break; 
	}
	printf("\t\t\t\t请按任意键退出！\n");
	getch();
	
}

void Student() {
	struct student *pHead;
	pHead=Fromfile();
	system("cls");
	Denglu(1);
	Fstudent(pHead);
} 

void Teacher() {
	struct student *pHead;
	pHead=Fromfile();
	system("cls");
	Denglu(2);
	Steacher(pHead);
}

void Manager() {
	system("cls");
	Denglu(3);
	Smanager(); 
}

void Putcode() {
	FILE *fp;
	char ch;
	printf("\t\t\t\t账号\t  密码\t 电话号\n\t\t\t\t");
	fp=fopen(M_S,"rt");
	if(fp==NULL ) {
		printf("\t\t\t\t文件打开失败！\n");
		exit(1);
	}
	while((ch=fgetc(fp))!=EOF) {
		ch-=5;
		putchar(ch);
		if(ch=='\n') {
			printf("\n\t\t\t\t");
		} 
	}
	fclose(fp);
	
	fp=fopen(M_T,"rt");
	if(fp==NULL ) {
		printf("\t\t\t\t文件打开失败！\n");
		exit(1);
	}
	while((ch=fgetc(fp))!=EOF) {
		ch-=5;
		putchar(ch);
	}
	fclose(fp);
} 

void Changecode(int c,char u[]) {
	FILE *fp,*ftp;
	char a[1000];
	char b[1000];
	char d[1000];
	char ch;
	Users temp[500];
	int i,j;
	if(c==1)//学生改密码 
	{
			i=0;
			fp=fopen(M_S,"r");
			ftp=fopen("e:\\1\\temp.txt","wt");
			if(fp==NULL || ftp==NULL) {
				printf("\t\t\t\t文件打开失败！\n");
				exit(1);
			}
			while((ch=fgetc(fp))!=EOF) {
				ch-=5;
				fputc(ch,ftp);
			}
			fclose(fp);
			fclose(ftp);
			printf("\t\t\t\t请输入新的密码：\n\t\t\t\t");
			fflush(stdin);
			for(j=0;a[j-1]!=13;j++)//密码的星号显示 
			{
				a[j]=getch();
				if(a[j]==8 && j>0)
					printf("\b \b",j-=2);	
				else if(j>=0)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
			a[j-1]='\0';	
	 		
			printf("\t\t\t\t请再次输入密码：\n\t\t\t\t");
			fflush(stdin);
			for(j=0;b[j-1]!=13;j++)//密码的星号显示 
			{
				b[j]=getch();
				if(b[j]==8 && j>0)
					printf("\b \b",j-=2);	
				else if(j>=0)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
			b[j-1]='\0';	
	 		
			if(strcmp(a,b)!=0)
				{
					printf("\t\t\t\t两次密码不一致，请重新输入：\n\t\t\t\t");
					return ;
				}
			fp=fopen("e:\\1\\temp.txt","rt");
			while(!feof(fp)) {
				fflush(stdin);
				fscanf(fp,"%s %s %s",&temp[i].user ,&temp[i].code ,&temp[i].tel );
				if(strcmp(temp[i].user ,u)==0) { 
						strcpy(temp[i].code ,b);
				}
				i++;
			}
			fclose(fp);
			fp=fopen("e:\\1\\temp.txt","wt");
			for(j=0;j<i;j++)
			{
				fprintf(fp,"%s %s %s\n",&temp[j].user ,&temp[j].code ,&temp[j].tel);
			}
			fclose(fp);
			ftp=fopen(M_S,"wt");
			fp=fopen("e:\\1\\temp.txt","rt");
			if(fp==NULL || ftp==NULL) {
				printf("文件打开失败！\n");
				exit(1);
			}
			while((ch=fgetc(fp))!=EOF) {
				ch+=5;
				fputc(ch,ftp);
			}
			fclose(fp);
			fclose(ftp);
			printf("\t\t\t\t修改成功！\n");
			printf("\t\t\t\t请按任意键继续\n");
			getch();	
	}
	else if(c==2){//修改教师的密码 
			i=0;
			fp=fopen(M_T,"r");
			ftp=fopen("e:\\1\\temp.txt","wt");
			if(fp==NULL || ftp==NULL) {
				printf("\t\t\t\t文件打开失败！\n");
				exit(1);
			}
			while((ch=fgetc(fp))!=EOF) {
				ch-=5;
				fputc(ch,ftp);
			}
			fclose(fp);
			fclose(ftp);
			printf("\t\t\t\t请输入新的密码：\n\t\t\t\t");
			fflush(stdin);
			for(j=0;a[j-1]!=13;j++)//密码的星号显示 
			{
				a[j]=getch();
				if(a[j]==8 && j>0)
					printf("\b \b",j-=2);	
				else if(j>=0)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
			a[j-1]='\0';	
	 		
			printf("\t\t\t\t请再次输入密码：\n\t\t\t\t");
			fflush(stdin);
			for(j=0;b[j-1]!=13;j++)//密码的星号显示 
			{
				b[j]=getch();
				if(b[j]==8 && j>0)
					printf("\b \b",j-=2);	
				else if(j>=0)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
			b[j-1]='\0';	
	 		
			if(strcmp(a,b)!=0)
				{
					printf("\t\t\t\t两次密码不一致，请重新输入：\n\t\t\t\t");
					return ;
				}
			fp=fopen("e:\\1\\temp.txt","rt");
			while(!feof(fp)) {
				fflush(stdin);
				fscanf(fp,"%s %s %s",&temp[i].user ,&temp[i].code ,&temp[i].tel );
				if(strcmp(temp[i].user ,u)==0) { 
						strcpy(temp[i].code ,b);
				}
				i++;
			}
			fclose(fp);
			fp=fopen("e:\\1\\temp.txt","wt");
			for(j=0;j<i;j++)
			{
				fprintf(fp,"%s %s %s\n",&temp[j].user ,&temp[j].code ,&temp[j].tel);
			}
			fclose(fp);
			ftp=fopen(M_T,"wt");
			fp=fopen("e:\\1\\temp.txt","rt");
			if(fp==NULL || ftp==NULL) {
				printf("文件打开失败！\n");
				exit(1);
			}
			while((ch=fgetc(fp))!=EOF) {
				ch+=5;
				fputc(ch,ftp);
			}
			fclose(fp);
			fclose(ftp);
			printf("\t\t\t\t修改成功！\n");
			printf("\t\t\t\t请按任意键继续\n");
			getch();	
		}
}
void Changecode_ex() {
			char a[500],b[500];
			FILE *fp,*ftp;
			char ch;
			int j;
			fp=fopen("e:\\1\\manager.txt","rt");
			ftp=fopen("e:\\1\\temp.txt","wt");
			if(fp==NULL || ftp==NULL) {
				printf("\t\t\t\t文件打开失败！\n");
				exit(1);
			}
			while((ch=fgetc(fp))!=EOF) {
				ch-=5;
				fputc(ch,ftp);
			}
			fclose(fp);
			fclose(ftp);
			printf("\t\t\t\t请输入新的密码：\n\t\t\t\t");
			fflush(stdin);
			for(j=0;a[j-1]!=13;j++)//密码的星号显示 
			{
				a[j]=getch();
				if(a[j]==8 && j>0)
					printf("\b \b",j-=2);	
				else if(j>=0)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
			a[j-1]='\0';	
	 		
			printf("\t\t\t\t请再次输入密码：\n\t\t\t\t");
			fflush(stdin);
			for(j=0;b[j-1]!=13;j++)//密码的星号显示 
			{
				b[j]=getch();
				if(b[j]==8 && j>0)
					printf("\b \b",j-=2);	
				else if(j>=0)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
			b[j-1]='\0';	
	 		
			if(strcmp(a,b)!=0)
				{
					printf("\t\t\t\t两次密码不一致，请重新输入：\n\t\t\t\t");
					return ;
				}
			fp=fopen("e:\\1\\temp.txt","wt");
			fprintf(fp,"%s",a);
			fclose(fp);
			ftp=fopen("e:\\1\\manager.txt","wt");
			fp=fopen("e:\\1\\temp.txt","rt");
			if(fp==NULL || ftp==NULL) {
				printf("文件打开失败！\n");
				exit(1);
			}
			while((ch=fgetc(fp))!=EOF) {
				ch+=5;
				fputc(ch,ftp);
			}
			fclose(fp);
			fclose(ftp);
			printf("\t\t\t\t修改成功！\n");
			printf("\t\t\t\t请按任意键继续\n");
			getch();	
}

