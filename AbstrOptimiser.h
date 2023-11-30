#pragma once
#include "AbstrFunc.h"
#include "AbstrStop.h"
#include "RectArea.h"
/// <summary>
/// \brief Родительский класс - Оптимизатор, который отвечает за нахождения минимума функции.
/// </summary>
class AbstrOptimiser
{
public:
	// <summary>
/// \brief Данный метод предназначен для нахождения минимума n-мерной функции.
/// \param point - начальная точка, от которой начнется поиск.
/// \param Func - функция, минимум которой мы ищем.
/// \param S - условие, по которому будет остановка оптимизатора.
/// \param Shape - n-мерный параллелепипед.
/// </summary>
	virtual void optimise(vec& point, AbstrFunc* Func, AbstrStop* S, RectArea& Shape) = 0;
    
};

