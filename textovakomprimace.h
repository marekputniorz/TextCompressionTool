#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int textova_komprimace(FILE* input, FILE* output) {

char nasledujiciznak;
char predchoziznak = fgetc(input);
int count = 1;
char tostring[2];
int inbyte = 1;
int outbyte = 0;
int isempty = 0;
int byty;




    while ((nasledujiciznak = fgetc(input)) != EOF) {       // pokud neni konec filu

        inbyte++;                                           // + byte v input file

        if (predchoziznak==nasledujiciznak) {

            if (count==9) {
                
                sprintf(tostring, "%d", count);              // int to string pro spravne zobrazeni cisla
                fputc(tostring[0], output);                  // vypsani cisla
                fputc(predchoziznak, output);                // vypsani znaku

                count = 0;
                outbyte += 2;                               // +2 byty v output file (cislo+pismeno)
                }

            count++;
            predchoziznak = nasledujiciznak;

    }
        else
            {
                sprintf(tostring, "%d", count);
                fputc(tostring[0], output);
                fputc(predchoziznak, output);

                count = 1;
                predchoziznak = nasledujiciznak;
                outbyte += 2;
            }

    }

    sprintf(tostring, "%d", count);
    fputc(tostring[0], output);
    fputc(predchoziznak, output);

    outbyte += 2;

    if (isempty==1) {

        byty = 0;
    }

    byty = (inbyte - outbyte);


    return byty;
}

