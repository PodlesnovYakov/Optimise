#include "StopIter.h"

bool StopIter::Stop()
{
    bool flag = true;
    if (kcur >= kmax) {
        flag = false;
    }
    return flag;
}
