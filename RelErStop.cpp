#include "RelErStop.h"

bool RelErStop::Stop()
{
    bool flag = true;
    ;
    if (std::abs((fcur-fprev)/fcur) < eps) {
        flag = false;
    }
    return flag;
}
