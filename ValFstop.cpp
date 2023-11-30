#include "ValFstop.h"

bool ValFstop::Stop()
{
    bool flag = true;
    if (abs(fcur - fprev) < eps) {
        flag = false;
    }
    return flag;
}
