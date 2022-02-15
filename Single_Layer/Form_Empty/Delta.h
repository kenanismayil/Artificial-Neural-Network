#pragma once
#include "Resource.h"

#define IS_EQUAL(x, y) (((x) < (y) + 0.4f && (x) > (y) - 0.4f)? 1 : 0)


int delta(Samples, double*, double);
