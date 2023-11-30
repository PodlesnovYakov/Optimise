#include "AbstrStop.h"

double AbstrStop::norma(vec& f)
{
    double sum = 0;
    for (auto iter : f) {
        sum += iter * iter;
    }
    return sqrt(sum);
}
