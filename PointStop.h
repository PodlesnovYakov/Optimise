#pragma once
#include "AbstrStop.h"
#include "VectorOper.h"
/// <summary>
///	\brief  ласс-наследник класса AbstrStop, отвечающий за остановку по двум ближайшим точкам в градиентном спуске.

///<summary>
class PointStop :
    public AbstrStop
{
public:
    bool Stop() override;
};

