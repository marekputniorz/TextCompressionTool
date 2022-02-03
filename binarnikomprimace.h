#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int binarni_komprimace(FILE* input,FILE* output) {

char nasledujiciznak;
char predchoziznak = fgetc(input);
uint8_t count = 1;      //unsigned
int znakint;
int inbyte = 0;
int outbyte = 0;
int isempty = 0;
int byty;



    inbyte++;

    while((nasledujiciznak=fgetc(input))!= EOF) {
    
        inbyte++;


        if(predchoziznak==nasledujiciznak) {
        
            if(count==255) {
            
                znakint = predchoziznak;                         // znak do intu

                fwrite(&count,sizeof(uint8_t),1,output);         // vypsani cisla
                fwrite(&znakint,sizeof(uint8_t),1,output);       // vypsani znaku v ascii

                count = 0;
                outbyte+=((sizeof(uint8_t)*2));
                }


            count++;
            predchoziznak=nasledujiciznak;

        }
             else {
        
                znakint = predchoziznak;


                fwrite(&count,sizeof(uint8_t),1,output);
                fwrite(&znakint,sizeof(uint8_t),1,output);

                count = 1;
                predchoziznak = nasledujiciznak;
                outbyte += ((sizeof(uint8_t)*2));
            }

    }

    znakint = predchoziznak;


    fwrite(&count,sizeof(uint8_t),1,output);
    fwrite(&znakint,sizeof(uint8_t),1,output);

    outbyte += ((sizeof(uint8_t)*2));





    if(isempty==1) {
        byty = 0;
    }

    else  byty = (inbyte - outbyte);

    return byty;

}
