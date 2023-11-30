#pragma once
#include "AbstrStop.h"
/// <summary>
///	\brief Класс-наследник класса AbstrStop, отвечающий за остановку по двум ближайшим значениям функции в случайном поиске.

///<summary>
class ValFstop :
    public AbstrStop
{
    bool Stop() override;
};

