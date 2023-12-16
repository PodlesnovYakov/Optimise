#pragma once
#include "AbstrStop.h"
/// <summary>
///	\brief A descendant class of the AbstrStop class, responsible for stopping by the number of iterations in both methods of finding the minimum.

///<summary>
class StopIter :
    public AbstrStop
{
    bool Stop() override;
};

