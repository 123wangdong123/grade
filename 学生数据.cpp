#include<stdio.h>
#include<iostream>
struct student
{
	char num[10];
	char name[8];
	int score[3];
	int ave;
}stu[2];
int main()
{
	int i,j,sum;
	
	FILE *fp;
	for(i=0;i<2;i++)
	{
		printf("\ninput score of student %d:\n",i+1);
		printf("NO.:");
		scanf("%s",stu[i].num);
		printf("name:");
		scanf("%s",stu[i].name);
		sum=0;
		for(j=0;j<3;j++)
		{
			printf("score %d:",j+1);
			scanf("%d",&stu[i].score[j]);
			sum+=stu[i].score[j];
		}
		stu[i].ave=sum/3.0;
	}
	
	fp=fopen("stud","w");
	for(i=0;i<2;i++)
	if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
		printf("can not open this file\n");
		fclose(fp);
		fp=fopen("stud","r");
		for(i=0;i<2;i++)
		{
			fread(&stu[i],sizeof(struct student),1,fp);
			printf("\n%s,%s,%d,%d,%d,%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].ave);
			}
			return 0; 
 } 
