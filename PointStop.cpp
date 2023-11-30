#include "PointStop.h"

bool PointStop::Stop()
{
    bool flag = true;
    vec check(curpoint - prevpoint);
    if (norma(check) < eps) {
        flag = false;
    }
    return flag;
}
