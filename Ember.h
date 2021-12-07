#ifndef VIRUSSZIMULACIO_EMBER_H
#define VIRUSSZIMULACIO_EMBER_H

#include <stdbool.h>

typedef enum Allapot {
    ERZEKENY, BETEG, GYOGYULT
} Allapot;

typedef struct Ember {
    Allapot allapot;
    bool oltott;
    struct Ember **kapcsolatok;
} Ember;

Ember *uj_ember();

void init_ember(Ember *ember);

#endif //VIRUSSZIMULACIO_EMBER_H
