#pragma once
#include "AbstrFunc.h"
#include "AbstrStop.h"
#include "RectArea.h"
/// <summary>
/// \brief Parent class - Optimizer, which is responsible for finding the minimum of a function.
/// </summary>
class AbstrOptimiser
{
public:
	// <summary>
/// \brief This method is designed to find the minimum of an n-dimensional function.
/// \param point - the starting point from which the search will begin.
/// \param Func is the minimum function we are looking for.
/// \param S is the condition that will cause the optimizer to stop.
/// \param Shape is an n-dimensional parallelepiped.
/// </summary>
	virtual void optimise(vec& point, AbstrFunc* Func, AbstrStop* S, RectArea& Shape) = 0;
	~AbstrOptimiser(){}
    
};

