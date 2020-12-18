#ifndef finalresult_h
#define finalresult_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct personnode
{
	 char name [8];
	  char xh[16];
	   char fh[30];
	   	}personnode;
char filename[20];
FILE *fp;
void creat();
void readfile();
void  output();
void  insert();
void search1();
void search2();
void search3();
void reload();
void deleted();

#endif
