#include "DetOpt.h"
#include <algorithm>

void DetOpt::optimise(vec& point, AbstrFunc* Func, AbstrStop* S, RectArea& Shape)
{
    vec prevpoint(point);
    double fprev = Func->GetValF(prevpoint);
    vec gradient = CalcGradient(point, *Func, Shape);
    int kcur = 0;
    double fcur;
    double b, lambda;
    do {
        b = CountB(point, gradient, Shape);
        lambda = GoldenSelection(0, b, gradient, point, Func);
        for (int i = 0; i < point.size(); ++i) {
            prevpoint[i] = point[i];
            point[i] = point[i] - lambda * gradient[i];
        }
        fprev = Func->GetValF(prevpoint);
        fcur = Func->GetValF(point);
        ++kcur;
        gradient = CalcGradient(point, *Func, Shape);
        S->SetParams(gradient, prevpoint, point, fprev, fcur, kcur);
    } while (S->Stop() && kcur < S->GetKmax());
    
}
vec DetOpt::CalcGradient(vec& point, AbstrFunc& F, RectArea& Shape)
{
    double h = 0.0001;
    int n = point.size();
    vec plus(n);
    vec minus(n);
    vec lower(Shape.GetLower());
    vec upper(Shape.GetUpper());
    vec gradient(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                if (point[j] + h > upper[j]) plus[j] = point[j];
                else plus[j] = point[j] + h;
                if (point[j] - h < lower[j]) minus[j] = point[j];
                else minus[j] = point[j] - h;
            }
            else {
                plus[j] = point[j];
                minus[j] = point[j];
            }
        }
        gradient[i] = (F.GetValF(plus) - F.GetValF(minus)) / (2 * h);
    }
    return gradient;
}

double Findmin(vec& v) {
    double min = INT_MAX;
    for (auto i : v) {
        if (i >= 0 && i < min) min = i;
    }
    return min;
}

double DetOpt::GoldenSelection(double a, double b, vec& gradient, vec& point, AbstrFunc* Func)
{
    const double fi = 1.6180339887;
    double x1, x2;
    double y1, y2;

    x1 = b - ((b - a) / fi);
    vec promezh = point - gradient * x1;
    y1 = Func->GetValF(promezh);
    
    x2 = a + ((b - a) / fi);
    promezh = point - gradient * x1;
    y2 = Func->GetValF(promezh);
    while (std::abs(b - a) > 0.00001)
    {
        if (y1 <= y2)
        {
            b = x2;
            x2 = x1;
            x1 = b - ((b - a) / fi);
            y2 = y1;
            promezh = point - gradient * x1;
            y1 = Func->GetValF(promezh);
        }
        else
        {
            a = x1;
            x1 = x2;
            x2 = a + ((b - a) / fi);
            y1 = y2;
            promezh = point - gradient * x2;
            y2 = Func->GetValF(promezh);
        }
    }

    return (a + b) / 2;
}
double DetOpt::CountB(vec& point, vec& gradient, RectArea& Shape)
{
    
    vec check(point.size());
    check = (Shape.GetUpper() - point) / (gradient*-1);
    double b1 = Findmin(check);
    
    check = (Shape.GetLower() - point) / (gradient*-1);
    double b2 = Findmin(check);
    
    return std::min(b1,b2);
}

