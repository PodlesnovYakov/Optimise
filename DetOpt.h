#pragma once
#include "AbstrOptimiser.h"
#include <vector>
#include "VectorOper.h"
/// <summary>
///	\brief �����-��������� ������ AbstrOptimiser, ����������� ���� ���������� �������� ������� � ������� ������������ ������.

///<summary>
class DetOpt :
    public AbstrOptimiser
{
public:
    void optimise(vec& point, AbstrFunc* Func, AbstrStop* S, RectArea& Shape);
    // <summary>
/// \brief ������ ����� ������� �������� �������� ������� � �����.
/// \param point - �����, � ������� ������� ��������.
/// \param Func - �������, �������� � ����� ������� ����.
/// \param Shape - ��������������.
/// </summary>
    vec CalcGradient(vec& point, AbstrFunc& Func, RectArea& Shape);
    // <summary>
/// \brief ������ ����� (������� �������) ������� ��������� ��� ����������� ������������ ������.
/// \param a - ������ ���������, � ������� ���� ��������� ��� ����������� ������������ ������.
/// \param b - ����� ���������, � ������� ���� ��������� ��� ����������� ������������ ������.
/// \param gradient - ��������, ����������� � �����.
/// \param point - ������� ����� �����������.
/// \param Func - �������, ������� ����������.
/// </summary>
    double GoldenSelection(double a, double b, vec& gradient, vec& point, AbstrFunc* Func);
    // <summary>
    /// \brief ������ ����� ������� ����� ��������, � ������� ���� ��������� ��� ����������� ������������ ������.
    /// \param point - ������� ����� �����������.
    /// \param gradient - ��������, ����������� � �����.
    /// \param Shape - ��������������.
    /// </summary>
    double CountB(vec& point, vec& gradient, RectArea& Shape);

};

