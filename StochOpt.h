#pragma once
#include "AbstrOptimiser.h"
#include "VectorOper.h"
#include <random>
extern std::mt19937 gen;
/// <summary>
///	\brief �����-��������� ������ AbstrOptimiser, ����������� ���� ���������� �������� ������� � ������� ���������� ������.

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
/// \brief ������ ����� ������� ����������� ������-����������� ����� � ���������������.
/// \param Bdown - ������ ����� ������-�����������.
/// \param Bup - ������� ����� ������-�����������.
/// \param Shape - ��������������.
/// </summary>
    void intersection(vec& Bup, vec& Bdown, RectArea& Shape);
    // <summary>
/// \brief ������ ����� ���������� ���������� ����� � ����������� ������-����������� ����� � ���������������.
/// \param Bdown - ������ ����� �����������.
/// \param Bup - ������� ����� �����������.
/// </summary>
    vec ModelPoint(vec& Bdown, vec& Bup);

private:
    /// �����������, ����������� ������-����������� �����
    double alpha;
    /// �����������, � ������� ���������� ���������� ����� � ���������������
    double p;
    /// ������-����������� �����
    vec delta;
};

