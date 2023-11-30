#pragma once
#include "AbstrOptimiser.h"
#include "VectorOper.h"
#include <random>
extern std::mt19937 gen;
/// <summary>
///	\brief Класс-наследник класса AbstrOptimiser, выполняющий роль нахождения минимума функции с помощью случайного поиска.

///<summary>
class StochOpt :
    public AbstrOptimiser
    
{
    
public:
    StochOpt(double _alpha, double _p, vec& _delta) {
        alpha = _alpha;
        delta.resize(_delta.size());
        p = _p;
        for (int i = 0; i < _delta.size(); ++i) {
            delta[i] = _delta[i];
        }
    }
    void optimise(vec& point, AbstrFunc* Func, AbstrStop* S, RectArea& Shape);
    // <summary>
/// \brief Данный метод находит пересечение дельта-окрестности точки и параллелепипеда.
/// \param Bdown - нижняя точка дельта-окрестности.
/// \param Bup - верхняя точка дельта-окрестности.
/// \param Shape - параллелепипед.
/// </summary>
    void intersection(vec& Bup, vec& Bdown, RectArea& Shape);
    // <summary>
/// \brief Данный метод моделирует равномерно точку в пересечении дельта-окрестности точки и параллелепипеда.
/// \param Bdown - нижняя точка пересечения.
/// \param Bup - верхняя точка пересечения.
/// </summary>
    vec ModelPoint(vec& Bdown, vec& Bup);

private:
    /// Коэффициент, уменьшающий дельта-окрестность точки
    double alpha;
    /// Вероятность, с которой моделируем равномерно точку в параллелепипеде
    double p;
    /// Дельта-окрестность точки
    vec delta;
};

