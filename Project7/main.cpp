#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>


int main(void)
{
    int nAge = 99;
    float fHeight = 999.0f;
    double dWeight = 999.0;

    char chTemp = ' ';
    char chString[100] = "";

        //printf("Input your information(Age, Height, Weight):\n");
       // scanf_s("%d%f%lf", &nAge, &fHeight, &dWeight);
    printf("input your alphabet  and word:\n");
    //scanf_s("%c%s", &chTemp, (unsigned int)sizeof(chTemp);
    // chString, (unsigned int)sizeof(chString));
    int nResScanf = scanf("%c%s", &chTemp, chString);

        printf("Output&\n", nResScanf);
       // printf("(Age:%d)(Height:%.2f)(Weight:%.1lf)\n", nAge, fHeight, dWeight);
        printf("(Alphabet:%c)(Word:%s)\n", chTemp, chString);
        return 0;
}