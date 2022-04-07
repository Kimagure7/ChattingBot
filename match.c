#include<stdio.h>
#include<string.h>
int* match(char* string1,char* string2) //string1为输入的字符串，string2为我们想要匹配的字符串
{
	/*char string1[10];
	char string2[10];
	scanf("%s",string1);
	scanf("%s",string2);*/  //测试用
	int len1,len2;
	len1=strlen(string1);
	len2=strlen(string2);
	int n1=0 , n2=0 ,same=0;
	if(len1<=len2)
	{
	    while(string1[n1]!='\0')	//检测待匹配的字符串是否结束 
	    {
		    if(string1[n1]==string2[n2])
		    {
			same++; //计算相同字符的个数
		    }
		n1++;
		n2++;
	}
	}
	else
	{
		while(string2[n2]!='\0')	//检测待匹配的字符串是否结束 
	    {
		    if(string1[n1]==string2[n2])
		    {
			same++; //计算相同字符的个数
		    }
		n1++;
		n2++;
		}
	}
	int result[2];
	result[0]=(len2==same); //result第1位返回这两个字符串是否完全相同
	result[1]=same; //result第二位返回这两个字符串相同的有几位
	/*for(int i=0;i<2;i++)
	printf("%d\n",result[i]);
	return 0;*/  //测试用
	return result;
}
