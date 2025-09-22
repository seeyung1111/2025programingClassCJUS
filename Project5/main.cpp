#include <stdio.h>

int main(void) 
{
    int age = 21;
    unsigned int count = 3000000000;
    float score = 93.5f;
    const char* title = "Basic Constants";
    const char* name = "Seeyung";
    char initial = name[0];
    printf("= %s =\n name \t : %s\n initial : %c\n Age : %d\n score \t %.6f\n count \t : %u\n",
        title, name, initial, age, score, count);
    return 0;
}