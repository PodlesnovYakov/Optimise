#pragma once
#include "AbstrStop.h"
/// <summary>
///	\brief A descendant class of the AbstrStop class, responsible for stopping by the two closest function values in a random search.

///<summary>
class ValFstop :
    public AbstrStop
{
    bool Stop() override;
};

