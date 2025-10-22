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
    printf("ù ��° ���� �Է�: ");
    scanf_s("%d", &a);
    printf("�� ��° ���� �Է�: ");
    scanf_s("%d", &b);

    int gcd = gcd_dowhile(a, b);
    int lcm = (a * b) / gcd;

    printf("�ִ�����(GCD): %d\n", gcd);
    printf("�ּҰ����(LCM): %d\n", lcm);

    return 0;
}