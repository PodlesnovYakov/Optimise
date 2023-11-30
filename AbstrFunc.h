#pragma once
#include <vector>
using vec = std::vector<double>;

/// <summary>
/// \brief ������������ ����� - �������, ������� �������� �� �������� n-������ �������.
/// </summary>
class AbstrFunc
{
public:
	/// <summary>
/// \brief ������ ����� ������������ ��� ������ �������� n-������ ������� � �����.
/// \param f - �����, � ������� ����� ����� �������� �������.
/// </summary>
	virtual double GetValF(vec f)  = 0;
};

