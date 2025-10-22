#include <stdio.h>

int gcd_dowhile(int a, int b) {
    int temp;
    do {
        temp = b;
        b = a % b;
        a = temp;
    } while (b != 0);
    return a;
}

int main() {
    int a, b;
    printf("첫 번째 숫자 입력: ");
    scanf_s("%d", &a);
    printf("두 번째 숫자 입력: ");
    scanf_s("%d", &b);

    int gcd = gcd_dowhile(a, b);
    int lcm = (a * b) / gcd;

    printf("최대공약수(GCD): %d\n", gcd);
    printf("최소공배수(LCM): %d\n", lcm);

    return 0;
}