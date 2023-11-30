#include "F2.h"

double F2::GetValF(vec f)
{
    return exp(f[0]/2)*(f[0]+f[1]*f[1]);
    
}
