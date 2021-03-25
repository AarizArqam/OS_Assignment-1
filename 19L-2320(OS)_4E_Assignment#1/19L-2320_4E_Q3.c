#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,const char *argv[])
{
	FILE *filepointer;
	FILE *filepointer2;
	char buffer[50]={'\0'};
	char buffer2[50]={'\0'};
	char buffer3[50]={'\0'};
	int i,endofworld,startofworld;
	int h=0;
	char swaper;
	filepointer=fopen(argv[1],"r");
	filepointer2=fopen("text2.txt","w");
	if(filepointer==NULL)
	{
		printf("Filed did'nt open");

	}
	else{
		while(fgets(buffer,50,filepointer)!=NULL)
		{
			int j=0,k=0;
			for(i=0;i<50;i++)
			{
				if((int)buffer[i]!=32&&(int)buffer[i]!=0)
				{
					buffer3[j]=buffer[i];
					j++;
				}
				else
				{
					//buffer2[k++]=' ';
					j--;
					endofworld=j;
					startofworld=0;
					for(startofworld=0;startofworld<=j/2;)
					{
						if(buffer3[startofworld]!='A'&&buffer3[startofworld]!='a'&&buffer3[startofworld]!='e'&&buffer3[startofworld]!='E'&&buffer3[startofworld]!='i'&&buffer3[startofworld]!='I'&&buffer3[startofworld]!='O'&&buffer3[startofworld]!='o'&&buffer3[startofworld]!='U'&&buffer3[startofworld]!='u')
						{
							if(buffer3[endofworld]!='A'&&buffer3[endofworld]!='a'&&buffer3[endofworld]!='e'&&buffer3[endofworld]!='E'&&buffer3[endofworld]!='i'&&buffer3[endofworld]!='I'&&buffer3[endofworld]!='O'&&buffer3[endofworld]!='o'&&buffer3[endofworld]!='U'&&buffer3[endofworld]!='u')
							{
								swaper=buffer3[endofworld];
								buffer3[endofworld]=buffer3[startofworld];
								buffer3[startofworld]=swaper;
							startofworld++;
								endofworld--;
							}
							else{
								endofworld--;
							}
						}
						else{
							startofworld++;
						}
					}
					h=0;
					for(;j>=0;j--,h++)
					{
						buffer2[k++]=buffer3[h];
					}
					j++;
					//buffer3[0]='\0';
				}
			}
			//printf("%s",buffer2);
			fputs(buffer2,filepointer2);
		}
	}
	remove(argv[1]);
	rename("text2.txt",argv[1]);
	
	fclose(filepointer);
	fclose(filepointer2);
	//getch();
	return 0;
}