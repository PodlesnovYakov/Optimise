#pragma once
#include "AbstrOptimiser.h"
#include "VectorOper.h"
#include <random>
extern std::mt19937 gen;
/// <summary>
///	\brief A descendant class of the AbstrOptimiser class, which performs the role of finding the minimum of a function using a random search.

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
/// \brief This method finds the intersection of the delta neighborhood of a point and a parallelepiped.
/// \param Bdown is the lowest point of the delta neighborhood.
/// \param Bup is the highest point of the delta neighborhood.
/// \param Shape - parallelepiped.
/// </summary>
    void intersection(vec& Bup, vec& Bdown, RectArea& Shape);
    // <summary>
/// \brief This method uniformly models a point at the intersection of the delta neighborhood of a point and a parallelepiped.
/// \param Bdown - the lowest point of intersection.
/// \param Bup is the upper intersection point.
/// </summary>
    vec ModelPoint(vec& Bdown, vec& Bup);

private:
    /// Coefficient that reduces the delta neighborhood of a point
    double alpha;
    /// The probability with which we model a uniform point in a parallelepiped
    double p;
    /// Delta neighborhood of a point
    vec delta;
};

