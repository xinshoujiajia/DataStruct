#ifndef MATHOBJECT_H
#define MATHOBJECT_H

#include "Suanshi.h"

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
    double value;
} M_const;

typedef struct
{
	_MathObject m;
	char value[64];
	double n;
} M_various;

typedef struct
{
	_MathObject m;
	char level;
	Suanshi s;
} M_brace;

typedef struct 
{
	_MathObject m;  
	MathObject value;  
} M_sin;

typedef struct 
{
	_MathObject m;  
	MathObject value;  
} M_cos;

typedef struct 
{
	_MathObject m;  
	MathObject index;
	MathObject value;
} M_pow;

typedef struct 
{
	_MathObject m;  
	MathObject n;
	MathObject value;
} M_sqrt;

typedef struct 
{
	_MathObject m;
	MathObject fz;
	MathObject fm;
} M_frac;


void MathObjectBuildFromstr(MathObject *obj, char **str);

void ConstBuildFromstr(MathObject *obj, char **str);
void VariousBuildFromstr(MathObject *obj, char **str);
void BraceBuildFromstr(MathObject *obj, char level, char **str);
void SinBuildFromstr(MathObject *obj, char **str);
void CosBuildFromstr(MathObject *obj, char **str);
void PowBuildFromstr(MathObject *obj, char **str);
void SqrtBuildFromstr(MathObject *obj, char **str);
void FracBuildFromstr(MathObject *obj, char **str);

void ConstOutput(MathObject obj);
void VariousOutput(MathObject obj);
void BraceOutput(MathObject obj);
void SinOutput(MathObject obj);
void CosOutput(MathObject obj);
void PowOutput(MathObject obj);
void SqrtOutput(MathObject obj);
void FracOutput(MathObject obj);

double ConstValue(MathObject obj);
double VariousValue(MathObject obj);
double BraceValue(MathObject obj);
double SinValue(MathObject obj);
double CosValue(MathObject obj);
double PowValue(MathObject obj);
double SqrtValue(MathObject obj);
double FracValue(MathObject obj);

#endif
