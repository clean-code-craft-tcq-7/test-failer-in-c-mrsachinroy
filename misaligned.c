#include <stdio.h>
#include <assert.h>
#include "string.h"
#include "stdlib.h"


//converting into string
const char* ConvertToString(int ColourCode, const char* MajorClr[], const char* MinorClr[] )
{
    char retString[20] = {};
    sprintf(retString,"%d",ColourCode);
    strcat(retString," | ");
    strcat(retString,MajorClr[0]);
    strcat(retString," | ");
    strcat(retString,MinorClr[0]);
    const char * ptrretString = retString;
    return ptrretString;
}


int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    const char *ptrPrintString = NULL;
    int indx = 0;
    char TstString[7] = {};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {

            ptrPrintString = ConvertToString(i * 5 + j, majorColor+i, minorColor+i);
            printf("%s \n",ptrPrintString);

            if (i > 0)
            {
                //testing for repeating of minor colour value for consecutive colour code 
                assert(strcmp(TstString,ptrPrintString + (strlen(ptrPrintString) - 6)));
            }
            strcpy(TstString,ptrPrintString + (strlen(ptrPrintString) - 6));
        }
    }
    return i * j;
}

int main() {
    
    int result = printColorMap();

    return 0;
}