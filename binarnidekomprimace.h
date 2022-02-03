#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int binarni_dekomprimace(FILE* input, FILE* output) {

    int prectene;
    int znak;
    int pocet;
    int inbyte = 0;
    int outbyte = 0;
    int isempty = 1;
    int byty;

    while ((prectene = fread(&pocet,sizeof(uint8_t),1,input)) != EOF) {

            isempty = 0;
            inbyte += sizeof(uint8_t);

            prectene = fread(&znak,sizeof(uint8_t),1,input);
            inbyte += sizeof(uint8_t);


            for(int i = 0; i < pocet; i++) {

                fwrite(&znak,sizeof(uint8_t),1,output);
                
                outbyte++;
            }
        }

    if(isempty==1) {

        byty = 0;
    }
    else byty = (outbyte - inbyte);

    return byty;

}
