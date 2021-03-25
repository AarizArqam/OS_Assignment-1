#include<stdio.h>
//#include<conio.h>
#include<string.h>
//#include<iostream>

int main(int argc,char *argv[])
{
int size1, size2;
int maincounter=0;
int ii=0,j=0,replica;
char a[50];//="ss",
char str[50];
FILE *point;
char name[20];
strcpy(a,argv[2]);
//scanf("%s",name);
strcpy(name,argv[1]);
point=fopen(name,"r");
if(point==NULL)
{
printf("file not open error");
}
else{
fgets(str,50,point);
//printf("%s",str);
//printf("\nEnter your string\n");
//scanf("%s",a);
size1=strlen(a);
size2=strlen(str);
for(ii=0;ii<size2;++ii)
{
for(j=0,replica=ii;j<size1&&a[j]==str[replica];j++,replica++){}
if(j==size1)
{
maincounter++;
}
}
}
printf("\nNumber of accurance = %d",maincounter);
//getch();
return 0;

}