#pragma once
#include "AbstrStop.h"
/// <summary>
///	\brief Класс-наследник класса AbstrStop, отвечающий за остановку по относительной ошибке двух ближайших значений функции в градиентном спуске.

///<summary>
class RelErStop :
    public AbstrStop
{
public:
    bool Stop() override;
};

