#include <stdio.h>

// �Լ� ����
int plus(int a, int b);
int minus(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
int mod(int a, int b);

int main(void) {
    int num1, num2;

    printf("�� ���� �Է�: ");
    scanf_s("%d %d", &num1, &num2);

    printf("����: %d + %d = %d\n", num1, num2, plus(num1, num2));
    printf("����: %d - %d = %d\n", num1, num2, minus(num1, num2));
    printf("����: %d * %d = %d\n", num1, num2, multiply(num1, num2));

    if (num2 != 0) {
        printf("������: %d / %d = %.2f\n", num1, num2, divide(num1, num2));
        printf("������: %d %% %d = %d\n", num1, num2, mod(num1, num2));
    }
    else {
        printf("0���� ���� �� �����ϴ�!\n");
    }

    return 0;
}

// �Լ� ����
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