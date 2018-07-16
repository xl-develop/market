#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int registe();//�û���¼����/ 
void adminiratostr();//����Ա������/
void sale_management();//���۹���/
void Good_query();//������
void supplier();//�����̹���
void Stock_query();//��������/
void clerk();//ְ������

void correct_user(int a);//�޸��û���
void correct_key(int a);//�޸�����

void Find_supply();//���ҹ����� 
void Add_good();//���� 

void Correct_good();//����޸�,,��Ʒ����
void sale_inventory();//�����̵�

void Find_good();//���ҿ�� 
void Delete_good();//ɾ����Ʒ 
void Addall_good();//�޸���Ʒ 
void add_newgood();//�����µ���Ʒ 

void Find_worker();//����ְԱ 
void Add_worker();//���ְԱ 
void Correct_worker();//�޸�ְԱ 
void Delete_worker();//ɾ��ְԱ

void Delete_supply();//ɾ�������� 
void Find_supply();//���ҹ����� 
void Correct_supply();//�޸Ĺ����� 
void Add_supply();//��ӹ����� 

typedef struct clerk//ְ����Ϣ
{
	int id;
	char name[10];
	char sex[5];
	char idcard[18];
	char tel[15];
	char add[20];
} CLERK;

typedef struct manage//����Ա��Ϣ
{
	char user[20];
	char key[20];
}MANAGE;

typedef struct supply//��������Ϣ
{
	int id1;
	int id2;//��Ʒ���
	char name[10];
	char tel[20];
	char add[20];
	int prince;
}SUPPLY;

typedef struct shop//��Ʒ��Ϣ
{
	int id;
	char name[10];
	int number;
	int purchase;
	int sale;
}SHOP;

void writeto_shopfile(SHOP stu[],int a);//д����Ʒ�ļ�
void writeto_clerkfile(CLERK stu[],int a);//д��ְ���ļ�
void writeto_supplyfile(SUPPLY stu[],int a);//д�빩�����ļ�
void sales_listing(SHOP stu[],int c,int b);//д�������嵥

int main()
{
	int i,j;
	printf("**********************************************\n");
	printf("************��ӭ���볬�й���ϵͳ**************\n");
	printf("**********************************************\n");
	j=registe();
	system("CLS");//�����¼����
	do{
		printf("1.����Ա����\n");
		printf("2.��������\n");
		printf("3.���۹���\n");
		printf("4.������\n");
		printf("5.�����̹���\n");
		printf("6.ְ������\n");
		printf("7.�˳�ϵͳ\n");
		printf("�������Ӧ���ܱ��:");
		scanf("%d",&i);
		getchar();
		system("CLS");//���һ���˵�Ŀ¼
		switch (i)//ͨ��switch���ﵽѡ������ã�ÿ�ο���ѡ��ͬ�Ĺ���
		{
		case 1:
			adminiratostr();break;
		case 2:
			Stock_query();break;
		case 3:
			sale_management();break;
		case 4:
			Good_query();break;
		case 5:
			supplier();break;
		case 6:
			clerk();break;
		default:
			exit(0);break;				
		}
		system("CLS");
	}while(i!=7);//�����벻Ϊ7��һֱѭ�����˵� 
	return 0;
}

int registe()//�û���¼����
{
	MANAGE stu[10];
	FILE *fp=fopen("user.txt","r");//����ָ�����Ա�ļ���ָ��
	int i=0,j=0;
	int n,m; 
	char u[20],k[20];
	if(fp==NULL)//�ж��ļ��Ƿ�򿪳ɹ�
	{
		printf("failure to open user.txt! \n");
		exit(0)	;
	}
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++) 
	{
		fscanf(fp,"%s\t%s",stu[i].user,stu[i].key);//�ļ���ȡ����
	}
	do{
		printf("�û���: ");
		gets(u);
		printf("����: ");
		gets(k);
		j++;
		for(m=0;m<n;m++)
		{
			if(strcmp(stu[m].user,u)==0&&strcmp(stu[m].key,k)==0)
			{
				printf("��¼�ɹ�!\n");
				fclose(fp); 
				return m;//�û�����������ȷ������������
			}
		}
		printf("����������\n");
	}while(j<3);//�û���������������Ļ��ᣬ�����˳�
	fclose(fp); 
	exit(0);
}

void adminiratostr()//����Ա������
{
	int i,j;
	j=registe();//�û���¼����
	system("CLS");
	do{
		printf("1.�޸��û���\n");
		printf("2.�޸�����\n");
		printf("3.�˳�\n");
		printf("�������Ӧ���ܱ��:");
		scanf("%d",&i);
		getchar();//���������ת���ַ� 
		switch (i)
		{
		case 1:
			correct_user(j);break;
		case 2:
			correct_key(j);break;
		default:
			return ;break;				
		}
		system("pause");//ϵͳ��ͣ 
		system("CLS");//�������Ա����Ŀ¼
	}while(i!=3);
	return ;
}

void correct_user(int a)//�޸��û���
{
	MANAGE stu[10];
	char w[20]; 
	int n,i; 
	FILE *fp;//����ָ�����Ա�ļ���ָ��
	if((fp=fopen("user.txt","r"))==NULL)//�ж��ļ��Ƿ�򿪳ɹ�
	{
		printf("failure to open user.txt\n");
		exit(0);
	}
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++) 
	{
		fscanf(fp,"%s\t%s",stu[i].user,stu[i].key);//�ļ���ȡ����
	}
	fclose(fp);
	if((fp=fopen("user.txt","w"))==NULL)//�ж��ļ��Ƿ�򿪳ɹ�
	{
		printf("failure to open user.txt\n");
		exit(0);
	} 
	printf("�������µ��û�����");
	gets(w);
	fprintf(fp,"%d\n",n); 
	for(i=0;i<n;i++)
	{
		if(i==a)
		{
			fprintf(fp,"%s %s\n",w,stu[i].key);
			continue ; 
		} 
		fprintf(fp,"%s %s\n",stu[i].user,stu[i].key);//���µ��û�����ԭ��������д���ļ���
	}
	fclose(fp);
	printf("chanage to the success!\n");
	return ;	
}

void correct_key(int a)//�޸����� 
{
	MANAGE stu[10];
	char w[20]; 
	int n,i; 
	FILE *fp;//����ָ�����Ա�ļ���ָ��
	if((fp=fopen("user.txt","r"))==NULL)//�ж��ļ��Ƿ�򿪳ɹ�
	{
		printf("failure to open user.txt\n");
		exit(0);
	}
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++) 
	{
		fscanf(fp,"%s\t%s",stu[i].user,stu[i].key);//�ļ���ȡ����
	}
	fclose(fp);
	if((fp=fopen("user.txt","w"))==NULL)//�ж��ļ��Ƿ�򿪳ɹ�
	{
		printf("failure to open user.txt\n");
		exit(0);
	} 
	printf("�������µ����룺");
	gets(w);
	fprintf(fp,"%d\n",n); 
	for(i=0;i<n;i++)
	{
		if(i==a)
		{
			fprintf(fp,"%s %s\n",stu[i].user,w);
			continue ;
		} 
		fprintf(fp,"%s %s\n",stu[i].user,stu[i].key);//���µ��û�����ԭ��������д���ļ���
	}
	fclose(fp);
	printf("chanage to the success!\n");
	return ;
}

void Stock_query()//��������
{
	int i;
	do{
		printf("1.���ҿ��\n");
		printf("2.���ҹ�����\n");
		printf("3.����\n") ; 
		printf("4.�˳�\n");
		printf("�������Ӧ���ܱ��:");
		scanf("%d",&i);
		switch (i)
		{
		case 1:
			Find_good();break;
		case 2:
			Find_supply();break;
		case 3:
			Add_good();break;
		default:
			return ;break;				
		}
		system("pause");//ϵͳ��ͣ 
		system("CLS");//�����������Ŀ¼ 
	}while(i!=4);
	return ;	
}

void Find_good()//������Ʒ
{
	SHOP stu[30];
	int id,n,i;
	FILE *fp=fopen("shop.txt","r"); //����ָ����Ʒ�ļ���ָ��
	if(fp==NULL)//�ж��ļ��Ƿ�򿪳ɹ�
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);  //���ļ��ж�ȡ��Ʒ��Ϣ 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%d",&stu[i].number);
		fscanf(fp,"%d",&stu[i].purchase);
		fscanf(fp,"%d",&stu[i].sale);
	}
	printf("��������Ʒ��ţ��磺01  :\n");//��ӡ��Ӧ����Ʒ��Ϣ 
	scanf("%d",&id);
	for(i=0;i<n;i++)
	{
		if(id==stu[i].id)
		{
			printf("��� ���� ���� ���� �ۼ�\n");
			printf("%4d %4s %4d %4d %4d\n",stu[i].id,stu[i].name,stu[i].number,stu[i].purchase,stu[i].sale);
		    printf("\n");
		    fclose(fp);
			return ;
		}
	}
	printf("û�и���Ʒ!\n");
	fclose(fp);
	return ;
}


void Find_supply()//���ҹ�����
{
	SUPPLY stu[30];
	int id,n,i;
	FILE *fp=fopen("supply.txt","r");//����ָ�򹩻����ļ���ָ��
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//���ļ��ж�ȡ��������Ϣ 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id1);
		fscanf(fp,"%d",&stu[i].id2);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
		fscanf(fp,"%d",&stu[i].prince);
	}
	printf("�������̼ұ�ţ��磺01  :\n");//��ӡ��Ӧ�Ĺ�������Ϣ��Ϣ 
	scanf("%d",&id);
	for(i=0;i<n;i++)
	{
		if(id==stu[i].id1)
		{
			printf("��� ��Ʒ��   ����   �绰   ��ַ   �۸�\n");
			printf("%4d %4d %4s %4s %4s %4d\n",stu[i].id1,stu[i].id2,stu[i].name,stu[i].tel,stu[i].add,stu[i].prince);
		    printf("\n");
		    fclose(fp);
			return ;
		}
	}
	printf("û�и��̼�!\n");
	fclose(fp);
	return ;
}

void Add_good()//�����Ʒ����
{
	SHOP stu[30];
	int id,m,n,i;
	FILE *fp=fopen("shop.txt","r");//����ָ����Ʒ�ļ���ָ��
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//���ļ��ж�ȡ��Ʒ��Ϣ 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%d",&stu[i].number);
		fscanf(fp,"%d",&stu[i].purchase);
		fscanf(fp,"%d",&stu[i].sale);
	}
	printf("��������Ҫ��ӵ���Ʒ��� ����:\n");//��ṹ�������������Ʒ����Ϣ 
	scanf("%d %d",&id,&m);
	for(i=0;i<n;i++)
	{
		if(id==stu[i].id)
		{
			fclose(fp);
			stu[i].number+=m;
			writeto_shopfile(stu,n);
			return ;
		}
	}
	printf("û�и���Ʒ!\n");
	fclose(fp);
	return;
}

void writeto_shopfile(SHOP stu[],int a)//д���ļ�����
{
	FILE *fp=fopen("shop.txt","w");
	int i;
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fprintf(fp,"%d\n",a);
	for(i=0;i<a;i++)
	{
		fprintf(fp,"%d %s %d %d %d\n",stu[i].id,stu[i].name,stu[i].number,stu[i].purchase,stu[i].sale);
	}
	fclose(fp);
	printf("\n");
}

void sale_management()//���۹���
{
	int i;
	do{
		printf("1.�鿴���\n");
		printf("2.������Ʒ\n");
		printf("3.�����̵�\n");
		printf("4.�˳�\n");
		printf("����������Ҫ�Ĺ��ܣ�\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				Find_good();break;
			case 2:
				Correct_good();break;
			case 3:
				sale_inventory();break;
			default:
				return ;		
		 } 
		system("pause"); //ϵͳ��ͣ 
		system("CLS");//������۹���Ŀ¼ 
	}while(i!=4);
	
}

void Correct_good()//����޸�,,��Ʒ���� 
{
 	SHOP stu[30];
	int id,m,n,i;
	FILE *fp=fopen("shop.txt","r");//����ָ����Ʒ�ļ���ָ�� 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//���ļ��ж�ȡ��Ʒ��Ϣ 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%d",&stu[i].number);
		fscanf(fp,"%d",&stu[i].purchase);
		fscanf(fp,"%d",&stu[i].sale);
	}
	printf("��������Ҫ���۵���Ʒ��� ����:\n"); //������Ʒ 
	scanf("%d %d",&id,&m);
	for(i=0;i<n;i++)
	{
		if(id==stu[i].id)
		{
			fclose(fp);
			stu[i].number-=m;
			sales_listing(stu,id,m);
			writeto_shopfile(stu,n);
			return ;
		}
	}
	printf("û�и���Ʒ!\n");
	fclose(fp);
	return;
 	
}

void sale_inventory()//�����̵�
{
	FILE *fp=fopen("inventory.txt","r");
	int id1[20];//����
	int id2[20];//��Ʒ���
	char name[20][10];//��Ʒ����
	int num[20];//��Ʒ����
	int sale[20];//��Ʒ�ۼ�
	int i,a,id;
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&a);
	for(i=0;i<a;i++)
	{
		fscanf(fp,"%d",&id1[i]);
		fscanf(fp,"%d",&id2[i]);
		fscanf(fp,"%s",&name[i]);
		fscanf(fp,"%d",&num[i]);
		fscanf(fp,"%d",&sale[i]);
	}
	printf("��������Ҫ��ѯ����Ʒ���: \n");
	scanf("%d",&id);
	for(i=0;i<a;i++)
	{
		if(id==id2[i])
		{
			printf("���� ��Ʒ��� ��Ʒ���� �������� �ۼ�\n");
			printf("%4d %4d %8s %4d %4d\n",id1[i],id2[i],name[i],num[i],sale[i]);
		    printf("\n");
		    fclose(fp);
			if(i==(a-1))  return ;
		}
	}
	printf("û�и���Ʒ��Ϣ!\n");
	fclose(fp);

}
void sales_listing(SHOP stu[],int c,int b)//�����嵥
{
	FILE *fp=fopen("inventory.txt","r");
	int id1[20];//����
	int id2[20];//��Ʒ���
	char name[20][10];//��Ʒ����
	int num[20];//��Ʒ����
	int sale[20];//��Ʒ�ۼ�
	int i,a;
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&a);
	for(i=0;i<a;i++)
	{
		fscanf(fp,"%d",&id1[i]);
		fscanf(fp,"%d",&id2[i]);
		fscanf(fp,"%s",&name[i]);
		fscanf(fp,"%d",&num[i]);
		fscanf(fp,"%d",&sale[i]);
	}
	fclose(fp);
	if((fp=fopen("inventory.txt","w"))==NULL)
	{
		printf("failure to open it!\n");
	}
	fprintf(fp,"%d\n",a+1);
	for(i=0;i<a;i++)
	{
		fprintf(fp,"%d ",i+1);
		fprintf(fp,"%d ",id2[i]);
		fprintf(fp,"%s ",name[i]);
		fprintf(fp,"%d ",num[i]);
		fprintf(fp,"%d\n",sale[i]);
	}
	fprintf(fp,"%d ",i+1);
	fprintf(fp,"%d ",stu[c-1].id);
	fprintf(fp,"%s ",stu[c-1].name);
	fprintf(fp,"%d ",b);
	fprintf(fp,"%d\n",stu[c-1].sale);
	fclose(fp);
}

void Good_query()//������
{
 	int i;
	do{
		printf("1.�޸���Ʒ\n");
		printf("2.�����Ʒ\n");
		printf("3.ɾ����Ʒ\n");
		printf("4.��ѯ��Ʒ\n");
		printf("5.�˳�\n");
		printf("�������Ӧ���ܱ�ţ�\n");
		scanf("%d",&i);
		switch (i)
		{
		case 1:
			Addall_good();break;
		case 2:
			add_newgood();break;
		case 3:
			Delete_good();break; 
		case 4:
			Find_good();break;	
		default:
			return ;break;				
		}
		system("pause");//ϵͳ��ͣ 
		system("CLS");//���������Ŀ¼ 
	}while(i!=5);
	return ;
}

void Addall_good()//�޸���Ʒ��Ϣ 
{
	SHOP stu[30];
	char k[10];
	int id,m,n,i,pur,sale;
	FILE *fp=fopen("shop.txt","r");//����ָ����Ʒ��Ϣ���ļ� 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//���ļ��ж�ȡ��Ʒ��Ϣ 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%d",&stu[i].number);
		fscanf(fp,"%d",&stu[i].purchase);
		fscanf(fp,"%d",&stu[i].sale);
	}
	printf("��������Ҫ�޸ĵ���Ʒ��� ���� ���� ���� �ۼ�:\n");
	scanf("%d %s %d %d %d",&id,k,&m,&pur,&sale);
	for(i=0;i<n;i++)
	{
		if(id==stu[i].id)
		{
			fclose(fp);
			strcpy(stu[i].name,k);
			stu[i].number=m;
			stu[i].purchase=pur ;
			stu[i].sale=sale ;
			writeto_shopfile(stu,n);
			return ;
		}
	}
	printf("û�и���Ʒ!\n");
	fclose(fp);
	return;
}


void add_newgood()//�����µ���Ʒ 
{
	char k[10]; 
	SHOP stu[30];
	int id,m,n,i,pur,sale;
	FILE *fp=fopen("shop.txt","r");//����ָ����Ʒ��Ϣ���ļ� 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//���ļ��ж�ȡ��Ʒ��Ϣ 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%d",&stu[i].number);
		fscanf(fp,"%d",&stu[i].purchase);
		fscanf(fp,"%d",&stu[i].sale);
	}
	printf("��������Ҫ��ӵ���Ʒ���� ���� ���� �ۼ�:\n");//�����Ʒ 
	scanf("%s %d %d %d",k,&m,&pur,&sale);
	fclose(fp);
	stu[i].id=n+1;
	strcpy(stu[i].name,k);
	stu[i].number=m;
	stu[i].purchase=pur;
	stu[i].sale=sale;
	writeto_shopfile(stu,n+1);
	return ;
}

void Delete_good()//ɾ����Ʒ 
{
	SHOP stu[30];
	SHOP copy[30];
	int id,n,i,j,k=0;
	FILE *fp=fopen("shop.txt","r");//����ָ����Ʒ��Ϣ���ļ�
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//���ļ��ж�ȡ��Ʒ��Ϣ 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",stu[i].name);
		fscanf(fp,"%d",&stu[i].number);
		fscanf(fp,"%d",&stu[i].purchase);
		fscanf(fp,"%d",&stu[i].sale);
	}
	printf("��������Ҫɾ������Ʒ��ţ�\n");//ɾ����Ʒ���� 
	scanf("%d",&id);
	for(i=0,j=0;i<=n;i++,j++)
	{
		if(id==stu[i].id)
		{
			i++;k=1;
		}
		copy[j].id=j+1;
		strcpy(copy[j].name,stu[i].name);
		copy[j].number=stu[i].number;
		copy[j].purchase=stu[i].purchase;
		copy[j].sale=stu[i].sale;
	}
	if(k)
	{
		writeto_shopfile(copy,n-1);
		printf("ɾ���ɹ�!\n");
	}
	else
	{
		printf("û�и���Ʒ!\n");
	}
	fclose(fp);
	return ; 
} 
 
void clerk()//ְ������
{
 	int i;
	do{
		printf("1.�޸�ְԱ��Ϣ\n");
		printf("2.���ְԱ\n");
		printf("3.ɾ��ְԱ\n");
		printf("4.��ѯְԱ\n");
		printf("5.�˳�\n");
		printf("�������Ӧ���ܱ�ţ�\n");
		scanf("%d",&i);
		switch (i)
		{
		case 1:
			Correct_worker();break;
		case 2:
			Add_worker();break;
		case 3:
			Delete_worker();break; 
		case 4:
			Find_worker();break;	
		default:
			return ;break;				
		}
		system("pause");//ϵͳ��ͣ 
		system("CLS");//���ְ������Ŀ¼ 
	}while(i!=5);
	return ;
}

void Find_worker()//����ְԱ 
{
	CLERK stu[30];
	int id,n,i;
	FILE *fp=fopen("clerk.txt","r");//����ָ��ְ����Ϣ���ļ�
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//���ļ��ж�ȡְ����Ϣ 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].sex);
		fscanf(fp,"%s",&stu[i].idcard);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
	}
	printf("������ְԱ��ţ��磺01  :\n");//��ѯְ����Ϣ 
	scanf("%d",&id);
	for(i=0;i<n;i++)
	{
		if(id==stu[i].id)
		{
			printf("��� ���� �Ա� ʡ��֤ tel ��ַ\n");
			printf("%d %s %s %s %s %s\n",stu[i].id,stu[i].name,stu[i].sex,stu[i].idcard,stu[i].tel,stu[i].add );
		    printf("\n");
		    fclose(fp);
			return ;
		}
	}
	printf("û�и�ְԱ!\n");
	fclose(fp);
	return ;
}
 
void Add_worker()//���ְԱ 
{
	char k[10],s[10],idcard[10],tel[10],add[10]; 
	CLERK stu[30];
	int n,i;
	FILE *fp=fopen("clerk.txt","r");//����ָ��ְ����Ϣ���ļ� 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//���ļ��ж�ȡְ����Ϣ 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].sex);
		fscanf(fp,"%s",&stu[i].idcard);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
	}
	printf("��������Ҫ��ӵ�ְԱ���� �Ա� ���֤  tel  ��ַ:\n");//���ְ������ 
	scanf("%s %s %s %s %s",k,s,idcard,tel,add);
	fclose(fp);
	stu[i].id=n+1;
	strcpy(stu[i].name,k);
	strcpy(stu[i].sex,s);
	strcpy(stu[i].idcard,idcard);
	strcpy(stu[i].tel,tel);
	strcpy(stu[i].add,add);
	writeto_clerkfile(stu,n+1);
	return ;
} 

void Correct_worker()//�޸�ְԱ 
{
	char k[10],s[10],idcard[10],tel[10],add[10]; 
	CLERK stu[30];
	int n,i,id;
	FILE *fp=fopen("clerk.txt","r");//����ָ��ְ����ָ�� 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//���ļ��ж�ȡְ����Ϣ 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].sex);
		fscanf(fp,"%s",&stu[i].idcard);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
	}
	printf("��������Ҫ�޸ĵ�ְԱ��� ���� �Ա� ���֤  tel  ��ַ:\n");//�޸�ְ������ 
	scanf("%d %s %s %s %s %s",&id,k,s,idcard,tel,add);
	for(i=0;i<n;i++)
	{
		if(id==stu[i].id)
		{
			fclose(fp);
			strcpy(stu[i].name,k);
			strcpy(stu[i].sex,s);
			strcpy(stu[i].idcard,idcard);
			strcpy(stu[i].tel,tel);
			strcpy(stu[i].add,add);
			writeto_clerkfile(stu,n);
			printf("�޸ĳɹ�!\n");
			return ;
		}
	}
	printf("û�и�ְԱ!\n");
	fclose(fp);
	return;
} 

void Delete_worker()//ɾ��ְԱ 
{
	CLERK stu[30];
	CLERK copy[30];
	int id,n,i,j,k=0;
	FILE *fp=fopen("clerk.txt","r");//����ָ��ְ���ļ���ָ�� 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//���ļ��ж�ȡְ����Ϣ 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].sex);
		fscanf(fp,"%s",&stu[i].idcard);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
	}
	printf("��������Ҫɾ����ְԱ��ţ�\n");//ɾ��ְ������ 
	scanf("%d",&id);
	for(i=0,j=0;i<=n;i++,j++)
	{
		if(id==stu[i].id)
		{
			i++;k=1;
		}
		copy[j].id=j+1;
		strcpy(copy[j].name,stu[i].name);
		strcpy(copy[j].sex,stu[i].sex);
		strcpy(copy[j].idcard,stu[i].idcard);
		strcpy(copy[j].tel,stu[i].tel);
		strcpy(copy[j].add,stu[i].add);
	}
	if(k)
	{
		writeto_clerkfile(copy,n-1);
		printf("ɾ���ɹ�!\n");
	}
	else
	{
		printf("û�и�ְԱ!\n");
	}
	fclose(fp);
	return ; 
} 

void writeto_clerkfile(CLERK stu[],int a)//д��ְ���ļ�
{
	FILE *fp=fopen("clerk.txt","w");
	int i;
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fprintf(fp,"%d\n",a);
	for(i=0;i<a;i++)
	{
		fprintf(fp,"%d %s %s %s %s %s\n",stu[i].id,stu[i].name,stu[i].sex,stu[i].idcard,stu[i].tel,stu[i].add );
	}
	fclose(fp);
	printf("\n");
}

void supplier()//�����̹���
{
		int i;
	do{
		printf("1.�޸Ĺ�������Ϣ\n");
		printf("2.��ӹ�����\n");
		printf("3.ɾ��������\n");
		printf("4.��ѯ������\n");
		printf("5.�˳�\n");
		printf("�������Ӧ���ܱ�ţ�\n");
		scanf("%d",&i);
		switch (i)
		{
		case 1:
			Correct_supply();break;
		case 2:
			Add_supply();break;
		case 3:
			Delete_supply();break; 
		case 4:
			Find_supply();break;	
		default:
			return ;break;				
		}
		system("pause");//ϵͳ��ͣ 
		system("CLS");//��������̹���Ŀ¼ 
	}while(i!=5);
	return ;
} 
 
void Add_supply()//��ӹ�����
{
	char name[10],tel[10],add[10]; 
	SUPPLY stu[30];
	int n,i,k,p;
	FILE *fp=fopen("supply.txt","r");//����ָ�򹩻����ļ���ָ�� 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//���ļ��ж�ȡ��������Ϣ 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id1);
		fscanf(fp,"%d",&stu[i].id2);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
		fscanf(fp,"%d",&stu[i].prince);
	}
	printf("��������Ҫ��ӵĹ�������Ʒ��   ����   �绰   ��ַ   �۸�\n");//��ӹ�������Ϣ���� 
	scanf("%d %s %s %s %d",&k,name,tel,add,&p);
	fclose(fp);
	stu[i].id1=n+1;
	stu[i].id2=k;
	strcpy(stu[i].name,name);
	strcpy(stu[i].tel,tel);
	strcpy(stu[i].add,add);
	stu[i].prince=p;
	writeto_supplyfile(stu,n+1);
	return ;
} 

void Correct_supply()//�޸Ĺ�����
{
	char name[10],tel[10],add[10]; 
	SUPPLY stu[30];
	int n,i,k,p,id;
	FILE *fp=fopen("supply.txt","r");//����ָ�򹩻����ļ���ָ�� 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//���ļ��ж�ȡ��������Ϣ 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id1);
		fscanf(fp,"%d",&stu[i].id2);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
		fscanf(fp,"%d",&stu[i].prince);
	}
	printf("��������Ҫ�޸ĵĹ����̱�� ��Ʒ��   ����   �绰   ��ַ   �۸�\n");//�޸Ĺ�������Ϣ���� 
	scanf("%d %d %s %s %s %d",&id,&k,name,tel,add,&p);
	for(i=0;i<n;i++)
	{
		if(id==stu[i].id1)
		{
			fclose(fp);
			stu[i].id2=k;
			strcpy(stu[i].name,name);
			strcpy(stu[i].tel,tel);
			strcpy(stu[i].add,add);
			stu[i].prince=p;
			writeto_supplyfile(stu,n);
			printf("�޸ĳɹ�!\n");
			return ;
		}
	}
	printf("û�иù�����!\n");
	fclose(fp);
	return;
} 

void Delete_supply()//ɾ��������
{
	SUPPLY stu[30];
	SUPPLY copy[30];
	int id,n,i,j,k=0;
	FILE *fp=fopen("supply.txt","r");//����ָ�򹩻����ļ���ָ�� 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//���ļ��ж�ȡ��������Ϣ 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id1);
		fscanf(fp,"%d",&stu[i].id2);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
		fscanf(fp,"%d",&stu[i].prince);
	}
	printf("��������Ҫɾ���Ĺ����̱�ţ�\n");//ɾ����������Ϣ���� 
	scanf("%d",&id);
	for(i=0,j=0;i<=n;i++,j++)
	{
		if(id==stu[i].id1)
		{
			i++;k=1;
		}
		copy[j].id1=j+1;
		copy[j].id2=stu[i].id2;
		strcpy(copy[j].name,stu[i].name);
		strcpy(copy[j].tel,stu[i].tel);
		strcpy(copy[j].add,stu[i].add);
		copy[j].prince=stu[i].prince;
	}
	if(k)
	{
		writeto_supplyfile(copy,n-1);
		printf("ɾ���ɹ�!\n");
	}
	else
	{
		printf("û�иù�����!\n");
	}
	fclose(fp);
	return ; 
} 

void writeto_supplyfile(SUPPLY stu[],int a)//д�빩�����ļ�
{
	FILE *fp=fopen("supply.txt","w");
	int i;
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fprintf(fp,"%d\n",a);
	for(i=0;i<a;i++)
	{
		fprintf(fp,"%d %d %s %s %s %d\n",stu[i].id1,stu[i].id2,stu[i].name,stu[i].tel,stu[i].add,stu[i].prince);
	}
	fclose(fp);
	printf("\n");
}
