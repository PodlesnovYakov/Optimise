#pragma once
#include "AbstrStop.h"
/// <summary>
///	\brief A descendant class of the AbstrStop class, responsible for stopping based on the relative error of the two closest function values in gradient descent.

///<summary>
class RelErStop :
    public AbstrStop
{
public:
    bool Stop() override;
};

