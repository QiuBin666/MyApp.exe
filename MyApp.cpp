#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int numb1,numb2,numb3,i;	//随机生成的数值
int op1,op2;	//运算符
FILE *fp;	//指向答案文件 
FILE *fb;	//指向题目文件 

int gcd(int numb1,int numb2)	//辗转相除法 
{
		if(numb2==0) return numb1;
		return	gcd(numb2,numb1%numb2);	
}

int caseone(int numb1,int numb2,int max,int i)		
{	
		int gcd(int numb1,int numb2);
		int temp;	//中间值
		int result;
		op1=rand()%4+1;		//op1的生成值为1到4，分别对应加法，减法，乘法，除法
		fb=fopen("Exercises.txt","a");
		fp=fopen("Answers.txt","a");	//打开文件
		switch(op1){
			case 1:		//op1为1的时候，执行加法操作
				result=numb1+numb2;
				fprintf(fp,"%d.答案=%d\n",i,result);		//写入文件
			    fclose(fp);			//关闭文件
				fprintf(fb,"%d.%d+%d=%d\n",i,numb1,numb2,result);		
			    fclose(fb);	
				break;
			case 2 :		//op1为2的时候，执行减法操作；
				if(numb1<numb2)		//为保证结果不为零，当出现生成的被减数比减数小，进行两者值的交换
				{
				temp=numb1;
				numb2=numb1;
				numb1=temp;
				}
				result=numb1-numb2;
				fprintf(fp,"%d.答案=%d\n",i,result);
			    fclose(fp);
				fprintf(fb,"%d.%d-%d =%d\n",i,numb1,numb2,result);
			    fclose(fb);
				break;
			case 3 :		//op1为3的时候，执行乘法操作；
				result=numb1*numb2;
				fprintf(fp,"%d.答案=%d\n",i,result);
			    fclose(fp);
				fprintf(fb,"%d.%d*%d =%d\n",i,numb1,numb2,result);
			    fclose(fb);
				break;
			case 4 :		//op1为4的时候，执行除法操作；
				if(numb2==0)
					numb2=rand()%max+1;
				temp=gcd(numb1,numb2);
				fprintf(fp,"%d.答案=%d/%d\n",i,numb1/temp,numb2/temp);
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
		op2=rand()%4+1;						//op1,op2的生成值为1到4，分别对应加法，减法，乘法，除法
		fp=fopen("Answers.txt","a");
		fb=fopen("Exercises.txt","a");
		switch(op1){
			case 1 :		
				switch(op2){
				case 1 :					//op1,op2均为加法的情况
					result1=numb1+numb2;
					result=result1+numb3;
					fprintf(fp,"%d.答案=%d\n",i,result);
					fclose(fp);
					fprintf(fb,"%d.%d+%d+%d%=%d\n",i,numb1,numb2,numb3,result);
					fclose(fb);
					break;
				case 2 :					//op1为加法,op2为减法的情况
					result1=numb1+numb2;
					if(result1<numb3)
					{
						temp=numb3;
						numb3=numb2;
						numb2=temp;
					}
					result=numb1+numb2-numb3;
					fprintf(fp,"%d.答案=%d\n",i,result);
					fclose(fp);
					fprintf(fb,"%d.%d+%d-%d%=%d\n",i,numb1,numb2,numb3,result);
					fclose(fb);
					break;
				case 3 :					//op1为加法,op2为乘法的情况
					result1=numb2*numb3;
					result=numb1+result1;
					fprintf(fp,"%d.答案=%d\n",i,result);
					fclose(fp);
					fprintf(fb,"%d.%d+%d*%d%=%d\n",i,numb1,numb2,numb3,result);
					fclose(fb);
					break;
				case 4 :					//op1为加法,op2为除法的情况
					if(numb3==0)
					{
					numb3=rand()%max+1;
					}
					temp=gcd(numb2,numb3);
					fprintf(fp,"%d.答案=%d'%d/%d\n",i,numb1,numb2/temp,numb3/temp);
					fclose(fp);
					fprintf(fb,"%d.%d+%d/%d%=%d'%d/%d\n",i,numb1,numb2,numb3,numb1,numb2/temp,numb3/temp);
					fclose(fb);
					break;
				default:printf("ERROR\n");
				}
				break;
			case 2 :		
				switch(op2){
					case 1 :					//op1为减法,op2为加法的情况
						if(numb1<numb2)			//为保证结果不为零，当出现生成的被减数比减数小，进行两者值的交换
						{
							temp=numb1;
							numb2=numb1;
							numb1=temp;
						}
						result=numb1-numb2+numb3;
						fprintf(fp,"%d.答案=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d-%d+%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
					case 2 :					//op1为减法,op2为减法的情况
						do{
						numb1=rand()%max;
						numb2=rand()%max;
						numb3=rand()%max;
						}while((numb1-numb2-numb3)<=0);
						result=numb1-numb2-numb3;
						fprintf(fp,"%d.答案=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d-%d-%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
					case 3 :					//op1为减法,op2为乘法的情况
						do{
						numb1=rand()%max;
						numb2=rand()%max;
						numb3=rand()%max;
						}while((numb1-numb2*numb3)<0);
						result=numb1-numb2*numb3;
						fprintf(fp,"%d.答案=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d-%d*%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
					case 4 :					//op1为减法,op2为除法的情况
						do{
						numb1=rand()%max;
						numb2=rand()%max;
						numb3=rand()%max;
						}while((numb1-numb2/numb3)<0||numb3==0);
						result=numb1-numb2/numb3;
						fprintf(fp,"%d.答案=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d-%d/%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
				default:printf("ERROR\n");
				}
				break;
			case 3 :		
				switch(op2){
					case 1 :					//op1为乘法,op2为加法的情况
						result=numb1*numb2+numb3;
						fprintf(fp,"%d.答案=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d*%d+%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
					case 2 :					//op1为乘法,op2为减法的情况
						do{
						numb1=rand()%max;
						numb2=rand()%max;
						numb3=rand()%max;
						}while((numb1*numb2-numb3)<0);
						result=numb1*numb2-numb3;
						fprintf(fp,"%d.答案=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d*%d-%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
					case 3 :					//op1为乘法,op2为乘法的情况
						result=numb1*numb2*numb3;
						fprintf(fp,"%d.答案=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d*%d*%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
					case 4 :					//op1为乘法,op2为除法的情况
						do{
						numb3=rand()%max;
						}while(numb3==0);
						temp1=numb1*numb2;
						temp=gcd(temp1,numb3);
						fprintf(fp,"%d.答案=%d/%d\n",i,temp1/temp,numb3/temp);
						fclose(fp);
						fprintf(fb,"%d.%d*%d/%d%=%d/%d\n",i,numb1,numb2,numb3,temp1/temp,numb3/temp);
						fclose(fb);
						break;
				default:printf("ERROR\n");
				}
				break;
			case 4 :		
				switch(op2){
					case 1 :					//op1为除法,op2为加法的情况
						do{
						numb2=rand()%max;
						}while(numb2==0);
						temp=gcd(numb1,numb2);
						fprintf(fp,"%d.答案=%d'%d/%d\n",i,numb3,numb1/temp,numb2/temp);
						fclose(fp);
						fprintf(fb,"%d.%d/%d+%d%=%d'%d/%d\n",i,numb1,numb2,numb3,numb3,numb1/temp,numb2/temp);
						fclose(fb);
						break;
					case 2 :					//op1为除法,op2为减法的情况
						do{
						numb3=rand()%max;
						}while(	(numb1/numb2-numb3)<0||numb2==0);
						result=numb1/numb2-numb3;
						fprintf(fp,"%d.答案=%d\n",i,result);
						fclose(fp);
						fprintf(fb,"%d.%d/%d-%d%=%d\n",i,numb1,numb2,numb3,result);
						fclose(fb);
						break;
					case 3 :					//op1为除法,op2为乘法的情况
						do{
						numb2=rand()%max;
						}while(numb2==0);
						temp1=numb1*numb3;
						temp=gcd(temp1,numb2);
						result=numb1/numb2*numb3;
						fprintf(fp,"%d.答案=%d/%d\n",i,temp1/temp,numb2/temp);
						fclose(fp);
						fprintf(fb,"%d.%d/%d*%d%=%d/%d\n",i,numb1,numb2,numb3,temp1/temp,numb2/temp);
						fclose(fb);
						break;
					case 4 :					//op1为除法,op2为除法的情况
						do{
						numb2=rand()%max;
						numb3=rand()%max;
						}while(numb3==0||numb2==0);
						result=numb1/numb2/numb3;
						temp1=numb2*numb3;
						temp=gcd(temp1,numb1);
						fprintf(fp,"%d.答案=%d/%d\n",i,numb1/temp,temp1/temp);
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


int Count(char file[])  /*计算的题目数量*/ 
{
    FILE *fp1;
    char a;
    int x=0;
    if((fp1=fopen(file,"r"))==NULL)
    {
        printf("read file failed！\n");
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

void Put_Judge(int *str1,int *str2,int n) /* 答案判断对错函数*/ 
{
	int i,j;
	FILE *out;
	out=fopen("Grade.txt","w");
	for(i=0,j=0;i<n;i++)     /*对的个数*/ 
		if(*(str1+i)==*(str2+i))
		j++;	
	fprintf(out,"Correct:%d (",j);
	for(i=0;i<n;i++)     /*对的序号*/ 
	{
		if(*(str1+i)==*(str2+i))
		fprintf(out," %d ",(i+1));
	}
	fprintf(out,")\n");
 	fprintf(out,"Wrong:%d (",(n-j));
	for(i=0;i<n;i++)  /*错的序号*/ 
	{
		if(*(str1+i)!=*(str2+i))
		fprintf(out," %d ",(i+1));
	}
	fprintf(out,")\n");
	fclose(out);
	printf("OK");
}

void GetAnswers(char infile[],int *str)  /*读取学生答案的函数*/ 
{
	FILE *in;
	char a;
	int i=0;
if((in=fopen(infile,"r"))==NULL)
	{
	   printf("read file failed！\n"); 
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
		int caseone(int numb1,int numb2,int max,int i);		//函数的声明
		int casetwo(int numb1,int numb2,int numb3,int max,int i);
		FILE *fp;
		fp=fopen("Exercises.txt","w");
		fp=fopen("Answers.txt","w");			//建立文件
		fclose(fp);
		srand((unsigned)time(0));				//为保证每次运行程序的时候生成的题目都不一样
		printf("***************随机生成四则运算题目*****************************\n");
		printf("1.使用 -n 参数控制生成题目的个数\n");
		printf("2.使用 -r 参数控制题目中数值（自然数、真分数和真分数分母）的范围\n");
		printf("请输入n：");
		scanf("%d",&subnumber); 
		printf("请输入r：");
		scanf("%d",&max); 
		printf("题目生成中，请稍后...\n"); 
		for(i=1;i<=subnumber;i++)		//for循环生成题目
		{
			opnum=rand()%2+1;
			switch(opnum)		
			{
			case 1 :							//当随机数是生成1个运算符时
				numb1=rand()%max;
				numb2=rand()%max;
				caseone(numb1,numb2,max,i);		//执行函数的同时得同时执行把表达式输出到txt文件中
				break;
			case 2 :			//当随机数是生成2个运算符时
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
	    printf("校对文件答案并生成Grade.txt文件\n");
		printf("请输入练习文本：\n"); 
		scanf("%s",file1);
		printf("请输入答案文本：\n"); 
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
