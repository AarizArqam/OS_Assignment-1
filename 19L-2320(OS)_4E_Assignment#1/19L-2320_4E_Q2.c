#include<stdio.h>
#include<string.h>

#include<stdlib.h>
int main(int argc,const char *argv[])
{
	FILE *fp,*fp1;
	char buffer[100];
	char buffer2[100];
	char buffer3[100];
	int i,num;
	int mainmanuoption;
	while(1)
	{
		
		printf("Press 1 to Enter new record\n");
		printf("Press 2 to read the record\n");
		printf("Press 3 to delete a record\n");
		printf("press 4 to quit\n");
		printf("Enter main manu option : ");
		scanf("%d",&mainmanuoption);
		if(mainmanuoption==2)
		{
			
	
			fp=fopen(argv[1],"r");
			if(fp==NULL)
			{
				printf("file not exist");
			}
			else
			{
				printf("Enter the data number: ");
				scanf("%d",&num);

				for(i=-1;i<num;i++)
				{
				fgets(buffer,100,fp);
				fgets(buffer2,100,fp);
				fgets(buffer3,100,fp);
				}
				printf("Name : %s\n",buffer);
				printf("Roll No. :%s\n",buffer2);
				printf("E_mail : %s\n",buffer3);
				fclose(fp);
			}
		}
		if(mainmanuoption==1)
		{
			fp=fopen(argv[1],"a");
			printf("Enter the name : ");
			scanf("%s",buffer);
			fputs(buffer,fp);
			fprintf(fp,"\n");
			printf("Enter the roll number : ");
			scanf("%s",buffer2);
			fputs(buffer2,fp);
			fprintf(fp,"\n");
			printf("Enter the E-mail address : ");
			scanf("%s",buffer3);
			fputs(buffer3,fp);
			fprintf(fp,"\n");
			fclose(fp);
		}
		if(mainmanuoption==3)
		{
			fp=fopen(argv[1],"r");
			fp1=fopen("temp.txt","w");
			printf("Enter the data number: ");
			scanf("%d",&num);
			for(i=-1;i<num-1;++i)
			{
				fgets(buffer,100,fp);
				fgets(buffer2,100,fp);
				fgets(buffer3,100,fp);
				fputs(buffer,fp1);
				//fprintf(fp1,"\n");
				fputs(buffer2,fp1);
				//fprintf(fp1,"\n");
				fputs(buffer3,fp1);
				//fprintf(fp1,"\n");
			}
			
			fgets(buffer,100,fp);
			fgets(buffer2,100,fp);
			fgets(buffer3,100,fp);
			while(fgets(buffer,100,fp)!=NULL)
			{
				fgets(buffer2,100,fp);
				fgets(buffer3,100,fp);
				fputs(buffer,fp1);
				//fprintf(fp1,"\n");
				fputs(buffer2,fp1);
				//fprintf(fp1,"\n");
				fputs(buffer3,fp1);
				//fprintf(fp1,"\n");
			}
			remove(argv[1]);
			rename("temp.txt",argv[1]);
			fclose(fp1);
			fclose(fp);
		}
		if(mainmanuoption==4)
		{
		break;
		}
	}
	
	return 0;
}