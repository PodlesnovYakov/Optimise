#pragma once
#include "AbstrFunc.h"
/// <summary>
///	\brief  ласс-наследник класса AbstrFunc, выполн€ющий роль двумерной функции.

///<summary>
class F2 :public AbstrFunc
{
public:
	double GetValF(vec f) override;
};

