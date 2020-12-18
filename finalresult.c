#include"finalresult.h"
void creat()
{
	personnode *person;
	person=(personnode *)malloc(sizeof(personnode));
	printf("\n 请输入文件名:\n");
	scanf("%s",filename);
	if((fp=fopen(filename,"w+"))==NULL)
	{
		printf("\n 找不到文件");
		exit(0);
	}

	printf("\n 请输入姓名 学号 房间号用#结束用空格隔开 \n");
	scanf("%s",person->name);
	while(strcmp(person->name,"#"))
	{
		scanf("%s %s",person->xh,person->fh);

		fprintf(fp,"%-10s%-20s%-50s\n",person->name,person->xh,person->fh);
		scanf("%s",person->name);
	}
	fclose(fp);
}
void readfile()
{printf("\n 请输入文件名:\n");
	scanf("%s",filename);
	if((fp=fopen(filename,"r+"))==NULL)
	{
		printf("\n 找不到文件:\n");
		exit(0);
	}
	fclose(fp);
}

void  output()
{
	personnode *person;
	long offset1,offset2;
	char name1[8],name2[8],name3[8];
	char xh1[16],xh2[16],xh3[16];
	char fh1[30],fh2[30],fh3[30];
	person=(personnode *)malloc(sizeof(personnode));
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("\n 打不开文件");
		exit(0);
	}
	while(!feof(fp))
	{
		int a,b,c,d;

		if((fp=fopen(filename,"r+"))==NULL)
		{
			printf("\n 打不开文件");
			exit(0);
		}
		while(!feof(fp))
		{

			while(!feof(fp))
			{
				offset1=ftell(fp);
				fscanf(fp,"%s%s%s\n",person->name,person->xh,person->fh);

				strcpy(name1,person->name);
				strcpy (xh1,person->xh);
				strcpy(fh1,person->fh);
				if(feof(fp))   break;
				offset2=ftell(fp);
				fscanf(fp,"%s%s%s\n",person->name,person->xh,person->fh);
				strcpy (name2,person->name);
				strcpy(xh2,person->xh);
				strcpy(fh2,person->fh);
				b=strlen(xh1);
				c=strlen(xh2);
				d=strcmp(xh1,xh2);
				if(b==c&&d>0)
				{
					strcpy(name3,name1);
					strcpy(name1,name2);
					strcpy(name2,name3);
					strcpy(xh3,xh1);
					strcpy(xh1,xh2);
					strcpy(xh2,xh3);
					strcpy(fh3,fh1);
					strcpy(fh1,fh2);
					strcpy(fh2,fh3);

					fseek(fp,offset1,SEEK_SET);
					strcpy(person->name,name1);
					strcpy(person->xh,xh1);
					strcpy(person->fh,fh1);
					fprintf(fp,"%-10s%-20s%-50s\n",person->name,person->xh,person->fh);

					strcpy(person->name,name2);
					strcpy(person->xh,xh2);
					strcpy( person->fh,fh2);
					fprintf(fp,"%-10s%-20s%-50s\n",person->name,person->xh,person->fh);

				}
				fseek(fp,offset2,SEEK_SET);
			}
			rewind(fp);
			while(!feof(fp))
			{
				offset1=ftell(fp);
				fscanf(fp,"%s%s%s\n",person->name,person->xh,person->fh);
				strcpy (xh1,person->xh);
				if(feof(fp)) {a=1; break;}
				offset2=ftell(fp);
				fscanf(fp,"%s%s%s\n",person->name,person->xh,person->fh);
				strcpy(xh2,person->xh);
				b=strlen(xh1);
				c=strlen(xh2);
				d=strcmp(xh1,xh2);

				if(b==c&&d<=0) a=1;
				else{ a=0;
					break;}

				fseek(fp,offset2,SEEK_SET);
			}

			if(a) break;
			rewind(fp);
		}
		if(a) break;
	}
	rewind(fp);

	printf("\n******************************************************************\n");
	printf("%35s\n","thefile(thefile hava printf as studentnumber)");
	printf("%-10s%-20s%-50s\n","姓名","学号","房间号");
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s\n",person->name,person->xh,person->fh);
		printf("%-10s%-20s%-50s\n",person->name,person->xh,person->fh);
	}

	fclose(fp);
	printf("*******************************************************************\n\n");
}


void  insert()
{
	personnode *person;
	person=(personnode *)malloc(sizeof(personnode));
	if((fp=fopen(filename,"a"))==NULL)
	{
		printf("\n can't open the file");
		exit(0);
	}
	printf("\n 请输入姓名 学号和房间号 \n");
	scanf("%s %s %s",person->name,person->xh,person->fh);
	fprintf(fp,"%-10s%-20s%-50s\n",person->name,person->xh,person->fh);
	fclose(fp);
}


void search1()
{
	int k=0;
	char namekey[8];
	personnode *person;
	person=(personnode *)malloc(sizeof(personnode));
	printf("\n 输入学生的姓名 :");
	scanf("%s",namekey);
	if((fp=fopen(filename,"rb"))==NULL)//读取打开一个2进制w文件只允许读取
	{
		printf("\n 不能打开文件");
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %s\n",person->name,person->xh,person->fh);// %s会跳过前面的空白符 但是不会跳过后面的空白符 fscanf用于读取文件流的数据
		if(!strcmp(namekey,person->name))//比较字符串
		{
			printf("\n\n have serched,the courrent is:");
			printf("%-10s%-20s%-50s\n",person->name,person->xh,person->fh);
			k=1;
		}
	}
	if(!k) printf("\n\n sorry,there is not the current of thiss people \n");
	fclose(fp);
}


void search2()
{
	int k=0;
	char xhkey[16];
	personnode *person;
	person=(personnode *)malloc(sizeof(personnode));
	printf("\n s输入学号");
	scanf("%s",xhkey);
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("\n 打不开文件 ");
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %s\n",person->name,person->xh,person->fh);
		if(!strcmp(xhkey,person->xh))
		{
			printf("\n\n 找到：");
			printf("%-10s%-20s%-50s\n",person->name,person->xh,person->fh);
			k=1;
		}
	}
	if(!k) printf("\n\n sorry 找不到 \n");
	fclose(fp);
}


void search3()
{
	int k=0;
	char fhkey[30];
	personnode *person;
	person=(personnode *)malloc(sizeof(personnode));
	printf("\n 请输入房间号:");
	scanf("%s",fhkey);
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("\n can't open thefile");
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %s\n",person->name,person->xh,person->fh);
		if(!strcmp(fhkey,person->fh))
		{
			printf("\n\n have got it,the current is:");
			printf("%-10s%-20s%-50s\n",person->name,person->xh,person->fh);
			k=1;
		}
	}
	if(!k) printf("\n\n 找不到\n");
	fclose(fp);
}


void reload()
{
	int k=0;
	long offset;
	char namekey[8];
	personnode *person;
	person=(personnode *)malloc(sizeof(personnode));
	printf("\n 输入你想修改学生的学号 :");
	scanf("%s",namekey);
	if((fp=fopen(filename,"r+"))==NULL)
	{
		printf("\n 打不开");
		exit(0);
	}
	while(!feof(fp))
	{
		offset=ftell(fp);
		fscanf(fp,"%s %s %s\n",person->name,person->xh,person->fh);
		if(!strcmp(namekey,person->name))
		{
			k=1;
			break;
		}
	}
	if(k)
	{
		printf("\n hava got it,the current is：");
		printf("%-10s%-20s%-50s\n",person->name,person->xh,person->fh);
		printf("\n 请输入新的学生名称 学号 和房间号 ：");
		scanf("%s %s %s",person->name,person->xh,person->fh);
		fseek(fp,offset,SEEK_SET);
		fprintf(fp,"%-10s%-20s%-50s\n",person->name,person->xh,person->fh);
	}
	else printf("\n 找不到\n");
	fclose(fp);
}


void deleted()
{
	int k=0;
	char m;
	long offset;
	char namekey[8];
	personnode *person;
	person=(personnode *)malloc(sizeof(personnode));
	printf("\n 请输入你想x删除的学生名称 :\n");
	scanf("%s",namekey);
	if((fp=fopen(filename,"r+"))==NULL)
	{
		printf("\n 找不到文件夹 ");
		exit(0);
	}
	while(!feof(fp))
	{
		offset=ftell(fp);
		fscanf(fp,"%s%s%s\n",person->name,person->xh,person->fh);
		if(!strcmp(namekey,person->name))
		{
			k=1;
			break;
		}
	}
	if(k)
	{
		printf("\n 找到:\n");
		printf("%-10s%-20s%-50s\n",person->name,person->xh,person->fh);
		printf("\n  are you sure to delete it?y/n?");
		scanf("%s",&m);
		if(m=='y')
		{
			fseek(fp,offset,SEEK_SET);
			fprintf(fp,"%-10s%-20s%-50s\n","","","");
		}
		else rewind(fp);

	}

	else printf("\n 找不到 \n");
	fclose(fp);
}


