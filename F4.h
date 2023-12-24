#pragma once
#include "AbstrFunc.h"
/// <summary>
///	\brief The class is a descendant of the AbstrFunc class, acting as a four-dimensional function.

///<summary>
class F4:public AbstrFunc
{
public:
	double GetValF(vec f) override;
	int getDimension() const override;
};

