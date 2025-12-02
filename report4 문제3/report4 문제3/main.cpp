#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputVector(double* v);
double dot(double* a, double* b);
void cross(double* a, double* b, double* result);

int main() {
    double A[3], B[3], C[3];

    printf("벡터 A 입력 (예: 1 2 3): ");
    inputVector(A);

    printf("벡터 B 입력 (예: 1 2 3): ");
    inputVector(B);

    double dotVal = dot(A, B);
    cross(A, B, C);

    printf("\n내적(dot): %.2f\n", dotVal);
    printf("외적(cross): (%.2f, %.2f, %.2f)\n", C[0], C[1], C[2]);

    return 0;
}

void inputVector(double* v) {
    while (1) {
        printf("숫자 3개를 입력하세요: ");

        if (scanf("%lf %lf %lf", &v[0], &v[1], &v[2]) == 3) {
            break;
        }

        printf("입력 오류! 숫자 3개를 다시 입력해주세요.\n");

        while (getchar() != '\n');
    }
}

double dot(double* a, double* b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

void cross(double* a, double* b, double* r) {
    r[0] = a[1] * b[2] - a[2] * b[1];
    r[1] = a[2] * b[0] - a[0] * b[2];
    r[2] = a[0] * b[1] - a[1] * b[0];
}