#include "SString.h"
/*int main()
{	
	SString S;
	InitString(S);
	char *str="abcdefg";
	StrAssign(S,str);
	SString T;
	StrCopy(T,S);
	PrintString(T);
	StrAssign(S,"xy");
	StrAssign(T,"xyz");
	int res=StrCompare(S,T);
	printf("%d",res);
	SString Y;
	InitString(Y);
	StrConcat(Y,S,T);
	PrintString(Y);
	
	return 0;
}*/
/*int main()
{
	SString S;
	InitString(S);
	char *str="abcc";
	StrAssign(S,str);
	SString sub;
	InitString(sub);
	SubString(S,sub,1,3);
	PrintString(sub);
	StrInsert(S,2,sub);
	PrintString(S);
	
	
	return 0;
}*/
int main()
{
	SString S;
	InitString(S);
	StrAssign(S,"ababcababcab");
		SString T;
	InitString(T);
	StrAssign(T,"abc");
	SString V;
	InitString(V);
	StrAssign(V,"XY");
//	int index=StrIndex(S,T,0);
	//printf("%d",index);
	StrReplace(S,T,V);
	PrintString(S);
	
	return 0;
}
