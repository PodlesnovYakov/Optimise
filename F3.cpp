#include "F3.h"

double F3::GetValF(vec f)
{
	return f[0] * f[0] + f[1] * f[1] + f[2] * f[2] + 2 * f[0] + 4 * f[1] - 6 * f[2];

}

int F3::getDimension() const
{
	return 3;
}
