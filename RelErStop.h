#pragma once
#include "AbstrStop.h"
/// <summary>
///	\brief �����-��������� ������ AbstrStop, ���������� �� ��������� �� ������������� ������ ���� ��������� �������� ������� � ����������� ������.

///<summary>
class RelErStop :
    public AbstrStop
{
public:
    bool Stop() override;
};

