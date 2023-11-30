#pragma once
#include <vector>
using vec = std::vector<double>;

/// <summary>
///	\brief Родительский класс - остановка, который отвечает за остановку для нахождения минимума.
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
/// \brief Данный метод ищет эвклидову норму вектора
/// \param f - вектор, эвклидову норму которого хотим найти
/// </summary>
    double norma(vec& f);
protected:
    
    /// эпсилон, меньше которого произойдёт остановка
    double eps;
    /// максимальное количество итераций
    int kmax;
    /// текущее значение итерации
    int kcur;
    /// значение функции в предыдущей найденной точке
    double fprev;
    /// значение функции в текущей найденной точке
    double fcur;
    /// предыдущая точка
    vec prevpoint;
    /// текущая точка
    vec curpoint;
    /// значение градиента в текущей точке
    vec grad;
    
};

