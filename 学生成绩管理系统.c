#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>

#define MD_1 "e:\\1\\mingdan.txt" //�ֶ�¼����Ϣʱ���浽�˴�
#define M_S "e:\\1\\xuesheng.txt"//�洢ѧ��������ļ�
#define M_T "e:\\1\\jiaoshi.txt"//�洢��ʦ�˺�������ļ� 
//temp ֻ�Ǹ����� 

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
	int No;//���� 
	char name[50];//���� 
	char num[50];//ѧ�� 
	char classes[20];//�༶ 
	char score[100]; 
	struct student *next;//ָ���� 
};
struct student *pHead;
int iCount; 
char u[50];//ѧ����½ʱ���˺� 

typedef struct {//�˺� �� ���� 
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
			case '1':Student();break;//ѧ����½ 
			case '2':Teacher();break;//��ʦ��½ 
			case '3':Manager();break;//����Ա��½ 
			case '4':Zhuce();break;//ע���˺� 
			case '5':
				{
					char k[50];
					printf("\t\t\t\t��������ǣ�1.ѧ��		2.��ʦ\n");
					fflush(stdin);
					scanf("%s",&k);
					if(k[0]=='1') {
						Findkey(1);
					} else {
						Findkey(2);
					}
				};break;//�һ����� 
			case '0':exit(0);break;//�˳� 
			default :printf("\t\t\t\t�����������������룡\n");break;
		}
		printf("\t\t\t\t�밴�����������һ��������\n");
		getch(); 
	}
	return 0;
}

void Show1(){
	printf("\t\t\t\t||===============��ӭʹ��ѧ���ɼ�����ϵͳ================||\n");
	printf("\t\t\t\t||\t\t\t*1.ѧ����½\t\t\t ||\n");
	printf("\t\t\t\t||\t\t\t*2.��ʦ��½\t\t\t ||\n");
	printf("\t\t\t\t||\t\t\t*3.����Ա��½\t\t\t ||\n");
	printf("\t\t\t\t||\t\t\t*4.ע���˺�\t\t\t ||\n");
	printf("\t\t\t\t||\t\t\t*5.�һ�����\t\t\t ||\n");
	printf("\t\t\t\t||\t\t\t*0.�˳�\t\t\t\t ||\n");
	printf("\t\t\t\t||��������Ӧ�����ֽ��в�����(0-5)\t\t\t ||\n");
	printf("\t\t\t\t||=======================================================||\n\t\t\t\t"); 
  }

struct student *Fromfile() {//ѧ��������Ϣ���ļ���ȡ 
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
		printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
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
			break;//�ļ���ȡ�����ֹͣ��ȡ 
		}
	 
	}
	pNew->next =NULL;
	fclose(fp);
	return pHead;
}


struct student *Input() {//�ֶ�¼��ѧ����Ϣ 
	struct student *pHead=NULL,*pNew,*pEnd,*pt;
	FILE *fp,*ftp;
	int i,sum=0;
	iCount=0;
	char ch; 
	fp=fopen(MD_1,"rt");
	ftp=fopen("e:\\1\\temp.txt","wt");
	if(fp== NULL ||ftp==NULL ){
		printf("�ļ���ʧ�ܣ�\n");
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
		printf("�ļ���ʧ�ܣ�\n");
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
			break;//�ļ���ȡ�����ֹͣ��ȡ 
		}
	}
	pt=pHead->next ;
	while(1) {
		pNew=(struct student *)malloc(sizeof(struct student));
		printf("\t\t\t\t������������\n\t\t\t\t");
		fflush(stdin);
		gets(pNew->name);
		printf("\t\t\t\t������ѧ�ţ�\n\t\t\t\t");
		fflush(stdin);
		gets(pNew->num);
		while(pt) {
			if(strcmp(pt->num ,pNew->num )==0) {
				printf("��ѧ����Ϣ�Ѵ��ڣ�\n");
				exit(1);
			}
			pt=pt->next ;
		}
		printf("\t\t\t\t������༶��\n\t\t\t\t");
		fflush(stdin);
		gets(pNew->classes);
		while(1) {
			sum=0;
			printf("\t\t\t\t������ɼ���\n\t\t\t\t");
			fflush(stdin);	
			scanf("%s",pNew->score );
			{
				for(i=0;i<strlen(pNew->score );i++) {
					if(pNew->score [i]>='0' && pNew->score [i]<='9' ) {
						sum=sum*10+(pNew->score [i]-'0');
					} else {
						printf("\t\t\t\t�����������������룡\n\t\t\t\t");
						continue;
					}
				}
				if(sum>100) {
					printf("\t\t\t\t�����������������룡\n");
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
		
		printf("\t\t\t\t�Ƿ������(y/n)\n\t\t\t\t");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='n'||ch=='N') {
			break;
		}
	}
	return pHead;
}

void Tofile(struct student *pHead) {//����Ϣ�洢���ļ��� 
	struct student *pt=pHead;
	FILE *fp,*ftp;
	int i;
	char ch;
	ftp=fopen("e:\\1\\temp.txt","wt");
	//fp=fopen(MD_1,"wt");
	if(ftp==NULL) {
		printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
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
	printf("\t\t\t\tд��ɹ���\n");
}

void Write();
void Fingkey(int a);
void Zhuce() {//ע���˺� 
	system("cls");
	char temp[20],m[50],t[50],k[50];//ע����˺� ���� �绰 
	int j;
	FILE *fp;
	char flag; 
	printf("\t\t\t\t||===============�û�ע��================||\n");
	printf("\t\t\t\t||1.����ѧ��		2.���ǽ�ʦ:\t ||\n\t\t\t\t");
	fflush(stdin);
	scanf("%c",&flag);
	switch(flag) {
			case '1':
				{
					system("cls");
					do {
					printf("\t\t\t\t������ѧ�ţ�\n\t\t\t\t");
					fflush(stdin);
					scanf("%s",temp );
					fp=fopen(M_S ,"r");
					if(fp==NULL) {
						printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
						fclose(fp);
						exit(1);
						} 
					while(!feof(fp)) {
						fflush(stdin);
						fscanf(fp,"%s %s %s",pe.user  ,pe.code  ,pe.tel  );
						if(strcmp(pe.user ,temp)==0) {//�ж��Ƿ�ע�� 
							printf("\t\t\t\t�û�����ע�ᣬ�Ƿ������(y-����ע�ᣬn-�һ�����)\n\t\t\t\t");
							if(getch()=='y' || getch()=='Y') {
								return Zhuce();
							} else {
								Findkey(1); 
							}
						}
					}
					strcpy(pe.user ,temp);
					printf("\t\t\t\t����������:\n\t\t\t\t");
					fflush(stdin);
						for(j=0;k[j-1]!=13;j++)//������Ǻ���ʾ 
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
					printf("\t\t\t\t���ٴ��������룺\n\t\t\t\t");
					fflush(stdin);
					for(j=0;m[j-1]!=13;j++)//������Ǻ���ʾ 
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
						printf("\t\t\t\t�������벻һ�£��������������룡\n\t\t\t\t");
						fflush(stdin);
						for(j=0;m[j-1]!=13;j++)//������Ǻ���ʾ 
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
					printf("\t\t\t\t�������ֻ����룺\n\t\t\t\t");
					fflush(stdin);
					scanf("%s",pe.tel );
					printf("\t\t\t\t���ٴ������ֻ����룺\n\t\t\t\t");
					fflush(stdin);
					scanf("%s",t);
					if(strcmp(pe.tel ,t)) {
						printf("\t\t\t\t���������ֻ��Ų�һ�£����������룺\n\t\t\t\t");
						fflush(stdin);
						scanf("%s",t);
					}
				} while(strcmp(pe.code ,m)!=0 || strcmp(pe.tel ,t)!=0);
				
			
				system("cls");
				Write(1);//���û���Ϣд���ļ����洢��Ϣ 
				//��ת������ 
				return ; 
				} break;
			case '2':
			{
					system("cls");
					do {
					printf("\t\t\t\t�����빤�ţ�\n\t\t\t\t");
					fflush(stdin);
					scanf("%s",temp );
					fp=fopen(M_T ,"r");
					if(fp==NULL) {
						printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
						fclose(fp);
						exit(1);
						} 
					while(!feof(fp)) {
						fflush(stdin);
						fscanf(fp,"%s %s %s",pe.user  ,pe.code  ,pe.tel  );
						if(strcmp(pe.user ,temp)==0) {//�ж��Ƿ�ע�� 
							printf("\t\t\t\t�û�����ע�ᣬ�Ƿ������(y-����ע�ᣬn-�һ�����)\n\t\t\t\t");
							if(getch()=='y' || getch()=='Y') {
								return Zhuce();
							} else {
								Findkey(2); 
							}
						}
					}
					strcpy(pe.user ,temp);
					printf("\t\t\t\t����������:\n\t\t\t\t");
					for(j=0;k[j-1]!=13;j++)//������Ǻ���ʾ 
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
					printf("\t\t\t\t���ٴ��������룺\n\t\t\t\t");
					fflush(stdin);
					for(j=0;m[j-1]!=13;j++)//������Ǻ���ʾ 
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
						printf("\t\t\t\t�������벻һ�£��������������룡\n\t\t\t\t");
						fflush(stdin);
						for(j=0;m[j-1]!=13;j++)//������Ǻ���ʾ 
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
					printf("\t\t\t\t�������ֻ����룺\n\t\t\t\t");
					fflush(stdin);
					scanf("%s",pe.tel );
					printf("\t\t\t\t���ٴ������ֻ����룺\n\t\t\t\t");
					fflush(stdin);
					scanf("%s",t);
					if(strcmp(pe.tel ,t)) {
						printf("\t\t\t\t���������ֻ��Ų�һ�£����������룺\n\t\t\t\t");
						fflush(stdin);
						scanf("%s",t);
					}
				} while(strcmp(pe.code ,m)!=0 || strcmp(pe.tel ,t)!=0);
				
			
				system("cls");
				Write(2);//���û���Ϣд���ļ����洢��Ϣ 
				//��ת������ 
				return ; 
				} break;
			default :printf("\t\t\t\t�����������������룡\n");break;
			}
} 

void Write(int a) {//�û���Ϣд���ļ� 
	FILE *fp,*ftp;
	char ch;
	if(a==1)//ѧ����Ϣд���ļ� 
	{
		//fp=fopen(M_S ,"a+");
		ftp=fopen("e:\\1\\temp.txt","wt"); 
		if(ftp==NULL) {
			fclose(ftp);
			printf("\t\t\t\t����д���ļ�ʱ��ʧ�ܣ�\n");
			exit(1);
		}
		 if(fprintf(ftp,"%s %s %s\n",pe.user ,pe.code ,pe.tel )==EOF) {
		 	fclose(ftp);
		 	printf("\t\t\t\t�ļ�д�����\n");
		 	exit(1); 
		 }//д��������˳����� 
		 fclose(ftp);
		 fp=fopen(M_S,"a+");
		 ftp=fopen("e:\\1\\temp.txt","rt");
		 if(fp==NULL || ftp==NULL) {
		 	printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
		 	exit(1);
		 }
		 while((ch=fgetc(ftp))!=EOF) {
		 	ch+=5;
		 	fputc(ch,fp);
		 }
		 fclose(fp);
		 fclose(ftp);
		 printf("\t\t\t\tע��ɹ���\n");
	}
	else {
		
		//fp=fopen(M_S ,"a+");
		ftp=fopen("e:\\1\\temp.txt","wt"); 
		if(ftp==NULL) {
			fclose(ftp);
			printf("\t\t\t\t����д���ļ�ʱ��ʧ�ܣ�\n");
			exit(1);
		}
		 if(fprintf(ftp,"%s %s %s\n",pe.user ,pe.code ,pe.tel )==EOF) {
		 	fclose(ftp);
		 	printf("\t\t\t\t�ļ�д�����\n");
		 	exit(1); 
		 }//д��������˳����� 
		 fclose(ftp);
		 fp=fopen(M_T,"a+");
		 ftp=fopen("e:\\1\\temp.txt","rt");
		 if(fp==NULL || ftp==NULL) {
		 	printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
		 	exit(1);
		 }
		 while((ch=fgetc(ftp))!=EOF) {
		 	ch+=5;
		 	fputc(ch,fp);
		 }
		 fclose(fp);
		 fclose(ftp);
		 printf("\t\t\t\tע��ɹ���\n");
	}
} 

char *Denglu(int b) {//��½ 
	char a[20],temp[20];
	int flag=0;
	int j;
	FILE *fp,*ftp;
	char ch;
	system("cls");
	printf("\t\t\t\t||===============�û���½===============||\n");
	if(b==1) //ѧ����½ 
	{
		fp=fopen(M_S,"rt");
		ftp=fopen("e:\\1\\temp.txt","wt");
		if(fp==NULL || ftp==NULL) {
			printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
			exit(1);
		}
		printf("\t\t\t\t�������˺ţ�\n\t\t\t\t");
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
			printf("�ļ���ʧ�ܣ�\n");
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
			printf("\t\t\t\t���˺�δע�ᣬ�Ƿ�ע�᣿(y/n)\n\t\t\t\t");
			if(getch()=='y' || getch()=='Y') {
				Zhuce();
			} else {
				Denglu(2); 
			}
		}
	 
		do {//���������Ƿ���ȷ 
		fflush(stdin);
		printf("\t\t\t\t���������룺\n\t\t\t\t");
		
		for(j=0;a[j-1]!=13;j++)//������Ǻ���ʾ 
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
	 		
		if(strcmp(pe.code ,a)!=0) {//�Ա������������������ 
			printf("\t\t\t\t�������벻��ȷ��\n");
			printf("\t\t\t\t1.�˳�  2.��������\n");
			fflush(stdin);
			temp[0]=getch();
			if(temp[0]=='1') {
				fclose(fp);
				return Denglu(2);
			}
			else if(temp[0]!='2') {
				printf("\t\t\t\t�����������������룡\n");
				Sleep(800);
				Denglu(2);
			}
		}
	} while(strcmp(pe.code ,a)!=0);
			
	}
	if(b==2) //��ʦ��½ 
	{
		fp=fopen(M_T,"rt");
		ftp=fopen("e:\\1\\temp.txt","wt");
		if(fp==NULL || ftp==NULL) {
			printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
			exit(1);
		}
		printf("\t\t\t\t�������˺ţ�\n\t\t\t\t");
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
			printf("�ļ���ʧ�ܣ�\n");
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
			printf("\t\t\t\t���˺�δע�ᣬ�Ƿ�ע�᣿(y/n)\n\t\t\t\t");
			if(getch()=='y' || getch()=='Y') {
				Zhuce();
			} else {
				Denglu(2); 
			}
		}
	 
		do {//���������Ƿ���ȷ 
		fflush(stdin);
		printf("\t\t\t\t���������룺\n\t\t\t\t");
		
		for(j=0;a[j-1]!=13;j++)//������Ǻ���ʾ 
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
	 		
		if(strcmp(pe.code ,a)!=0) {//�Ա������������������ 
			printf("\t\t\t\t�������벻��ȷ��\n");
			printf("\t\t\t\t1.�˳�  2.��������\n");
			fflush(stdin);
			temp[0]=getch();
			if(temp[0]=='1') {
				fclose(fp);
				return Denglu(2);
			}
			else if(temp[0]!='2') {
				printf("\t\t\t\t�����������������룡\n");
				Sleep(800);
				Denglu(2);
			}
		}
	} while(strcmp(pe.code ,a)!=0);
			
	}
	if(b==3) {//����Ա��½ 
		fp=fopen("E:\\1\\manager.txt","rt");
		ftp=fopen("e:\\1\\temp.txt","wt");
		if(fp==NULL || ftp==NULL) {
			printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
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
			printf("�ļ���ʧ�ܣ�\n");
			exit(1);
		}
		fscanf(fp,"%s",u);
		fclose(fp);
		do {//���������Ƿ���ȷ 
		fflush(stdin);
		printf("\t\t\t\t���������룺\n\t\t\t\t");
		
		for(j=0;a[j-1]!=13;j++)//������Ǻ���ʾ 
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
	 		
		if(strcmp(u,a)!=0) {//�Ա������������������ 
			printf("\t\t\t\t�������벻��ȷ��\n");
			printf("\t\t\t\t1.�˳�  2.��������\n");
			fflush(stdin);
			temp[0]=getch();
			if(temp[0]=='1') {
				fclose(fp);
				return Denglu(3);
			}
			else if(temp[0]!='2') {
				printf("\t\t\t\t�����������������룡\n");
				Sleep(800);
				Denglu(3);
			}
		}
	
	} while(strcmp(u ,a)!=0);
	
	getch();
	} 
	return u;
}

//�һ�����
void Findkey(int a) {
	system("cls");
	char u[50],m[50], t[50];
	FILE *fp,*ftp; 
	char ch;
	int flag=0;
	if(a==1)//ѧ�� 
	{
		printf("\t\t\t\t�����������˺ţ�\n\t\t\t\t");
		scanf("%s",u);
		fp=fopen(M_S,"rt");
		ftp=fopen("e:\\1\\temp.txt","wt");
		if(fp==NULL || ftp==NULL) {
			printf("\t\t\t\t�ļ���ʧ��!\n");
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
			printf("\t\t\t\t���˺�δע�ᣬ�Ƿ�ע�᣿(y/n)\n\t\t\t\t");
			if(getch()=='y' || getch()=='Y') {
				return Zhuce(1);
			} else {
				return ;
			}
		}
		else {
			do {
				printf("\t\t\t\t����������Ԥ���ֻ��ţ�\n\t\t\t\t");
				fflush(stdin);
				scanf("%s",t);
				if(strcmp(pe.tel ,t)==0) {
					printf("\t\t\t\t���������ǣ�%s\n\t\t\t\t",pe.code );
					break;
				} else {
					printf("\t\t\t\t��������ֻ��Ÿ�Ԥ���ֻ��Ų�һ�£��Ƿ���������ֻ��ţ�(y/n)\n\t\t\t\t");
				}
			}while(getch()=='y' || getch()=='Y');
		}
	}
	if(a==2)//��ʦ 
	{
		printf("\t\t\t\t�����������˺ţ�\n\t\t\t\t");
		scanf("%s",u);
		fp=fopen(M_T,"rt");
		ftp=fopen("e:\\1\\temp.txt","wt");
		if(fp==NULL || ftp==NULL) {
			printf("\t\t\t\t�ļ���ʧ��!\n");
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
			printf("\t\t\t\t���˺�δע�ᣬ�Ƿ�ע�᣿(y/n)\n\t\t\t\t");
			if(getch()=='y' || getch()=='Y') {
				return Zhuce(1);
			} else {
				return ;
			}
		}
		else {
			do {
				printf("\t\t\t\t����������Ԥ���ֻ��ţ�\n\t\t\t\t");
				fflush(stdin);
				scanf("%s",t);
				if(strcmp(pe.tel ,t)==0) {
					printf("\t\t\t\t���������ǣ�%s\n\t\t\t\t",pe.code );
					break;
				} else {
					printf("\t\t\t\t��������ֻ��Ÿ�Ԥ���ֻ��Ų�һ�£��Ƿ���������ֻ��ţ�(y/n)\n\t\t\t\t");
				}
			}while(getch()=='y' || getch()=='Y');
		}
	}
}

void Output(struct student *pHead) {//��� ����ѧ����Ϣ 
	struct student *pt;
	pt=pHead->next ;
	printf("\t\t\t\t����һ����%d��ѧ��\n",iCount);
	printf("\t\t\t\t����\tѧ��\t�༶\t�ɼ�\n");//û������ 
	while(pt->next !=NULL)
	{
		printf("\t\t\t\t%s\t%s\t%s\t%s\n",pt->name,pt->num,pt->classes,pt->score );
		pt=pt->next;
	}
	getch();
}

void Insert(struct student *pHead) {//������Ϣ 
	int i,sum=0;
	char a[20];
	struct student *pNew,*pt,*p;
	p=pHead;
	printf("\t\t\t\t����������Ҫ�����λ�ã�(������һ��ѧ�ţ���ʾ���ڸ�ѧ����)\n\t\t\t\t"); 
	fflush(stdin);
	scanf("%s",a);
	while(p->next && strcmp(p->num ,a)!=0) {
		p=p->next;
	} 
	if(p->next==NULL&&strcmp(p->num,a)!=0)
	{
		printf("\t\t\t\tδ�ҵ�����!\n");
		return ;//��ȷ����ôд 
	}	
	pt=pHead->next ;
	pNew=(struct student *)malloc(sizeof(struct student)); 
	printf("\t\t\t\t������������");
	scanf("%s",pNew->name);
	printf("\t\t\t\t������ѧ�ţ�");
	scanf("%s",pNew->num);
	while(pt) {
		if(strcmp(pt->num ,pNew->num )==0) {
			printf("\t\t\t\t��ѧ����Ϣ�Ѵ��ڣ�\n");
			return;
		}
		pt=pt->next ;
	}
	printf("\t\t\t\t������༶��");
	scanf("%s",pNew->classes);
	while(1) {
			sum=0;
			printf("\t\t\t\t������ɼ���\n\t\t\t\t");
			fflush(stdin);	
			scanf("%s",pNew->score );
			{
				for(i=0;i<strlen(pNew->score );i++) {
					if(pNew->score [i]>='0' && pNew->score [i]<='9' ) {
						sum=sum*10+(pNew->score [i]-'0');
					} else {
						printf("\t\t\t\t�����������������룡\n");
						continue;
					}
				}
				if(sum>100) {
					printf("\t\t\t\t�����������������룡\n");
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

void Delete(struct student *pHead) {//ɾ��ѧ����Ϣ 
	char a[20];
	struct student *pt=pHead;
	//pHead=pHead->next;
	printf("\t\t\t\t����������ɾ����ѧ����ѧ�ţ�\n");
	scanf("%s",a);
	while(pHead && strcmp(pHead->num,a)!=0) {
		pt=pHead;
		pHead=pHead->next;
	} 
	if(pHead==NULL && strcmp(pHead->num,a)!=0)
		printf("\t\t\t\t���޴��ˣ�\n");
	else {
		pt->next=pHead->next;
		free(pHead);
		iCount--;
		printf("\t\t\t\t��ɾ����\n");
	}
} 

void Change(struct student *pHead) {//�޸�ѧ����Ϣ
	int i,sum=0; 
	char a[20];
	printf("\t\t\t\t�����������޸�ѧ����ѧ��\n\t\t\t\t");
	scanf("%s",a);
	while(pHead&&strcmp(pHead->num,a))
		pHead=pHead->next;
	if(pHead==NULL)
		printf("\t\t\t\tδ�ҵ�����\n");	
	else 
	{
		printf("\t\t\t\t������������");
		scanf("%s",pHead->name);
		printf("\t\t\t\t������ѧ�ţ�");
		scanf("%s",pHead->num);
		printf("\t\t\t\t������༶��");
		scanf("%s",pHead->classes);
		while(1) {
			sum=0;
			printf("\t\t\t\t������ɼ���\n\t\t\t\t");
			fflush(stdin);	
			scanf("%s",pHead->score );
			{
				for(i=0;i<strlen(pHead->score );i++) {
					if(pHead->score [i]>='0' && pHead->score [i]<='9' ) {
						sum=sum*10+(pHead->score [i]-'0');
					} else {
						printf("\t\t\t\t�����������������룡\n");
						continue;
					}
				}
				if(sum>100) {
					printf("\t\t\t\t�����������������룡\n");
					continue;
				} else {
					break;
				}
			}
		}
		printf("\t\t\t\t�޸ĳɹ���\n");
	}
} 

void Seek(struct student *pHead) {//��ѯѧ����Ϣ 
	char c[20];
	printf("\t\t\t\t�����������ѯѧ����ѧ��\n\t\t\t\t");
	scanf("%s",c);
	while(pHead && strcmp(pHead->num,c)!=0)
		pHead=pHead->next;
	if(pHead==NULL)
		printf("\t\t\t\tδ�ҵ�����\n");	 
	else 
	{
		printf("����\tѧ��\t�༶\t�ɼ�\n");
		//printf("%d\t",pHead->No); 
		printf("\t\t\t\t%s\t\t%s\t\t%s\t\t%s\n",pHead->name,pHead->num,pHead->classes,pHead->score );
	}		
}

void Seek_1(struct student *pHead,char c[]) {//��ѯѧ����Ϣ 
	while(pHead && strcmp(pHead->num,c)!=0)
		pHead=pHead->next;
	if(pHead==NULL)
		printf("\t\t\t\t���ĳɼ���Ϣ�����ڣ�\n");	 
	else 
	{
		printf("\t\t\t\t����\tѧ��\t�༶\t�ɼ�\n\t\t\t\t");
		printf("%s\t%s\t%s\t%s\n",pHead->name,pHead->num,pHead->classes,pHead->score );
	}		
}

void Save_1();
void Sort(struct student *pHead,int a,int b) {//���� ����  (�������) b����������ļ�д�� 
	struct student *f,*p,*x,*y,*pt=pHead ;
	int i,sum1,sum2;
	f=NULL;
	if(pt->next==NULL || pt->next->next==NULL) {
		return;
	}
	if(a==1)//��ƽ������ 
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
	if(a==2)//��ѧ���� 
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
		Output(pHead);//��� 
	}
	if(b==2) {
		Tofile(pHead);//�ļ�д�� 
	} 
}

void Analysis(struct student *pHead)
{
	struct student *pt=pHead;
	Sort(pHead,1,0); //��ƽ������
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
	printf("\t\t\t\t���ǰ���߷�Ϊ��%d,��ͷ�Ϊ��%d\n",max,min);
}


void Save_1(struct student *pHead) {//�ļ�д�� 
	FILE *fp;
	struct student *pt;
	pt=pHead->next ;
	char filename[100]; 
	char Biaoti[4][20]={"����","ѧ��","�༶","�ɼ�"};
	printf("\t\t\t\t�������ļ�·�����ļ�����"); 
	fflush(stdin);
	scanf("%s",filename); 
	fp=fopen(filename,"wt");
	if(fp==NULL)
	{
		printf("\t\t\t\t���ܴ��ļ�");
		exit(1); 
	}
	fprintf(fp,"%s\t%s\t%s\t%s\n",Biaoti[0],Biaoti[1],Biaoti[2],Biaoti[3]);
	while(pt)
	{

		fprintf(fp,"%s\t%s\t%s\t%s\n",pt->name,pt->num,pt->classes,pt->score );
		pHead=pHead->next;
		
		pt=pt->next ;
	}
	printf("\t\t\t\t���سɹ���\n");
	fclose(fp);
} 

void Show3() {
	printf("\t\t\t\t||=================��ӭ��½ѧ����=======================||\n");
	printf("\t\t\t\t||��ѡ��Ҫ���еĲ�������0-4��\t\t\t\t||\n");
	printf("\t\t\t\t||\t\t\t*1.���˳ɼ���ѯ\t\t\t||\n");
	printf("\t\t\t\t||\t\t\t*2.��ѯ����ɼ�\t\t\t||\n");
	printf("\t\t\t\t||\t\t\t*3.�鿴ƽ����\t\t\t||\n");
	printf("\t\t\t\t||\t\t\t*4.�޸�����\t\t\t||\n");
	printf("\t\t\t\t||\t\t\t*5.������һ��\t\t\t||\n");
	printf("\t\t\t\t||\t\t\t*0.�˳�\t\t\t\t||\n");
	printf("\t\t\t\t||======================================================||\n\t\t\t\t");
}


void Fstudent(struct student *pHead)//����Show3 �±ߵĲ��� 
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
			case '1':pHead=Fromfile();Seek_1(pHead,u);break;//��ѯ���˳ɼ� 
			case '2':Output(pHead);break;//��ѯ�༶�ɼ� 
			case '3': pHead=Fromfile();Analysis(pHead);break; //�������˳ɼ� 
			case '4':Changecode(1,u);break;
			case '5':return;break; 
			case '0':exit(0);break;
			default :printf("\t\t\t\t������������������\n");break; 
		}
		printf("\t\t\t\t�������������һ������\n\t\t\t\t");
		getch();
	}
}

void Show4()//��ʦ����ʾҳ�� 
{
	printf("\t\t\t\t||================��ӭ��½��ʦ��================||\n");
	printf("\t\t\t\t||��������Ӧ������ (0-9) \t\t\t||\n"); 	
	printf("\t\t\t\t||*1.�����µ�ѧ����Ϣ\t\t*2.ɾ��ѧ����Ϣ ||\n");
	printf("\t\t\t\t||*3.�޸�ѧ����Ϣ\t\t*4.��ѯѧ����Ϣ ||\n");
	printf("\t\t\t\t||*5.����ɼ� \t\t\t*6.�޸�����\t||\n");
	printf("\t\t\t\t||*7.�ɼ�ͳ��\t\t\t*8.���浽�ļ�\t||\n "); 
	printf("\t\t\t\t||*9.������һ��\t\t\t* 0.�˳�\t||\n");
	printf("\t\t\t\t|| =============================================||\n\t\t\t\t");
}

//���ڽ�ʦ�ĳɼ�����
//����߷� �� ��ͷ� �� ͳ��ÿ�������ε��� 
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
		if(sum>90)//90������ 
			num1++;
		else if(sum >80)
			num2++;//80������ 
		else if(sum>70)
			num3++;//70������ 
		else if(sum>=60)
			num4++; //60������ 
		pt=pt->next;			
	}
	printf("\t\t\t\t��߷�Ϊ��%d\n",max);
	printf("\t\t\t\t��ͷ�Ϊ��%d\n",min);
	printf("\t\t\t\t������90�����ϵ�����Ϊ��%d\n",num1);
	printf("\t\t\t\t������80~90�����ϵ�����Ϊ��%d\n",num2);
	printf("\t\t\t\t������70~80�����ϵ�����Ϊ��%d\n",num3);
	printf("\t\t\t\t������60�����ϵ�����Ϊ��%d\n",num4);
}

void Steacher(struct student *pHead)//��Ӧ��ʦ�˵Ĳ��� 
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
			default :printf("\t\t\t\t������������������\n");break; 
		}
		printf("\t\t\t\t�������������һ������\n");
		getch();
	}
}

void Show5()//����Ա�� 
{
	printf("\t\t\t\t||================��ӭ��½����Ա��==============||\n");
	printf("\t\t\t\t||��ѡ����Ҫ���еĲ�����0-6��\t\t\t||\n"); 	
	printf("\t\t\t\t||*1.�����ʦ��\t\t\t*2.�޸��˺�����\t||\n");
	printf("\t\t\t\t||*3.����˺�����\t\t*4.¼��ѧ����Ϣ\t||\n"); 
	printf("\t\t\t\t||*5.�������ѧ����Ϣ\t\t6.������һ��\t||\n");
	printf("\t\t\t\t||*0.�˳�\t\t\t\t\t||\n"); 
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
			default :printf("\t\t\t\t�����������������룡\n");break; 
		}
		printf("\t\t\t\t�밴�����������\n");
		getch();
	}
}

void Luru() {
	system("cls");
	char flag;
	printf("\t\t\t\t��ѡ��¼�뷽ʽ��\n");
	printf("\t\t\t\t1.�ֶ�¼��        2.���ļ�¼��\n");
	fflush(stdin);
	scanf("%c",&flag);
	system("cls");
	switch(flag) {
		case '1':pHead=Input();Tofile(pHead);break;  
		case '2':pHead=Fromfile(2);Tofile(pHead);break;
		default :printf("\t\t\t\t�����������������룡\n");break; 
	}
	printf("\t\t\t\t�밴������˳���\n");
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
	printf("\t\t\t\t�˺�\t  ����\t �绰��\n\t\t\t\t");
	fp=fopen(M_S,"rt");
	if(fp==NULL ) {
		printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
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
		printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
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
	if(c==1)//ѧ�������� 
	{
			i=0;
			fp=fopen(M_S,"r");
			ftp=fopen("e:\\1\\temp.txt","wt");
			if(fp==NULL || ftp==NULL) {
				printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
				exit(1);
			}
			while((ch=fgetc(fp))!=EOF) {
				ch-=5;
				fputc(ch,ftp);
			}
			fclose(fp);
			fclose(ftp);
			printf("\t\t\t\t�������µ����룺\n\t\t\t\t");
			fflush(stdin);
			for(j=0;a[j-1]!=13;j++)//������Ǻ���ʾ 
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
	 		
			printf("\t\t\t\t���ٴ��������룺\n\t\t\t\t");
			fflush(stdin);
			for(j=0;b[j-1]!=13;j++)//������Ǻ���ʾ 
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
					printf("\t\t\t\t�������벻һ�£����������룺\n\t\t\t\t");
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
				printf("�ļ���ʧ�ܣ�\n");
				exit(1);
			}
			while((ch=fgetc(fp))!=EOF) {
				ch+=5;
				fputc(ch,ftp);
			}
			fclose(fp);
			fclose(ftp);
			printf("\t\t\t\t�޸ĳɹ���\n");
			printf("\t\t\t\t�밴���������\n");
			getch();	
	}
	else if(c==2){//�޸Ľ�ʦ������ 
			i=0;
			fp=fopen(M_T,"r");
			ftp=fopen("e:\\1\\temp.txt","wt");
			if(fp==NULL || ftp==NULL) {
				printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
				exit(1);
			}
			while((ch=fgetc(fp))!=EOF) {
				ch-=5;
				fputc(ch,ftp);
			}
			fclose(fp);
			fclose(ftp);
			printf("\t\t\t\t�������µ����룺\n\t\t\t\t");
			fflush(stdin);
			for(j=0;a[j-1]!=13;j++)//������Ǻ���ʾ 
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
	 		
			printf("\t\t\t\t���ٴ��������룺\n\t\t\t\t");
			fflush(stdin);
			for(j=0;b[j-1]!=13;j++)//������Ǻ���ʾ 
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
					printf("\t\t\t\t�������벻һ�£����������룺\n\t\t\t\t");
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
				printf("�ļ���ʧ�ܣ�\n");
				exit(1);
			}
			while((ch=fgetc(fp))!=EOF) {
				ch+=5;
				fputc(ch,ftp);
			}
			fclose(fp);
			fclose(ftp);
			printf("\t\t\t\t�޸ĳɹ���\n");
			printf("\t\t\t\t�밴���������\n");
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
				printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
				exit(1);
			}
			while((ch=fgetc(fp))!=EOF) {
				ch-=5;
				fputc(ch,ftp);
			}
			fclose(fp);
			fclose(ftp);
			printf("\t\t\t\t�������µ����룺\n\t\t\t\t");
			fflush(stdin);
			for(j=0;a[j-1]!=13;j++)//������Ǻ���ʾ 
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
	 		
			printf("\t\t\t\t���ٴ��������룺\n\t\t\t\t");
			fflush(stdin);
			for(j=0;b[j-1]!=13;j++)//������Ǻ���ʾ 
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
					printf("\t\t\t\t�������벻һ�£����������룺\n\t\t\t\t");
					return ;
				}
			fp=fopen("e:\\1\\temp.txt","wt");
			fprintf(fp,"%s",a);
			fclose(fp);
			ftp=fopen("e:\\1\\manager.txt","wt");
			fp=fopen("e:\\1\\temp.txt","rt");
			if(fp==NULL || ftp==NULL) {
				printf("�ļ���ʧ�ܣ�\n");
				exit(1);
			}
			while((ch=fgetc(fp))!=EOF) {
				ch+=5;
				fputc(ch,ftp);
			}
			fclose(fp);
			fclose(ftp);
			printf("\t\t\t\t�޸ĳɹ���\n");
			printf("\t\t\t\t�밴���������\n");
			getch();	
}

