#pragma once
#include "AbstrStop.h"
#include "VectorOper.h"
/// <summary>
///	\brief �����-��������� ������ AbstrStop, ���������� �� ��������� �� ���� ��������� ������ � ����������� ������.

///<summary>
class PointStop :
    public AbstrStop
{
public:
    bool Stop() override;
};

