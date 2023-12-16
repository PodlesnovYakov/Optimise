#pragma once
#include "AbstrOptimiser.h"
#include <vector>
#include "VectorOper.h"
/// <summary>
///	\brief A descendant class of the AbstrOptimiser class, which performs the role of finding the minimum of a function using gradient descent.

///<summary>
class DetOpt :
    public AbstrOptimiser
{
public:
    void optimise(vec& point, AbstrFunc* Func, AbstrStop* S, RectArea& Shape);
    // <summary>
/// \brief This method calculates numerically the gradient of a function at a point.
/// \param point - the point at which we calculate the gradient.
/// \param Func - function, the gradient at the point of which we are looking for.
/// \param Shape - parallelepiped.
/// </summary>
    vec CalcGradient(vec& point, AbstrFunc& Func, RectArea& Shape);
    // <summary>
/// \brief This method (golden ratio) considers the next step in the direction of gradient descent.
/// \param a is the beginning of the interval in which we are looking for the next step in the gradient descent direction.
/// \param b - the end of the interval in which we are looking for the next step in the direction of gradient descent.
/// \param gradient - gradient calculated at a point.
/// \param point - current direction point.
/// \param Func is the function that we are minimizing.
/// </summary>
    double GoldenSelection(double a, double b, vec& gradient, vec& point, AbstrFunc* Func);
    // <summary>
    /// \brief This method finds the end of the interval in which we are looking for the next step in the gradient descent direction.
    /// \param point - current direction point.
    /// \param gradient - gradient calculated at a point.
    /// \param Shape - parallelepiped.
    /// </summary>
    double CountB(vec& point, vec& gradient, RectArea& Shape);

};

