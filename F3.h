#pragma once
#include "AbstrFunc.h"
/// <summary>
///	\brief  ласс-наследник класса AbstrFunc, выполн€ющий роль трЄхмерной функции.

///<summary>
class F3 :public AbstrFunc
{
public:
	double GetValF(vec f) override;
};

