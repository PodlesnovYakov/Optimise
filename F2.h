#pragma once
#include "AbstrFunc.h"
/// <summary>
///	\brief The class is a descendant of the AbstrFunc class, acting as a two-dimensional function.

///<summary>
class F2 :public AbstrFunc
{
public:
	double GetValF(vec f) override;
	int getDimension() const override;
};

