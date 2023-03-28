#include "MathObject.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char brace[3][2]={{'{','}'},{'[',']'},{'(',')'}};
int M_strcmp(char* str, char* p)
{
	char *q;
	for(q=str;q;q++,p++)
	{
		if(*q!=*p)
		{
			break;
		}
	}
	return *q == 0;
}

void MathObjectBuildFromstr(MathObject *obj, char **str)
{
    char *p = *str;
	MathObject m;
	if(isdigit(*p))
	{
    	ConstBuildFromstr(&m, &p);
	}
	else if(isalpha(*p))
	{
		VariousBuildFromstr(&m, &p);
	}
	else if(*p == '\\')
	{
		p++;
		if(M_strcmp("sin",p))
		{
			p+=3;
			SinBuildFromstr(&m,&p);
		}else if(M_strcmp("cos",p))
		{
			p+=3;
			CosBuildFromstr(&m,&p);
		}else if(M_strcmp("sqrt",p))
		{
			p+=4;
			SqrtBuildFromstr(&m,&p);
		}else if(M_strcmp("frac",p))
		{
			p+=4;
			FracBuildFromstr(&m,&p);
		}
	}
	else 
	{
		switch(*p)
		{
			case '{':BraceBuildFromstr(&m,0,&p);break;
			case '[':BraceBuildFromstr(&m,1,&p);break;
			case '(':BraceBuildFromstr(&m,2,&p);break;
		}
	}
	if(*p == '^')
	{
		p++;
		PowBuildFromstr(&m, &p);
	}
	*obj = m;
	*str = p;
}

void ConstBuildFromstr(MathObject *obj, char **str)
{
    char i=1, *p = *str;
    int value = 0;
	double f = 0;
    M_const c;
    while (*p)
    {
        if (!isdigit(*p))
        {
			if(*p == '.'&&i)
			{
				i=0;
				p++;
			}
			else
			{
            	break;
        	}
        }
		if(i)
		{
        	value = 10 * value - '0' + *p;
        	p++;
		}
		else
		{
			f = (f-'0'+*p)/10;
		}
    }
    c.m.output = ConstOutput;
    c.m.value = ConstValue;
    c.value = f+value;
    *obj = (MathObject)malloc(sizeof(M_const));
    memcpy(*obj, &c, sizeof(M_const));
    *str = p;
}

void VariousBuildFromstr(MathObject *obj, char **str)
{
    char *p = *str;
	M_various v;
	char *q = v.value;
    while (*p)
    {
		if(!isalpha(*p))
		{
			break;
		}
		*q=*p;
		p++;q++;
    }
	*q=0;
	v.m.output = VariousOutput;
	*obj = (MathObject)malloc(sizeof(M_various));
	memcpy(*obj, &v, sizeof(M_various));
    *str = p;
}

void BraceBuildFromstr(MathObject *obj,char level, char **str)
{
    char *p = *str;
	M_brace b;
	Suanshi s;
	p++;
	SuanshiCreate(&s);
	SuanshiBuildFromstr(s, &p);
	p++;
	b.m.output = BraceOutput;
	b.level=level;
	b.s=s;
	*obj = (MathObject)malloc(sizeof(M_brace));
	memcpy(*obj, &b, sizeof(M_brace));
    *str = p;
}

void SinBuildFromstr(MathObject *obj, char **str)
{
    char *p = *str;
	M_sin s;
	MathObject m;
	MathObjectBuildFromstr(&m, &p);
	s.m.output=SinOutput;
	s.value=m;
	*obj = (MathObject)malloc(sizeof(M_sin));
	memcpy(*obj, &s, sizeof(M_sin));
    *str = p;
}

void CosBuildFromstr(MathObject *obj, char **str)
{
    char *p = *str;
	M_cos s;
	MathObject m;
	MathObjectBuildFromstr(&m, &p);
	s.m.output=CosOutput;
	s.value=m;
	*obj = (MathObject)malloc(sizeof(M_cos));
	memcpy(*obj, &s, sizeof(M_cos));
    *str = p;
}

void PowBuildFromstr(MathObject *obj, char **str)
{
    char *p = *str;
	M_pow o;
	MathObject m;
	MathObjectBuildFromstr(&m, &p);
	o.m.output = PowOutput;
	o.index = m;
	o.value = *obj;
	*obj = (MathObject)malloc(sizeof(M_pow));
	memcpy(*obj, &o, sizeof(M_pow));
    *str = p;
}

void SqrtBuildFromstr(MathObject *obj, char **str)
{
    char *p = *str;
	M_sqrt s;
	MathObject m;
	MathObjectBuildFromstr(&m, &p);
	s.m.output = SqrtOutput;
	s.value = m;
	*obj = (MathObject)malloc(sizeof(M_sqrt));
	memcpy(*obj, &s, sizeof(M_sqrt));
    *str = p;
}

void FracBuildFromstr(MathObject *obj, char **str)
{
    char *p = *str;
	M_frac f;
	MathObject fz,fm;
	MathObjectBuildFromstr(&fz, &p);
	MathObjectBuildFromstr(&fm, &p);
	f.m.output = FracOutput;
	f.fz = fz;
	f.fm = fm;
	*obj = (MathObject)malloc(sizeof(M_frac));
	memcpy(*obj, &f, sizeof(M_frac));
    *str = p;
}

void ConstOutput(MathObject obj)
{
    printf("%f", ((M_const *)obj)->value);
}

void VariousOutput(MathObject obj)
{
	printf("%s",((M_various *)obj)->value);
}

void BraceOutput(MathObject obj)
{
	M_brace *b=(M_brace*)obj;
	putchar(brace[b->level][0]);
	SuanshiOutput(b->s);
	putchar(brace[b->level][1]);
}

void SinOutput(MathObject obj)
{
	M_sin *s=(M_sin*)obj;
	printf("\\sin ");
	s->value->output(s->value);
}

void CosOutput(MathObject obj)
{
	M_cos *s=(M_cos*)obj;
	printf("\\cos ");
	s->value->output(s->value);
}

void PowOutput(MathObject obj)
{
	M_pow *s=(M_pow*)obj;
	s->value->output(s->value);
	printf("^");
	s->index->output(s->index);
}

void SqrtOutput(MathObject obj)
{
	M_sqrt *s=(M_sqrt*)obj;
	printf("\\sqrt ");
	s->value->output(s->value);
}

void FracOutput(MathObject obj)
{
	M_frac *s=(M_frac*)obj;
	printf("\\frac");
	s->fz->output(s->fz);
	s->fm->output(s->fm);
}

double ConstValue(MathObject obj)
{
	return ((M_const*)obj)->value;
}

double VariousValue(MathObject obj)
{
	return 0;
}

double BraceValue(MathObject obj)
{
	return 0;
}

double SinValue(MathObject obj)
{
	return 0;
}

double CosValue(MathObject obj)
{
	return 0;
}

double PowValue(MathObject obj)
{
	return 0;
}

double SqrtValue(MathObject obj)
{
	return 0;
}

double FracValue(MathObject obj)
{
	return 0;
}


