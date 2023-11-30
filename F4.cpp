#include "F4.h"
double F4::GetValF(vec f)
{
    return sin(f[0])*sin(f[0]) + f[1]*f[1] + sin(f[2]-0.5) + f[3]*f[3];
}
