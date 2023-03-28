#include "Suanshi.h"
#include "MathObject.h"
#include <ctype.h>
#include <stdio.h>

void SuanshiCreate(Suanshi *s)
{
    LinkListCreate(s, sizeof(Team));
}
void SuanshiBuildFromstr(Suanshi s, char **str)
{
    char *p = *str;
    Team t;
    TeamCreate(&t, *p == '-' ? '-' : 0);
    TeamBuildFromstr(t, &p);
    LinkListInsertTail(s, &t);
    while (*p)
    {
        if (isblank(*p) || *p == '\n')
        {
            p++;
            continue;
        }
		if(*p=='}'||*p==']'||*p==')')
		{
			break;
		}
        TeamCreate(&t, *p);
        p++;
        TeamBuildFromstr(t, &p);
        LinkListInsertTail(s, &t);
    }
	*str = p;
}

void SuanshiOutput(Suanshi s)
{
    LinkListFor(p, LinkListGetFront(s))
    {
        TeamOutput(*(Team *)NodeGetData(p));
    }
}

void SuanshiHuajian(Suanshi s)
{
	LinkListFor(p,LinkListGetFront(s))
	{
		TeamChuLing((Team*)NodeGetData(p));
		if(*(Team*)NodeGetData(p)==NULL)
		{
			LinkListEraseNode(s, p);
		}
	}
}

void TeamCreate(Suanshi *t, char opt)
{
    LinkListCreate(t, sizeof(MathObject));
    TeamInfo I;
    I.operate = opt;
    LinkListSetHeaderInfo(*t, &I, sizeof(I));
}
void TeamBuildFromstr(Team t, char **str)
{
    char *p = *str;
    MathObject obj;
    while (*p)
    {
        if (isblank(*p) || *p =='\n')
        {
            p++;
            continue;
        }
        if (*p == '+' || *p == '-'||*p=='}'||*p==']'||*p==')')
		{
			break;
		}
        if (*p == '*')
        {
            p++;
        }
        MathObjectBuildFromstr(&obj, &p);
        LinkListInsertTail(t, &obj);
    }
	*str = p;
}

void TeamOutput(Team t)
{
    Node *p = LinkListGetFront(t);
    MathObject obj = *(MathObject *)NodeGetData(p);
    putchar(TeamGetOperate(t));
    obj->output(obj);
    LinkListFor(q, LinkListGetFront(p))
    {
        printf("*");
        obj = *(MathObject *)NodeGetData(q);
        obj->output(obj);
    }
}

void TeamChuLing(Team *t)
{
	int a=0;
	LinkListFor(p, LinkListGetFront(*t))
	{
		MathObject m = *(MathObject*)NodeGetData(p);
		if(m->value(m)==0)
		{
			a=1;
			break;
		}
	}
	if(a)
	{
		LinkListDestory(t);
	}
}

char TeamGetOperate(Team t)
{
    return ((TeamInfo *)LinkListGetHeaderInfo(t))->operate;
}
