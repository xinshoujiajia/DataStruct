#include "Suanshi.h"
int main()
{
	Suanshi s;
	char str[] = "1*2+3*4";
	SuanshiCreate(&s);
	SuanshiBuildFromstr(s,str);
	SuanshiOutput(s);
	return 0;
}
