#pragma once
#include "AbstrStop.h"
/// <summary>
///	\brief �����-��������� ������ AbstrStop, ���������� �� ��������� �� ���������� �������� � ����� ������� ������ ��������.

///<summary>
class StopIter :
    public AbstrStop
{
    bool Stop() override;
};

