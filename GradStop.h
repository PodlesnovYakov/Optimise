#pragma once
#include "AbstrStop.h"
/// <summary>
///	\brief Класс-наследник класса AbstrStop, отвечающий за остановку по значению градиента в градиентном спуске.

///<summary>
class GradStop :
    public AbstrStop
{
public:
    bool Stop() override;
};

