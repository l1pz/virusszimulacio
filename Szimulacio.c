#include "Szimulacio.h"

void szimulacio(Ember **emberek, int lakossag_gyok, float alfa, float beta, float gamma, bool veletlen_keveredes,
                int idoegyeseg, FILE *kimenet) {
    int lakossag = lakossag_gyok * lakossag_gyok;
    int beteg = veletlen_keveredes ? (int) ((float) lakossag * KEZDETBEN_BETEG) : 9;
    int erzekeny = lakossag - beteg;
    int gyogyult = 0;

    for (int i = 0; i < lakossag; ++i) {
        init_ember(emberek[i]);
    }
    init_betegek(emberek, lakossag_gyok, beteg, veletlen_keveredes);
    fprintf(kimenet,
            "N\t%d\nlakossag\t%d\nalfa (megbetegedesi valoszinuseg)\t%f\nbeta (gyogyulasi valoszinuseg)\t%f\ngamma (oltva megbetegedesi valoszinuseg)\t%f\nveletlen_keveredes\t%d\n",
            N, lakossag_gyok * lakossag_gyok, alfa, beta, gamma, veletlen_keveredes);
    fprintf(kimenet, "idoegyseg\tbeteg\terzekeny\tgyogyult\n");
    for (int i = 0; i < N; ++i) {
        Ember *ember = emberek[random_int(lakossag)];
        Ember *partner;
        switch (ember->allapot) {
            case BETEG:
                if (random_float() <= beta) {
                    ember->allapot = GYOGYULT;
                    --beteg;
                    ++gyogyult;
                }

                break;
            case ERZEKENY:
                partner = partner_kivalaszt(ember, emberek, lakossag, veletlen_keveredes);
                if (partner->allapot == BETEG && random_float() <= alfa) {
                    ember->allapot = BETEG;
                    --erzekeny;
                    ++beteg;
                }
                break;
            default:
                break;
        }

        if (i % idoegyeseg == 0) {
            float beteg_arany = (float) beteg / (float) lakossag;
            float erzekeny_arany = (float) erzekeny / (float) lakossag;
            float gyogyult_arany = (float) gyogyult / (float) lakossag;
            /*fprintf(kimenet, "%d\t%.3f\t%.3f\t%.3f\n",
                    i, beteg_arany, erzekeny_arany, gyogyult_arany);*/
            fprintf(kimenet, "%d\t%d\t%d\t%d\n",
                    i, beteg, erzekeny, gyogyult);
        }
    }
    fprintf(kimenet, "\n");


}

void init_betegek(Ember **emberek, int lakossag_gyok, int betegek, bool veletlen_keveredes) {
    if (veletlen_keveredes) {
        for (int i = 0; i < betegek; ++i) {
            emberek[i]->allapot = BETEG;
        }
    } else {
        int center = lakossag_gyok / 2;
        for (int y = 0; y < 3; ++y) {
            for (int x = 0; x < 3; ++x) {
                emberek[koordbol_index(center + x, center + y, lakossag_gyok)]->allapot = BETEG;
            }
        }
    }
}

void init_negyzethalo(Ember **emberek, int lakossag_gyok) {
    int lakossag = lakossag_gyok * lakossag_gyok;
    for (int i = 0; i < lakossag; ++i) {
        int x = i % lakossag_gyok;
        int y = i / lakossag_gyok;
        emberek[i]->kapcsolatok[0] = emberek[koordbol_index(balra_vagy_fel(x, lakossag_gyok), y, lakossag_gyok)];
        emberek[i]->kapcsolatok[1] = emberek[koordbol_index(jobbra_vagy_le(x, lakossag_gyok), y, lakossag_gyok)];
        emberek[i]->kapcsolatok[2] = emberek[koordbol_index(x, balra_vagy_fel(y, lakossag_gyok), lakossag_gyok)];
        emberek[i]->kapcsolatok[3] = emberek[koordbol_index(x, jobbra_vagy_le(y, lakossag_gyok), lakossag_gyok)];
    }
}

Ember *partner_kivalaszt(Ember *ember, Ember **emberek, int lakossag, bool veletlen_keveredes) {
    Ember *partner;
    if (veletlen_keveredes) {
        do {
            partner = emberek[random_int(lakossag)];
        } while (ember == partner);
    } else {
        partner = ember->kapcsolatok[random_int(4)];
    }
    return partner;
}

int balra_vagy_fel(int c, int lakossag_gyok) {
    return (--c < 0) ? lakossag_gyok - 1 : c;
}

int jobbra_vagy_le(int c, int lakossag_gyok) {
    return (++c >= lakossag_gyok) ? 0 : c;
}

int koordbol_index(int x, int y, int lakossag_gyok) {
    return x + (y * lakossag_gyok);
}

