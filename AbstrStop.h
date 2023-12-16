#pragma once
#include <vector>
using vec = std::vector<double>;

/// <summary>
///	\brief The parent class is stop, which is responsible for stopping to find the minimum.
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
    ~AbstrStop(){}
    // <summary>
/// \brief This method searches for the Euclidean norm of the vector
/// \param f is the vector whose Euclidean norm we want to find
/// </summary>
    double norma(vec& f);
protected:
    
    /// epsilon, less than which the stop occurs
    double eps;
    /// maximum number of iterations
    int kmax;
    /// current iteration value
    int kcur;
    /// the value of the function at the previous found point
    double fprev;
    /// function value at the current found point
    double fcur;
    /// previous point
    vec prevpoint;
    /// current point
    vec curpoint;
    /// gradient value at the current point
    vec grad;
    
};

