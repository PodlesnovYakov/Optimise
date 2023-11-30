#include "GradStop.h"
bool GradStop::Stop()
{
    bool flag = true;
    if (norma(grad) < eps) {
        flag = false;
    }
    return flag;
}
