#pragma once
#include <vector>
using vec = std::vector<double>;

/// <summary>
/// \brief Parent class - Function, which is responsible for simulating an n-dimensional function.
/// </summary>
class AbstrFunc
{
public:
	/// <summary>
/// \brief This method is designed to take the value of an n-dimensional function at a point.
/// \param f is the point at which the function value will be taken.
/// </summary>
	virtual double GetValF(vec f)  = 0;
	/// <summary>
/// \brief This method is designed to return dimension of function.
/// </summary>
	virtual int getDimension() const = 0;
	~AbstrFunc() {}
};

