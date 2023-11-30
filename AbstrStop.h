#pragma once
#include <vector>
using vec = std::vector<double>;

/// <summary>
///	\brief ������������ ����� - ���������, ������� �������� �� ��������� ��� ���������� ��������.
///<summary>
class AbstrStop
{
public:
	virtual bool Stop() = 0;
    void SetParams(vec& _grad, vec& _prevpoint, vec& _curpoint, double _fprev, double _fcur,int _kcur) {
        Setcur(_curpoint);
        Setprev(_prevpoint);
        Setgrad(_grad);
        Setfcur(_fcur);
        Setfprev(_fprev);
        Setkcur(_kcur);
        
    }
    void Setcur(vec& _curpoint) { curpoint = _curpoint; }
    void Setprev(vec& _prevpoint) { prevpoint = _prevpoint; }
    void Setgrad(vec& _grad) { grad = _grad; }
    void Setfcur(double _fcur) {fcur = _fcur;}
    void Setfprev(double _fprev) {fprev = _fprev;}
    void Setkmax(int _kmax) { kmax = _kmax; }
    void Setkcur(int _kcur) { kcur = _kcur; }
    void Seteps(double _eps) { eps = _eps; }
    vec& GetPoint() { return curpoint; }
    int GetK() { return kcur; }
    int GetKmax() { return kmax; }

    // <summary>
/// \brief ������ ����� ���� ��������� ����� �������
/// \param f - ������, ��������� ����� �������� ����� �����
/// </summary>
    double norma(vec& f);
protected:
    
    /// �������, ������ �������� ��������� ���������
    double eps;
    /// ������������ ���������� ��������
    int kmax;
    /// ������� �������� ��������
    int kcur;
    /// �������� ������� � ���������� ��������� �����
    double fprev;
    /// �������� ������� � ������� ��������� �����
    double fcur;
    /// ���������� �����
    vec prevpoint;
    /// ������� �����
    vec curpoint;
    /// �������� ��������� � ������� �����
    vec grad;
    
};

