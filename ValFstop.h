#pragma once
#include "AbstrStop.h"
/// <summary>
///	\brief �����-��������� ������ AbstrStop, ���������� �� ��������� �� ���� ��������� ��������� ������� � ��������� ������.

///<summary>
class ValFstop :
    public AbstrStop
{
    bool Stop() override;
};

