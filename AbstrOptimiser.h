#pragma once
#include "AbstrFunc.h"
#include "AbstrStop.h"
#include "RectArea.h"
/// <summary>
/// \brief ������������ ����� - �����������, ������� �������� �� ���������� �������� �������.
/// </summary>
class AbstrOptimiser
{
public:
	// <summary>
/// \brief ������ ����� ������������ ��� ���������� �������� n-������ �������.
/// \param point - ��������� �����, �� ������� �������� �����.
/// \param Func - �������, ������� ������� �� ����.
/// \param S - �������, �� �������� ����� ��������� ������������.
/// \param Shape - n-������ ��������������.
/// </summary>
	virtual void optimise(vec& point, AbstrFunc* Func, AbstrStop* S, RectArea& Shape) = 0;
    
};

