#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int registe();//用户登录函数/ 
void adminiratostr();//管理员管理函数/
void sale_management();//销售管理/
void Good_query();//库存管理
void supplier();//供货商管理
void Stock_query();//进货管理/
void clerk();//职工管理

void correct_user(int a);//修改用户名
void correct_key(int a);//修改密码

void Find_supply();//查找供货商 
void Add_good();//进货 

void Correct_good();//库存修改,,商品减少
void sale_inventory();//销售盘点

void Find_good();//查找库存 
void Delete_good();//删除商品 
void Addall_good();//修改商品 
void add_newgood();//增加新的商品 

void Find_worker();//查找职员 
void Add_worker();//添加职员 
void Correct_worker();//修改职员 
void Delete_worker();//删除职员

void Delete_supply();//删除供货商 
void Find_supply();//查找供货商 
void Correct_supply();//修改供货商 
void Add_supply();//添加供货商 

typedef struct clerk//职工信息
{
	int id;
	char name[10];
	char sex[5];
	char idcard[18];
	char tel[15];
	char add[20];
} CLERK;

typedef struct manage//管理员信息
{
	char user[20];
	char key[20];
}MANAGE;

typedef struct supply//供货商信息
{
	int id1;
	int id2;//商品编号
	char name[10];
	char tel[20];
	char add[20];
	int prince;
}SUPPLY;

typedef struct shop//商品信息
{
	int id;
	char name[10];
	int number;
	int purchase;
	int sale;
}SHOP;

void writeto_shopfile(SHOP stu[],int a);//写入商品文件
void writeto_clerkfile(CLERK stu[],int a);//写入职工文件
void writeto_supplyfile(SUPPLY stu[],int a);//写入供货商文件
void sales_listing(SHOP stu[],int c,int b);//写入销售清单

int main()
{
	int i,j;
	printf("**********************************************\n");
	printf("************欢迎进入超市管理系统**************\n");
	printf("**********************************************\n");
	j=registe();
	system("CLS");//清除登录界面
	do{
		printf("1.管理员管理\n");
		printf("2.进货管理\n");
		printf("3.销售管理\n");
		printf("4.库存管理\n");
		printf("5.供货商管理\n");
		printf("6.职工管理\n");
		printf("7.退出系统\n");
		printf("请输入对应功能编号:");
		scanf("%d",&i);
		getchar();
		system("CLS");//清除一级菜单目录
		switch (i)//通过switch语句达到选择的作用，每次可以选择不同的功能
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
	}while(i!=7);//当输入不为7，一直循环主菜单 
	return 0;
}

int registe()//用户登录函数
{
	MANAGE stu[10];
	FILE *fp=fopen("user.txt","r");//定义指向管理员文件的指针
	int i=0,j=0;
	int n,m; 
	char u[20],k[20];
	if(fp==NULL)//判断文件是否打开成功
	{
		printf("failure to open user.txt! \n");
		exit(0)	;
	}
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++) 
	{
		fscanf(fp,"%s\t%s",stu[i].user,stu[i].key);//文件读取函数
	}
	do{
		printf("用户名: ");
		gets(u);
		printf("密码: ");
		gets(k);
		j++;
		for(m=0;m<n;m++)
		{
			if(strcmp(stu[m].user,u)==0&&strcmp(stu[m].key,k)==0)
			{
				printf("登录成功!\n");
				fclose(fp); 
				return m;//用户名，密码正确，返回主函数
			}
		}
		printf("请重新输入\n");
	}while(j<3);//用户有三次输入密码的机会，否则退出
	fclose(fp); 
	exit(0);
}

void adminiratostr()//管理员管理函数
{
	int i,j;
	j=registe();//用户登录函数
	system("CLS");
	do{
		printf("1.修改用户名\n");
		printf("2.修改密码\n");
		printf("3.退出\n");
		printf("请输入对应功能编号:");
		scanf("%d",&i);
		getchar();//清除缓冲区转行字符 
		switch (i)
		{
		case 1:
			correct_user(j);break;
		case 2:
			correct_key(j);break;
		default:
			return ;break;				
		}
		system("pause");//系统暂停 
		system("CLS");//清除管理员管理目录
	}while(i!=3);
	return ;
}

void correct_user(int a)//修改用户名
{
	MANAGE stu[10];
	char w[20]; 
	int n,i; 
	FILE *fp;//定义指向管理员文件的指针
	if((fp=fopen("user.txt","r"))==NULL)//判断文件是否打开成功
	{
		printf("failure to open user.txt\n");
		exit(0);
	}
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++) 
	{
		fscanf(fp,"%s\t%s",stu[i].user,stu[i].key);//文件读取函数
	}
	fclose(fp);
	if((fp=fopen("user.txt","w"))==NULL)//判断文件是否打开成功
	{
		printf("failure to open user.txt\n");
		exit(0);
	} 
	printf("请输入新的用户名：");
	gets(w);
	fprintf(fp,"%d\n",n); 
	for(i=0;i<n;i++)
	{
		if(i==a)
		{
			fprintf(fp,"%s %s\n",w,stu[i].key);
			continue ; 
		} 
		fprintf(fp,"%s %s\n",stu[i].user,stu[i].key);//将新的用户名和原来的密码写入文件，
	}
	fclose(fp);
	printf("chanage to the success!\n");
	return ;	
}

void correct_key(int a)//修改密码 
{
	MANAGE stu[10];
	char w[20]; 
	int n,i; 
	FILE *fp;//定义指向管理员文件的指针
	if((fp=fopen("user.txt","r"))==NULL)//判断文件是否打开成功
	{
		printf("failure to open user.txt\n");
		exit(0);
	}
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++) 
	{
		fscanf(fp,"%s\t%s",stu[i].user,stu[i].key);//文件读取函数
	}
	fclose(fp);
	if((fp=fopen("user.txt","w"))==NULL)//判断文件是否打开成功
	{
		printf("failure to open user.txt\n");
		exit(0);
	} 
	printf("请输入新的密码：");
	gets(w);
	fprintf(fp,"%d\n",n); 
	for(i=0;i<n;i++)
	{
		if(i==a)
		{
			fprintf(fp,"%s %s\n",stu[i].user,w);
			continue ;
		} 
		fprintf(fp,"%s %s\n",stu[i].user,stu[i].key);//将新的用户名和原来的密码写入文件，
	}
	fclose(fp);
	printf("chanage to the success!\n");
	return ;
}

void Stock_query()//进货管理
{
	int i;
	do{
		printf("1.查找库存\n");
		printf("2.查找供货商\n");
		printf("3.进货\n") ; 
		printf("4.退出\n");
		printf("请输入对应功能编号:");
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
		system("pause");//系统暂停 
		system("CLS");//清除进货管理目录 
	}while(i!=4);
	return ;	
}

void Find_good()//查找商品
{
	SHOP stu[30];
	int id,n,i;
	FILE *fp=fopen("shop.txt","r"); //定义指向商品文件的指针
	if(fp==NULL)//判断文件是否打开成功
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);  //从文件中读取商品信息 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%d",&stu[i].number);
		fscanf(fp,"%d",&stu[i].purchase);
		fscanf(fp,"%d",&stu[i].sale);
	}
	printf("请输入商品编号，如：01  :\n");//打印对应的商品信息 
	scanf("%d",&id);
	for(i=0;i<n;i++)
	{
		if(id==stu[i].id)
		{
			printf("编号 名称 数量 进价 售价\n");
			printf("%4d %4s %4d %4d %4d\n",stu[i].id,stu[i].name,stu[i].number,stu[i].purchase,stu[i].sale);
		    printf("\n");
		    fclose(fp);
			return ;
		}
	}
	printf("没有该商品!\n");
	fclose(fp);
	return ;
}


void Find_supply()//查找供货商
{
	SUPPLY stu[30];
	int id,n,i;
	FILE *fp=fopen("supply.txt","r");//定义指向供货商文件的指针
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//从文件中读取供货商信息 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id1);
		fscanf(fp,"%d",&stu[i].id2);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
		fscanf(fp,"%d",&stu[i].prince);
	}
	printf("请输入商家编号，如：01  :\n");//打印对应的供货商信息信息 
	scanf("%d",&id);
	for(i=0;i<n;i++)
	{
		if(id==stu[i].id1)
		{
			printf("编号 商品号   名称   电话   地址   价格\n");
			printf("%4d %4d %4s %4s %4s %4d\n",stu[i].id1,stu[i].id2,stu[i].name,stu[i].tel,stu[i].add,stu[i].prince);
		    printf("\n");
		    fclose(fp);
			return ;
		}
	}
	printf("没有该商家!\n");
	fclose(fp);
	return ;
}

void Add_good()//添加商品操作
{
	SHOP stu[30];
	int id,m,n,i;
	FILE *fp=fopen("shop.txt","r");//定义指向商品文件的指针
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//从文件中读取商品信息 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%d",&stu[i].number);
		fscanf(fp,"%d",&stu[i].purchase);
		fscanf(fp,"%d",&stu[i].sale);
	}
	printf("请输入你要添加的商品编号 数量:\n");//向结构体中输入添加商品的信息 
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
	printf("没有该商品!\n");
	fclose(fp);
	return;
}

void writeto_shopfile(SHOP stu[],int a)//写入文件操作
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

void sale_management()//销售管理
{
	int i;
	do{
		printf("1.查看库存\n");
		printf("2.销售商品\n");
		printf("3.销售盘点\n");
		printf("4.退出\n");
		printf("请输入你需要的功能：\n");
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
		system("pause"); //系统暂停 
		system("CLS");//清除销售管理目录 
	}while(i!=4);
	
}

void Correct_good()//库存修改,,商品减少 
{
 	SHOP stu[30];
	int id,m,n,i;
	FILE *fp=fopen("shop.txt","r");//定义指向商品文件的指针 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//从文件中读取商品信息 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%d",&stu[i].number);
		fscanf(fp,"%d",&stu[i].purchase);
		fscanf(fp,"%d",&stu[i].sale);
	}
	printf("请输入你要销售的商品编号 数量:\n"); //销售商品 
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
	printf("没有该商品!\n");
	fclose(fp);
	return;
 	
}

void sale_inventory()//销售盘点
{
	FILE *fp=fopen("inventory.txt","r");
	int id1[20];//单号
	int id2[20];//商品编号
	char name[20][10];//商品名称
	int num[20];//商品数量
	int sale[20];//商品售价
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
	printf("请输入你要查询的商品编号: \n");
	scanf("%d",&id);
	for(i=0;i<a;i++)
	{
		if(id==id2[i])
		{
			printf("单号 商品编号 商品名称 销售数量 售价\n");
			printf("%4d %4d %8s %4d %4d\n",id1[i],id2[i],name[i],num[i],sale[i]);
		    printf("\n");
		    fclose(fp);
			if(i==(a-1))  return ;
		}
	}
	printf("没有该商品信息!\n");
	fclose(fp);

}
void sales_listing(SHOP stu[],int c,int b)//销售清单
{
	FILE *fp=fopen("inventory.txt","r");
	int id1[20];//单号
	int id2[20];//商品编号
	char name[20][10];//商品名称
	int num[20];//商品数量
	int sale[20];//商品售价
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

void Good_query()//库存管理
{
 	int i;
	do{
		printf("1.修改商品\n");
		printf("2.添加商品\n");
		printf("3.删除商品\n");
		printf("4.查询商品\n");
		printf("5.退出\n");
		printf("请输入对应功能编号：\n");
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
		system("pause");//系统暂停 
		system("CLS");//清除库存管理目录 
	}while(i!=5);
	return ;
}

void Addall_good()//修改商品信息 
{
	SHOP stu[30];
	char k[10];
	int id,m,n,i,pur,sale;
	FILE *fp=fopen("shop.txt","r");//定义指向商品信息的文件 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//从文件中读取商品信息 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%d",&stu[i].number);
		fscanf(fp,"%d",&stu[i].purchase);
		fscanf(fp,"%d",&stu[i].sale);
	}
	printf("请输入你要修改的商品编号 名称 数量 进价 售价:\n");
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
	printf("没有该商品!\n");
	fclose(fp);
	return;
}


void add_newgood()//增加新的商品 
{
	char k[10]; 
	SHOP stu[30];
	int id,m,n,i,pur,sale;
	FILE *fp=fopen("shop.txt","r");//定义指向商品信息的文件 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//从文件中读取商品信息 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%d",&stu[i].number);
		fscanf(fp,"%d",&stu[i].purchase);
		fscanf(fp,"%d",&stu[i].sale);
	}
	printf("请输入你要添加的商品名称 数量 进价 售价:\n");//添加商品 
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

void Delete_good()//删除商品 
{
	SHOP stu[30];
	SHOP copy[30];
	int id,n,i,j,k=0;
	FILE *fp=fopen("shop.txt","r");//定义指向商品信息的文件
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//从文件中读取商品信息 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",stu[i].name);
		fscanf(fp,"%d",&stu[i].number);
		fscanf(fp,"%d",&stu[i].purchase);
		fscanf(fp,"%d",&stu[i].sale);
	}
	printf("请输入你要删除的商品编号：\n");//删除商品操作 
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
		printf("删除成功!\n");
	}
	else
	{
		printf("没有该商品!\n");
	}
	fclose(fp);
	return ; 
} 
 
void clerk()//职工管理
{
 	int i;
	do{
		printf("1.修改职员信息\n");
		printf("2.添加职员\n");
		printf("3.删除职员\n");
		printf("4.查询职员\n");
		printf("5.退出\n");
		printf("请输入对应功能编号：\n");
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
		system("pause");//系统暂停 
		system("CLS");//清除职工管理目录 
	}while(i!=5);
	return ;
}

void Find_worker()//查找职员 
{
	CLERK stu[30];
	int id,n,i;
	FILE *fp=fopen("clerk.txt","r");//定义指向职工信息的文件
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//从文件中读取职工信息 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].sex);
		fscanf(fp,"%s",&stu[i].idcard);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
	}
	printf("请输入职员编号，如：01  :\n");//查询职工信息 
	scanf("%d",&id);
	for(i=0;i<n;i++)
	{
		if(id==stu[i].id)
		{
			printf("编号 名称 性别 省份证 tel 地址\n");
			printf("%d %s %s %s %s %s\n",stu[i].id,stu[i].name,stu[i].sex,stu[i].idcard,stu[i].tel,stu[i].add );
		    printf("\n");
		    fclose(fp);
			return ;
		}
	}
	printf("没有该职员!\n");
	fclose(fp);
	return ;
}
 
void Add_worker()//添加职员 
{
	char k[10],s[10],idcard[10],tel[10],add[10]; 
	CLERK stu[30];
	int n,i;
	FILE *fp=fopen("clerk.txt","r");//定义指向职工信息的文件 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//从文件中读取职工信息 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].sex);
		fscanf(fp,"%s",&stu[i].idcard);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
	}
	printf("请输入你要添加的职员名称 性别 身份证  tel  地址:\n");//添加职工操作 
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

void Correct_worker()//修改职员 
{
	char k[10],s[10],idcard[10],tel[10],add[10]; 
	CLERK stu[30];
	int n,i,id;
	FILE *fp=fopen("clerk.txt","r");//定义指向职工的指针 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//从文件中读取职工信息 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].sex);
		fscanf(fp,"%s",&stu[i].idcard);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
	}
	printf("请输入你要修改的职员编号 名称 性别 身份证  tel  地址:\n");//修改职工操作 
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
			printf("修改成功!\n");
			return ;
		}
	}
	printf("没有该职员!\n");
	fclose(fp);
	return;
} 

void Delete_worker()//删除职员 
{
	CLERK stu[30];
	CLERK copy[30];
	int id,n,i,j,k=0;
	FILE *fp=fopen("clerk.txt","r");//定义指向职工文件的指针 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//从文件中读取职工信息 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].sex);
		fscanf(fp,"%s",&stu[i].idcard);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
	}
	printf("请输入你要删除的职员编号：\n");//删除职工操作 
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
		printf("删除成功!\n");
	}
	else
	{
		printf("没有该职员!\n");
	}
	fclose(fp);
	return ; 
} 

void writeto_clerkfile(CLERK stu[],int a)//写入职工文件
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

void supplier()//供货商管理
{
		int i;
	do{
		printf("1.修改供货商信息\n");
		printf("2.添加供货商\n");
		printf("3.删除供货商\n");
		printf("4.查询供货商\n");
		printf("5.退出\n");
		printf("请输入对应功能编号：\n");
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
		system("pause");//系统暂停 
		system("CLS");//清除供货商管理目录 
	}while(i!=5);
	return ;
} 
 
void Add_supply()//添加供货商
{
	char name[10],tel[10],add[10]; 
	SUPPLY stu[30];
	int n,i,k,p;
	FILE *fp=fopen("supply.txt","r");//定义指向供货商文件的指针 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//从文件中读取供货商信息 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id1);
		fscanf(fp,"%d",&stu[i].id2);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
		fscanf(fp,"%d",&stu[i].prince);
	}
	printf("请输入你要添加的供货商商品号   名称   电话   地址   价格：\n");//添加供货商信息操作 
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

void Correct_supply()//修改供货商
{
	char name[10],tel[10],add[10]; 
	SUPPLY stu[30];
	int n,i,k,p,id;
	FILE *fp=fopen("supply.txt","r");//定义指向供货商文件的指针 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//从文件中读取供货商信息 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id1);
		fscanf(fp,"%d",&stu[i].id2);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
		fscanf(fp,"%d",&stu[i].prince);
	}
	printf("请输入你要修改的供货商编号 商品号   名称   电话   地址   价格：\n");//修改供货商信息操作 
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
			printf("修改成功!\n");
			return ;
		}
	}
	printf("没有该供货商!\n");
	fclose(fp);
	return;
} 

void Delete_supply()//删除供货商
{
	SUPPLY stu[30];
	SUPPLY copy[30];
	int id,n,i,j,k=0;
	FILE *fp=fopen("supply.txt","r");//定义指向供货商文件的指针 
	if(fp==NULL)
	{
		printf("failure to open it!\n");
	}
	fscanf(fp,"%d",&n);//从文件中读取供货商信息 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&stu[i].id1);
		fscanf(fp,"%d",&stu[i].id2);
		fscanf(fp,"%s",&stu[i].name);
		fscanf(fp,"%s",&stu[i].tel);
		fscanf(fp,"%s",&stu[i].add);
		fscanf(fp,"%d",&stu[i].prince);
	}
	printf("请输入你要删除的供货商编号：\n");//删除供货商信息操作 
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
		printf("删除成功!\n");
	}
	else
	{
		printf("没有该供货商!\n");
	}
	fclose(fp);
	return ; 
} 

void writeto_supplyfile(SUPPLY stu[],int a)//写入供货商文件
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
