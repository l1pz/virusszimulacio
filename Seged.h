#ifndef VIRUSSZIMULACIO_SEGED_H
#define VIRUSSZIMULACIO_SEGED_H

#include <stdlib.h>

#define N 10000
#define KAPACITAS 100
#define KORHAZ 0.05f
#define INTEZKEDESI_LIMIT KAPACITAS / KORHAZ
#define KEZDETBEN_BETEG 0.001f

float random_float();

int random_int(int max);

#endif //VIRUSSZIMULACIO_SEGED_H
