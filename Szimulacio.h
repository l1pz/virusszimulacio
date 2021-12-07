#ifndef VIRUSSZIMULACIO_SZIMULACIO_H
#define VIRUSSZIMULACIO_SZIMULACIO_H

#include "Ember.h"
#include "Seged.h"
#include <stdio.h>

void szimulacio(Ember **emberek, int lakossag_gyok, float alfa, float beta, float gamma, bool veletlen_keveredes,
                int idoegyseg, FILE *kimenet);

void init_betegek(Ember **emberek, int lakossag_gyok, int betegek, bool veletlen_keveredes);

void init_negyzethalo(Ember **emberek, int lakossag_gyok);

Ember *partner_kivalaszt(Ember *ember, Ember **emberek, int lakossag, bool veletlen_keveredes);

int balra_vagy_fel(int c, int lakossag_gyok);

int jobbra_vagy_le(int c, int lakossag_gyok);

int koordbol_index(int x, int y, int lakossag_gyok);

#endif //VIRUSSZIMULACIO_SZIMULACIO_H
