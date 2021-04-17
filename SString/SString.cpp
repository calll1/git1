#include "SString.h"
void InitString(SString S)
{
	S[0]='\0';
}
void StrAssign(SString S,char *str)
{
	int len=strlen(str);
	for(int i=0;i<len;++i)
	{
		S[i]=str[i];
	}
	S[len]='\0';
}
void PrintString(SString S)
{	
	printf("%s",S);
}
void StrCopy(SString S,SString T){
	int len =StrLength(T);
	for(int i=0;i<len;i++)
	{
		S[i]=T[i];
		
	}
	S[len]='\0';
}

bool StrEmpty(SString S){
	return S[0]=='\0';
}
int StrCompare(SString S,SString T){
	 int flag=0;
	 while(*S!='\0'||*T!='\0')
	 {
	 	flag=*S-*T;
	 	if(flag!=0)
	 	break;
	 	S++;
	 	T++;
	 }
	 if(flag<0)
	 flag = -1;
	if(flag>0)
	 flag= 1;
	 return flag;
}
int StrLength(SString S){
	int len=0;
	while(*S!='\0')
	{
		len++;
		S++;
	}
	return len;
}
void SubString(SString S,int pos,int len);
void StrConcat(SString T,SString s1,SString s2)
{
	int len1 = StrLength(s1);
	int len2 = StrLength(s2);
	if(len1+len2<=MAXSIZE)
	{
		for(int i=0;i<=len1;i++)
		{
			T[i]=s1[i];
			
			
		}
		for(int j=0;j<len2;++j)
		{
			T[j+len1]=s2[j];
		}
		T[len2+len1]='\0';
	 } else if(len1<MAXSIZE)
	 {
	 	for(int i=0;i<len1;i++)
		{
			T[i]=s1[i];
			
			
		}
		for(int j=0;j<MAXSIZE-len1;j++)
		{
			T[j+len1-1]=s2[j];
			
			
		}
		T[MAXSIZE]='\0';
	 }
	else
	{
		for(int i=0;i<MAXSIZE;i++)
		{
			T[i]=s1[i];
			
			
		}
		T[MAXSIZE]='\0';
	}
}
//void StrIndex(SString S,SString T,int pos);
//void StrReplace(SString S,SString T,SString V);
void SubString(SString S,SString sub,int pos,int len){
	int lens=StrLength(S);
	if(pos<0||pos>=lens||len<=0||len>lens)
	return ;
	for(int i=0;i<len;i++)
	{
		sub[i]=S[i+pos];
	}
	sub[len]='\0';

	
}
void StrInsert(SString S,int pos,SString T){
	int len1=StrLength(S);
	int len2=StrLength(T);
	if(len1+len2<=MAXSIZE)
	{
		
			for(int i=len1-1 ; i>=pos;i--)
	{
		S[i+len2]=S[i];
	}
	for(int j=0;j<len2;j++)
	{
	S[j+pos]=T[j];
	}	
	S[len2+len1]='\0';
}
else if(len1<MAXSIZE)
{
	len2=MAXSIZE-len1;
	
			for(int i=len1-1 ; i>=pos;i--)
	{
		S[i+len2]=S[i];
	}
	for(int j=0;j<len2;j++)
	{
	S[j+pos]=T[j];
	}	
	S[len2+len1]='\0';
}
}
	

void StrDele(SString S,int pos,int len){
	int len1=StrLength(S);
	for(int i=pos;i<len1;i++)
	{
		S[i]=S[i+len];
	 } 
	 S[len1-len]='\0';
} 
void StrClear(SString S){
 S[0]='\0';
} 
int StrIndex(SString S,SString T,int pos)
{
int i=pos;
int j=0;
 while(S[i]!='\0'&&T[j]!='\0')
 {
 	if(S[i]==T[j])
 	{
 		i++;
 		j++;
	 }else {
	 	i=i-j+1;
	 	j=0;
	 }
 }
 if(T[j]=='\0')
 return i-j;
 return -1;
}
void StrReplace(SString S,SString T,SString V){
	int s_len=StrLength(S);
		int v_len=StrLength(V);
			int t_len=StrLength(T);
			int index=-1;
			int pos=0;
			 while(pos<s_len)
	{
		 index=StrIndex(S,T,pos);
		 if(index==-1)
		 return;
		 StrDele(S,index,t_len);
		 StrInsert(S,index,V);
		 pos=index+v_len;
	}
	
	 
}
