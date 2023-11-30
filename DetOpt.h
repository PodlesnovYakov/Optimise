#pragma once
#include "AbstrOptimiser.h"
#include <vector>
#include "VectorOper.h"
/// <summary>
///	\brief Класс-наследник класса AbstrOptimiser, выполняющий роль нахождения минимума функции с помощью градиентного спуска.

///<summary>
class DetOpt :
    public AbstrOptimiser
{
public:
    void optimise(vec& point, AbstrFunc* Func, AbstrStop* S, RectArea& Shape);
    // <summary>
/// \brief Данный метод считает численно градиент функции в точке.
/// \param point - точка, в которой считаем градиент.
/// \param Func - функция, градиент в точке которой ищем.
/// \param Shape - параллелепипед.
/// </summary>
    vec CalcGradient(vec& point, AbstrFunc& Func, RectArea& Shape);
    // <summary>
/// \brief Данный метод (золотое сечение) считает следующий шаг направления градиентного спуска.
/// \param a - начало интервала, в котором ищем следующий шаг направления градиентного спуска.
/// \param b - конец интервала, в котором ищем следующий шаг направления градиентного спуска.
/// \param gradient - градиент, посчитанный в точке.
/// \param point - текущая точка направления.
/// \param Func - функция, которую минизируем.
/// </summary>
    double GoldenSelection(double a, double b, vec& gradient, vec& point, AbstrFunc* Func);
    // <summary>
    /// \brief Данный метод находит конец интервал, в котором ищем следующий шаг направления градиентного спуска.
    /// \param point - текущая точка направления.
    /// \param gradient - градиент, посчитанный в точке.
    /// \param Shape - параллелепипед.
    /// </summary>
    double CountB(vec& point, vec& gradient, RectArea& Shape);

};

