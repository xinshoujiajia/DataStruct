#include "MathObject.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *MathObjectBuildFromstr(MathObject *obj, char *str)
{
    char *p = str;
    p = ConstValueBuildFromstr(obj, p);
    return p;
}

char *ConstValueBuildFromstr(MathObject *obj, char *str)
{
    char *p = str;
    int value = 0;
    ConstValue c;
    while (*p)
    {
        if (!isdigit(*p))
        {
            break;
        }
        value = 10 * value - '0' + *p;
        p++;
    }
    c.m.output = ConstValueOutput;
    c.value = value;
    *obj = (MathObject)malloc(sizeof(ConstValue));
    memcpy(*obj, &c, sizeof(ConstValue));
    return p;
}

void ConstValueOutput(MathObject obj)
{
    printf("%d", ((ConstValue *)obj)->value);
}
