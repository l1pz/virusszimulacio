#include "Seged.h"

float random_float() {
    return (float) rand() / RAND_MAX;
}

int random_int(int max) {
    return rand() % max;
}
