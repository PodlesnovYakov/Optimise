#pragma once
#include "AbstrStop.h"
/// <summary>
///	\brief �����-��������� ������ AbstrStop, ���������� �� ��������� �� �������� ��������� � ����������� ������.

///<summary>
class GradStop :
    public AbstrStop
{
public:
    bool Stop() override;
};

