#include "main.h"
#include <string.h>

int main(void) {
    char str1[20] = "character array.";
    char str2[] = "character array......";
    char ch;
    unsigned int len;
    int karsilastir;

    len = strlen(str1);
    len = sizeof(str1);
    len = strlen(str2);
    len = sizeof(str2);

    ch = str1[6];
    ch = str1[9];
    karsilastir = strcmp(str1, str2);

    str2[0] = 'k';
    str2[16] = '\0';
    karsilastir = strcmp(str1, str2);
    ch = str2[17];
}
