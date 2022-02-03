#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int textova_dekomprimace(FILE* input,FILE* output) {

    char znak;
    int inbyte = 0;
    int outbyte = 0;
    int isempty = 1;
    int byty;
    int pocet;
    char pocetchar;

    while ((pocetchar = fgetc(input)) != EOF) {     // pokud neni konec filu
    
            znak = fgetc(input);

            pocet = (int)pocetchar - 48;            // z ascii do spravne hodnoty (posun 48)

            for (int i = 0; i < pocet; i++, outbyte++) {

                fputc(znak,output);     // zapisujeme znak * pocet, pricitame byty
            }

            inbyte += 2;
            isempty = 0;

        }


    if (isempty == 1) {

        byty = 0;
    }

    else byty = (outbyte - inbyte);

    return byty;

}
