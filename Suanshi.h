#ifndef SUANSHI_H
#define SUANSHI_H

#include "LinkList.h"
#include "MathObject.h"

typedef LinkList Suanshi;
typedef LinkList Team;

typedef struct
{
    char operate;
} TeamInfo;

void SuanshiCreate(Suanshi *s);
void SuanshiBuildFromstr(Suanshi s, char *str);
void SuanshiOutput(Suanshi s);
void TeamCreate(Team *t, char opt);
char *TeamBuildFromstr(Team t, char *str);
void TeamOutput(Team t);
char TeamGetOperate(Team t);

#endif
