#pragma once
#include <vector>
using vec = std::vector<double>;

/// <summary>
/// \brief Родительский класс - Функция, который отвечает за имитацию n-мерной функции.
/// </summary>
class AbstrFunc
{
public:
	/// <summary>
/// \brief Данный метод предназначен для взятия значения n-мерной функции в точке.
/// \param f - точка, в которой будет взято значение функции.
/// </summary>
	virtual double GetValF(vec f)  = 0;
};

