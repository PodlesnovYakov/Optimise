#pragma once
#include "AbstrStop.h"
#include "VectorOper.h"
/// <summary>
///	\brief A descendant class of the AbstrStop class, responsible for stopping at the two closest points in gradient descent.
///<summary>
class PointStop :
    public AbstrStop
{
public:
    bool Stop() override;
};

