#include "VectorOper.h"
vec operator-(vec v1, vec v2) {

    for (int i = 0; i < v1.size(); ++i) {
        v1[i] -= v2[i];
    }
    return v1;

}
vec operator+(vec v1, vec v2)
{
    for (int i = 0; i < v1.size(); ++i) {
        v1[i] += v2[i];
    }
    return v1;
}
vec operator/(vec v1, vec v2) {

    for (int i = 0; i < v1.size(); ++i) {
        v1[i] /= v2[i];
    }
    return v1;
}
vec operator*(vec v1, double a) {
    for (int i = 0; i < v1.size(); ++i) {
        v1[i] *= a;
    }
    return v1;
}