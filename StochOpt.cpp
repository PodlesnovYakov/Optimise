#include "StochOpt.h"
unsigned seed = 0;
std::mt19937 gen(seed);
void StochOpt::optimise(vec& point, AbstrFunc* Func, AbstrStop* S, RectArea& Shape)
{
    vec prevpoint(point);
    vec curpoint(point);
    int kcur = 0;
    double fcur = 0;
    double fprev = 0;
    
    do {
        vec model_point;
        vec Bup(curpoint + delta);
        vec Bdown(curpoint - delta);
        
        std::uniform_real_distribution<double> modp(0, 1);

        if (modp(gen) < p) {
            intersection(Bup, Bdown, Shape);
            model_point = ModelPoint(Bdown, Bup);
        }
        else model_point = ModelPoint(Shape.GetLower(), Shape.GetUpper());

        if (Func->GetValF(model_point) < Func->GetValF(curpoint)) {
   
            delta = delta * alpha;
            prevpoint = curpoint;
            curpoint = model_point;
            fprev = Func->GetValF(prevpoint);
            fcur = Func->GetValF(curpoint);
        } 
        ++kcur;
        S->Setkcur(kcur);
        
    } while (S->Stop() || curpoint == point);
    S->Setcur(curpoint);
    
}

void StochOpt::intersection(vec& Bup, vec& Bdown, RectArea& Shape)
{

    vec Upper(Shape.GetUpper());
    vec Lower(Shape.GetLower());
    
    for (int i = 0; i < Bup.size(); ++i) {
        Bdown[i] = std::max(Bdown[i], Lower[i]);
        Bup[i] = std::min(Bup[i], Upper[i]);
    }

}

vec StochOpt::ModelPoint(vec& Bdown, vec& Bup)
{
    vec curpoint(Bdown.size());
    for (int i = 0; i < curpoint.size(); ++i)
    {
        std::uniform_real_distribution<double> modpoint(Bdown[i], Bup[i]);
        curpoint[i] = modpoint(gen);
    }
    return curpoint;
}
