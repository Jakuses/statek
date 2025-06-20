#include "utils.h"

float utils::random(float _min, float _max)
{
    return rand() % ((int)_max - (int)_min) + _min;
}
