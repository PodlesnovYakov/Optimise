#pragma once
#include "AbstrStop.h"
/// <summary>
///	\brief Класс-наследник класса AbstrStop, отвечающий за остановку по количеству итераций в обоих методах поиска минимума.

///<summary>
class StopIter :
    public AbstrStop
{
    bool Stop() override;
};

