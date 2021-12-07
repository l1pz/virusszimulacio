#include <stdlib.h>
#include "Ember.h"
#include "Seged.h"

Ember *uj_ember() {
    Ember *ember = malloc(sizeof *ember);
    ember->kapcsolatok = malloc(4 * sizeof *ember->kapcsolatok);
    init_ember(ember);
    return ember;
}

void init_ember(Ember *ember) {
    ember->allapot = ERZEKENY;
    ember->oltott = false;
}

