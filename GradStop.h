#pragma once
#include "AbstrStop.h"
/// <summary>
///	\brief A descendant class of the AbstrStop class, responsible for stopping by the gradient value in gradient descent.

///<summary>
class GradStop :
    public AbstrStop
{
public:
    bool Stop() override;
};

