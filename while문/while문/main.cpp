#include <stdio.h>

int gcd_while(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    printf("ù ��° ���� �Է�: ");
    scanf_s("%d", &a);
    printf("�� ��° ���� �Է�: ");
    scanf_s("%d", &b);

    int gcd = gcd_while(a, b);
    int lcm = (a * b) / gcd;

    printf("�ִ�����(GCD): %d\n", gcd);
    printf("�ּҰ����(LCM): %d\n", lcm);

    return 0;
}