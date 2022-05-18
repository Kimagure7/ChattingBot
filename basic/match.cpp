#include"include/match.h"
int match(char* string1,char* string2) //string1为输入的字符串，string2为我们想要匹配的字符串
{
	/*char string1[10];
	char string2[10];
	gets(string1);
	gets(string2);*/ //测试用
	int len1,len2;
	len1=strlen(string1);
	len2=strlen(string2);
	int n1=0 , n2=0 ,same=0;
	while(string1[n1]!='\0')
	{
		if(string1[n1]==string2[n2]){
			same++;
			while(string1[++n1]==string2[++n2]){
				if(string2[n2]!='\0')
					same++;
			}
		}
		n1++;
	}
	if(same==len2) 
		return 1; //匹配成功 就返回1
	else
		return 0; //匹配失败 就返回0
}

