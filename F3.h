#pragma once
#include "AbstrFunc.h"
/// <summary>
///	\brief The class is a descendant of the AbstrFunc class, acting as a three-dimensional function.

///<summary>
class F3 :public AbstrFunc
{
public:
	double GetValF(vec f) override;
	int getDimension() const override {
		return 3; // размерность 2D функции
	}
};

