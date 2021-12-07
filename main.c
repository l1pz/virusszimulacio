#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Szimulacio.h"


int main() {
    srand(time(0));

    bool veletlen_keveredes = false;

    int lakossag_gyok = 100;
    int lakossag = lakossag_gyok * lakossag_gyok;

    Ember **emberek = malloc(lakossag * sizeof *emberek);
    for (int i = 0; i < lakossag; ++i) {
        emberek[i] = uj_ember();
    }
    init_negyzethalo(emberek, lakossag_gyok);

    remove("szimulacio.txt");
    FILE *kimenet = fopen("szimulacio.txt", "a+");

    // Q1
    /*int ertekek_db = 5;
    float ertekek[] = {0.1f, 0.3f, 0.5f, 0.7f, 0.9f};
    for (int alfa_i = 0; alfa_i < ertekek_db; ++alfa_i) {
        for (int beta_i = 0; beta_i < ertekek_db; ++beta_i) {*/
    szimulacio(emberek,
               lakossag_gyok,
               0.3f,
               0.1f,
               0.0f,
               true,
               10,
               kimenet);
    /*}
}*/

    fclose(kimenet);

    return 0;
}
