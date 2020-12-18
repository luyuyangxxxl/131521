#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"finalresult.h"
void main()
{
	int m,flag=1;
	while(flag)
	{
		printf("%33s\n","                宿舍管理系统");
		printf("--------------------------------------------------------------------------------\n");
		printf("\t\t0-------------创建一个文件夹\n");
		printf("\t\t1-------------切换到旧的文件夹\n");
		printf("\t\t2-------------添加学生信息\n");
		printf("\t\t3------------ 以学号搜索\n");
		printf("\t\t4------------ 以房间号搜索\n");
		printf("\t\t5-------------修改数据\n");
		printf("\t\t6-------------删除学生信息\n");
		printf("\t\t7------------ 以姓名搜索\n");
		printf("\t\t8-------------输出所有学生信息（以学号的先后顺序）\n");
		printf("\t\t9-------------退出\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("\t 选择(0-----------9)以操作\n");
		scanf("%d",&m);
		switch(m)
		{ case 0:creat(); break;
			case 1:readfile(); break;
			case 2:insert();   break;
			case 3:search2();  break;
			case 4:search3();  break;
			case 5:reload();   break;
			case 6: deleted(); break;
			case 7:search1();  break;
			case 8:output();   break;
			case 9:exit(0);
		}
	}
}
