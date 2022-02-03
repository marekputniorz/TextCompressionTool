#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "textovakomprimace.h"
#include "textovadekomprimace.h"
#include "binarnikomprimace.h"
#include "binarnidekomprimace.h"

int main (int argc, char* argv[]) {

    int j = 1;
    int dekomprimace = 0;
    int binary = 0;
    char* prikaz;
    const char* vstup;
    const char* vystup;
    int isinput = 0;
    int isoutput = 0;


     while (argv[j] != NULL) {
    
        prikaz = argv[j];

        if (prikaz[0] == '-') {
         
            if (prikaz[1] == 'i') {
            j++;
            vstup = argv[j];
            isinput++;

          }

            if (prikaz[1] == 'o') {
            j++;
            vystup = argv[j];
            isoutput++;

         }
            if (prikaz[1] == 'd') {
            dekomprimace = 1;
        }
            if (prikaz[1] == 'b') {
            binary = 1;
        }

    }
        j++;
}

    if (j > 7) {
    
        printf("Chyba: Prilis mnoho argumentu.");
        exit(1);
    }

    if (isinput != 1) {
    
        printf("Chyba: Spatne zadany vstupni soubor.");
        exit(1);
    }
    

    if (isoutput != 1) {
    
        printf("Chyba: Spatne zadany vystupni soubor.");
        exit(1);
    }




    if (binary == 0) {
    
    FILE* input = fopen(vstup,"r");
    assert(input);
    FILE* output = fopen(vystup,"w");
    assert(output);


        if (dekomprimace == 1) {
                
            printf("Soubor je po dekomprimaci o %d bytu vetsi. \n", textova_dekomprimace(input,output));
        }

        else {

             printf("Soubor je po komprimaci o %d bytu mensi. \n ", textova_komprimace(input,output));
             }


    fclose (output); 
    fclose (input);

}

    else if (dekomprimace == 1) {
            
    FILE* input = fopen(vstup,"rb");
    assert(input);
    FILE* output = fopen(vystup,"w");
    assert(output);
 

    printf("Soubor je po dekomprimaci o %d bytu vetsi. \n", binarni_dekomprimace(input,output));

    fclose(output);                          
    fclose(input);
                        

    }

    else {

    FILE* input=fopen(vstup,"r");
    assert(input);
    FILE* output=fopen(vystup,"wb");
    assert(output);

                   
    printf("Soubor je po komprimaci o %d bytu mensi. \n", binarni_komprimace(input,output));

    fclose(output);
    fclose(input);

    }
    return 0;
}
