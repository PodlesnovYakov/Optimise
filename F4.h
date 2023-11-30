#pragma once
#include "AbstrFunc.h"
/// <summary>
///	\brief  ласс-наследник класса AbstrFunc, выполн€ющий роль четырЄхмерной функции.

///<summary>
class F4:public AbstrFunc
{
public:
	double GetValF(vec f) override;
};

