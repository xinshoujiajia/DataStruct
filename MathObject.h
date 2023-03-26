#ifndef MATHOBJECT_H
#define MATHOBJECT_H

typedef struct _MathObject _MathObject;
typedef _MathObject *MathObject;
struct _MathObject
{
    void (*output)(MathObject obj);
    double (*value)(MathObject obj);
};

typedef struct
{
    _MathObject m;
    int value;
} ConstValue;

char *MathObjectBuildFromstr(MathObject *obj, char *str);
char *ConstValueBuildFromstr(MathObject *obj, char *str);
void ConstValueOutput(MathObject obj);
#endif
