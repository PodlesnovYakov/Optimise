#pragma once
#include <vector>
using vec = std::vector<double>;
/// <summary>
///	\brief ����� - ��������������, � ������� ������ ������� �������.

///<summary>
class RectArea
{
public:
	RectArea(int _AreaSize, vec& _lower_point, vec& _upper_point) : AreaSize(_AreaSize) {
		lower_point.resize(AreaSize);
		upper_point.resize(AreaSize);
		for (int i = 0; i < AreaSize; ++i) {
			lower_point[i] = _lower_point[i];
			upper_point[i] = _upper_point[i];
		}
	}
	void SetLower(vec& _lower_point) {
		lower_point.resize(AreaSize);
		for (int i = 0; i < AreaSize; ++i) {
			lower_point[i] = _lower_point[i];
			
		}
	}
	void SetUpper(vec& _upper_point) {
		upper_point.resize(AreaSize);
		for (int i = 0; i < AreaSize; ++i) {
			upper_point[i] = _upper_point[i];

		}
	}
	void SetSize(int _AreaSize) { AreaSize = _AreaSize; }
	int GetSize() { return AreaSize; }
	vec& GetLower() { return lower_point; }
	vec& GetUpper() { return upper_point; }
protected:
	/// ������ n-������� ���������������.
	int AreaSize;
	/// ������ ����� ���������������.
	vec lower_point;
	/// ������� ����� ���������������.
	vec upper_point;
};

