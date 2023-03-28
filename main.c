#include "Suanshi.h"
#include <stdio.h>
int main()
{
	Suanshi s;
	char str[100]="1+1*2*0+2+333\n";
	char *p = str;
	SuanshiCreate(&s);
	SuanshiBuildFromstr(s,&p);
	printf("原式：");
	SuanshiOutput(s);
	SuanshiHuajian(s);
	printf("\n化简后：");
	SuanshiOutput(s);
	puts("");
	return 0;
}
