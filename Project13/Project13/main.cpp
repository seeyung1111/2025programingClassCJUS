#include <stdio.h>

// ÇÔ¼ö ¼±¾ğ
int plus(int a, int b);
int minus(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
int mod(int a, int b);

int main(void) {
    int num1, num2;

    printf("µÎ ¼ıÀÚ ÀÔ·Â: ");
    scanf_s("%d %d", &num1, &num2);

    printf("µ¡¼À: %d + %d = %d\n", num1, num2, plus(num1, num2));
    printf("»¬¼À: %d - %d = %d\n", num1, num2, minus(num1, num2));
    printf("°ö¼À: %d * %d = %d\n", num1, num2, multiply(num1, num2));

    if (num2 != 0) {
        printf("³ª´°¼À: %d / %d = %.2f\n", num1, num2, divide(num1, num2));
        printf("³ª¸ÓÁö: %d %% %d = %d\n", num1, num2, mod(num1, num2));
    }
    else {
        printf("0À¸·Î ³ª´­ ¼ö ¾ø½À´Ï´Ù!\n");
    }

    return 0;
}

// ÇÔ¼ö Á¤ÀÇ
int plus(int a, int b) {
    return a + b;
}

int minus(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / b;
}

int mod(int a, int b) {
    return a % b;
}