#include "Suanshi.h"
#include <ctype.h>
#include <stdio.h>

void SuanshiCreate(Suanshi *s)
{
    LinkListCreate(s, sizeof(Team));
}
void SuanshiBuildFromstr(Suanshi s, char *str)
{
    char *p = str;
    Team t;
    TeamCreate(&t, *p == '-' ? '-' : 0);
    p = TeamBuildFromstr(t, p);
    LinkListInsertTail(s, &t);
    while (*p)
    {
        if (isblank(*p))
        {
            p++;
            continue;
        }
        TeamCreate(&t, *p);
        p++;
        p = TeamBuildFromstr(t, p);
        LinkListInsertTail(s, &t);
    }
}

void SuanshiOutput(Suanshi s)
{
    LinkListFor(p, LinkListGetFront(s))
    {
        TeamOutput(*(Team *)NodeGetData(p));
    }
    puts("");
}
void TeamCreate(Suanshi *t, char opt)
{
    LinkListCreate(t, sizeof(MathObject));
    TeamInfo I;
    I.operate = opt;
    LinkListSetHeaderInfo(*t, &I, sizeof(I));
}
char *TeamBuildFromstr(Team t, char *str)
{
    char *p = str;
    MathObject obj;
    while (*p)
    {
        if (isblank(*p))
        {
            p++;
            continue;
        }
        if (*p == '+' || *p == '-')
        {
            break;
        }
        if (*p == '*')
        {
            p++;
        }
        p = MathObjectBuildFromstr(&obj, p);
        LinkListInsertTail(t, &obj);
    }
    return p;
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

char TeamGetOperate(Team t)
{
    return ((TeamInfo *)LinkListGetHeaderInfo(t))->operate;
}
