#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int numb1,numb2,numb3,i;	//������ɵ���ֵ
int op1,op2;	//�����
FILE *fp;	//ָ����ļ� 
FILE *fb;	//ָ����Ŀ�ļ� 

int gcd(int numb1,int numb2)	//շת����� 
{
		if(numb2==0) return numb1;
		return	gcd(numb2,numb1%numb2);	
}

int caseone(int numb1,int numb2,int max,int i)		
{	
		int gcd(int numb1,int numb2);
		int temp;	//�м�ֵ
		int result;
		op1=rand()%4+1;		//op1������ֵΪ1��4���ֱ��Ӧ�ӷ����������˷�������
		fb=fopen("Exercises.txt","a");
		fp=fopen("Answers.txt","a");	//���ļ�
		switch(op1){
			case 1:		//op1Ϊ1��ʱ��ִ�мӷ�����
				result=numb1+numb2;
				fprintf(fp,"%d.��=%d\n",i,result);		//д���ļ�
			    fclose(fp);			//�ر��ļ�
				fprintf(fb,"%d.%d+%d=%d\n",i,numb1,numb2,result);		
			    fclose(fb);	
				break;
			case 2 :		//op1Ϊ2��ʱ��ִ�м���������
				if(numb1<numb2)		//Ϊ��֤�����Ϊ�㣬���������ɵı������ȼ���С����������ֵ�Ľ���
				{
				temp=numb1;
				numb2=numb1;
				numb1=temp;
				}
				result=numb1-numb2;
				fprintf(fp,"%d.��=%d\n",i,result);
			    fclose(fp);
				fprintf(fb,"%d.%d-%d =%d\n",i,numb1,numb2,result);
			    fclose(fb);
				break;
			case 3 :		//op1Ϊ3��ʱ��ִ�г˷�������
				result=numb1*numb2;
				fprintf(fp,"%d.��=%d\n",i,result);
			    fclose(fp);
				fprintf(fb,"%d.%d*%d =%d\n",i,numb1,numb2,result);
			    fclose(fb);
				break;
			case 4 :		//op1Ϊ4��ʱ��ִ�г���������
				if(numb2==0)
					numb2=rand()%max+1;
				temp=gcd(numb1,numb2);
				fprintf(fp,"%d.��=%d/%d\n",i,numb1/temp,numb2/temp);
			    fclose(fp);
				fprintf(fb,"%d.%d/%d =%d/%d\n",i,numb1,numb2,numb1/temp,numb2/temp);
			    fclose(fb);
				break;
			default:printf("ERROR\n");
		}
		return 0;
}

int casetwo(int numb1,int numb2,int numb3,int max,int i)
{	
		int gcd(int numb1,int numb2);
		int result, result1,temp,temp1;
		op1=rand()%4+1;		
		op2=rand()%4+1;						//op1,op2������ֵΪ1��4���ֱ��Ӧ�ӷ����������˷�������
		fp=fopen("Answers.txt","a");
		fb=fopen("Exercises.txt","a");
		switch(op1){
			case 1 :		
				switch(op2){
				case 1 :					//op1,op2��Ϊ�ӷ������
					result1=numb1+numb2;
					result=result1+numb3;
					fprintf(fp,"%d.��=%d\n",i,result);
					fclose(fp);
					fprintf(fb,"%d.%d+%d+%d%=%d\n",i,numb1,numb2,numb3,result);
					fclose(fb);
					break;
				case 2 :					//op1Ϊ�ӷ�,op2Ϊ���������
					result1=numb1+numb2;
					if(result1<numb3)
					{
						temp=numb3;
						numb3=numb2;
						numb2=temp;
					}
					result=numb1+numb2-numb3;
					fprintf(fp,"%d.��=%d\n",i,result);
					fclose(fp);
					fprintf(fb,"%d.%d+%d-%d%=%d\n",i,numb1,numb2,numb3,result);
					fclose(fb);
					break;
				case 3 :					//op1Ϊ�ӷ�,op2Ϊ�˷������
					result1=numb2*numb3;
					result=numb1+result1;
					fprintf(fp,"%d.��=%d\n",i,result);
					fclose(fp);
					fprintf(fb,"%d.%d+%d*%d%=%d\n",i,numb1,numb2,numb3,result);
					fclose(fb);
					break;
				case 4 :					//op1Ϊ�ӷ�,op2Ϊ���������
					if(numb3==0)
					{
					numb3=rand()%max+1;
					}
					temp=gcd(numb2,numb3);
					fprintf(fp,"%d.��=%d'%d/%d\n",i,numb1,numb2/temp,numb3/temp);
					fclose(fp);
					fprintf(fb,"%d.%d+%d/%d%=%d'%d/%d\n",i,numb1,numb2,numb3,numb1,numb2/temp,numb3/temp);
					fclose(fb);
					break;
				default:printf("ERROR\n");
				}
				break;
			case 2 :		
				switch(op2){
					case 1 :					//op1Ϊ����,op2Ϊ�ӷ������
						if(numb1<numb2)			//Ϊ��֤�����Ϊ�㣬���������ɵı������ȼ���С����������ֵ�Ľ���
						{
							temp=numb1;
							numb2=numb1;
							numb1=temp;
						}
						result=numb1-numb2+numb3;
						fprintf(fp,"%d.��=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d-%d+%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
					case 2 :					//op1Ϊ����,op2Ϊ���������
						do{
						numb1=rand()%max;
						numb2=rand()%max;
						numb3=rand()%max;
						}while((numb1-numb2-numb3)<=0);
						result=numb1-numb2-numb3;
						fprintf(fp,"%d.��=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d-%d-%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
					case 3 :					//op1Ϊ����,op2Ϊ�˷������
						do{
						numb1=rand()%max;
						numb2=rand()%max;
						numb3=rand()%max;
						}while((numb1-numb2*numb3)<0);
						result=numb1-numb2*numb3;
						fprintf(fp,"%d.��=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d-%d*%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
					case 4 :					//op1Ϊ����,op2Ϊ���������
						do{
						numb1=rand()%max;
						numb2=rand()%max;
						numb3=rand()%max;
						}while((numb1-numb2/numb3)<0||numb3==0);
						result=numb1-numb2/numb3;
						fprintf(fp,"%d.��=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d-%d/%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
				default:printf("ERROR\n");
				}
				break;
			case 3 :		
				switch(op2){
					case 1 :					//op1Ϊ�˷�,op2Ϊ�ӷ������
						result=numb1*numb2+numb3;
						fprintf(fp,"%d.��=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d*%d+%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
					case 2 :					//op1Ϊ�˷�,op2Ϊ���������
						do{
						numb1=rand()%max;
						numb2=rand()%max;
						numb3=rand()%max;
						}while((numb1*numb2-numb3)<0);
						result=numb1*numb2-numb3;
						fprintf(fp,"%d.��=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d*%d-%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
					case 3 :					//op1Ϊ�˷�,op2Ϊ�˷������
						result=numb1*numb2*numb3;
						fprintf(fp,"%d.��=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d*%d*%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
					case 4 :					//op1Ϊ�˷�,op2Ϊ���������
						do{
						numb3=rand()%max;
						}while(numb3==0);
						temp1=numb1*numb2;
						temp=gcd(temp1,numb3);
						fprintf(fp,"%d.��=%d/%d\n",i,temp1/temp,numb3/temp);
						fclose(fp);
						fprintf(fb,"%d.%d*%d/%d%=%d/%d\n",i,numb1,numb2,numb3,temp1/temp,numb3/temp);
						fclose(fb);
						break;
				default:printf("ERROR\n");
				}
				break;
			case 4 :		
				switch(op2){
					case 1 :					//op1Ϊ����,op2Ϊ�ӷ������
						do{
						numb2=rand()%max;
						}while(numb2==0);
						temp=gcd(numb1,numb2);
						fprintf(fp,"%d.��=%d'%d/%d\n",i,numb3,numb1/temp,numb2/temp);
						fclose(fp);
						fprintf(fb,"%d.%d/%d+%d%=%d'%d/%d\n",i,numb1,numb2,numb3,numb3,numb1/temp,numb2/temp);
						fclose(fb);
						break;
					case 2 :					//op1Ϊ����,op2Ϊ���������
						do{
						numb3=rand()%max;
						}while(	(numb1/numb2-numb3)<0||numb2==0);
						result=numb1/numb2-numb3;
						fprintf(fp,"%d.��=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d/%d-%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
					case 3 :					//op1Ϊ����,op2Ϊ�˷������
						do{
						numb2=rand()%max;
						}while(numb2==0);
						temp1=numb1*numb3;
						temp=gcd(temp1,numb2);
						result=numb1/numb2*numb3;
						fprintf(fp,"%d.��=%d/%d\n",i,temp1/temp,numb2/temp);
						fclose(fp);
						fprintf(fb,"%d.%d/%d*%d%=%d/%d\n",i,numb1,numb2,numb3,temp1/temp,numb2/temp);
						fclose(fb);
						break;
					case 4 :					//op1Ϊ����,op2Ϊ���������
						do{
						numb2=rand()%max;
						numb3=rand()%max;
						}while(numb3==0||numb2==0);
						result=numb1/numb2/numb3;
						temp1=numb2*numb3;
						temp=gcd(temp1,numb1);
						fprintf(fp,"%d.��=%d/%d\n",i,numb1/temp,temp1/temp);
						fclose(fp);
						fprintf(fb,"%d.%d/%d/%d%=%d/%d\n",i,numb1,numb2,numb3,numb1/temp,temp1/temp);
						fclose(fb);
						break;
				default:printf("ERROR\n");
				}
				break;
			default:printf("ERROR\n");
		}
		return 0;
}


int Count(char file[])  /*�������Ŀ����*/ 
{
    FILE *fp1;
    char a;
    int x=0;
    if((fp1=fopen(file,"r"))==NULL)
    {
        printf("read file failed��\n");
        exit(0);
    }
    while(!feof(fp1))
    {
        a=fgetc(fp1);
        if(a=='\n')
            x++;
    }      
    fclose(fp1);
    return x;
}

void Put_Judge(int *str1,int *str2,int n) /* ���ж϶Դ���*/ 
{
	int i,j;
	FILE *out;
	out=fopen("Grade.txt","w");
	for(i=0,j=0;i<n;i++)     /*�Եĸ���*/ 
		if(*(str1+i)==*(str2+i))
		j++;	
	fprintf(out,"Correct:%d (",j);
	for(i=0;i<n;i++)     /*�Ե����*/ 
	{
		if(*(str1+i)==*(str2+i))
		fprintf(out," %d ",(i+1));
	}
	fprintf(out,")\n");
 	fprintf(out,"Wrong:%d (",(n-j));
	for(i=0;i<n;i++)  /*������*/ 
	{
		if(*(str1+i)!=*(str2+i))
		fprintf(out," %d ",(i+1));
	}
	fprintf(out,")\n");
	fclose(out);
	printf("OK");
}

void GetAnswers(char infile[],int *str)  /*��ȡѧ���𰸵ĺ���*/ 
{
	FILE *in;
	char a;
	int i=0;
if((in=fopen(infile,"r"))==NULL)
	{
	   printf("read file failed��\n"); 
	   exit(0);
	} 
	while(!feof(in))
	{
		*(str+i)=0;
		a=fgetc(in);		
		if(a!='=') 
		continue;
		while(1)
		{
			a=fgetc(in);
			if(a=='\n')break;
			*(str+i)*=10;	
			*(str+i)+=(a-48);
	    }
			printf("%d ",*(str+i));
			i++;
	}
	printf("\n");
	fclose(in);
}


int main()
{
		int subnumber,max;
		int opnum;
		int caseone(int numb1,int numb2,int max,int i);		//����������
		int casetwo(int numb1,int numb2,int numb3,int max,int i);
		FILE *fp;
		fp=fopen("Exercises.txt","w");
		fp=fopen("Answers.txt","w");			//�����ļ�
		fclose(fp);
		srand((unsigned)time(0));				//Ϊ��֤ÿ�����г����ʱ�����ɵ���Ŀ����һ��
		printf("***************�����������������Ŀ*****************************\n");
		printf("1.ʹ�� -n ��������������Ŀ�ĸ���\n");
		printf("2.ʹ�� -r ����������Ŀ����ֵ����Ȼ������������������ĸ���ķ�Χ\n");
		printf("������n��");
		scanf("%d",&subnumber); 
		printf("������r��");
		scanf("%d",&max); 
		printf("��Ŀ�����У����Ժ�...\n"); 
		for(i=1;i<=subnumber;i++)		//forѭ��������Ŀ
		{
			opnum=rand()%2+1;
			switch(opnum)		
			{
			case 1 :							//�������������1�������ʱ
				numb1=rand()%max;
				numb2=rand()%max;
				caseone(numb1,numb2,max,i);		//ִ�к�����ͬʱ��ͬʱִ�аѱ��ʽ�����txt�ļ���
				break;
			case 2 :			//�������������2�������ʱ
				numb1=rand()%max;
				numb2=rand()%max;
				numb3=rand()%max;
				casetwo(numb1,numb2,numb3,max,i);
				break;	
			default:printf("ERROR\n");
			}
		}
		char file1[10],file2[10],s[3];
	    int *exe;
	    int *an;
	    printf("У���ļ��𰸲�����Grade.txt�ļ�\n");
		printf("��������ϰ�ı���\n"); 
		scanf("%s",file1);
		printf("��������ı���\n"); 
		scanf("%s",file2);
		int n;
		n=Count(file1);
		exe=(int*)malloc(n*sizeof(int));
		an=(int*)malloc(n*sizeof(int));
		GetAnswers(file1,exe);
		GetAnswers(file2,an);
		Put_Judge(exe,an,n);
		return 0;

}
