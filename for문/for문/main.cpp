#include <stdio.h>

void gugudan_for(int dan) {
    if (dan == 0) {
        for (int d = 2; d <= 9; d++) {
            printf("--- %d�� ---\n", d);
            for (int i = 1; i <= 9; i++) {
                printf("%d x %d = %d\n", d, i, d * i);
            }
            printf("\n");
        }
    }
    else if (dan >= 2 && dan <= 9) {
        printf("--- %d�� ---\n", dan);
        for (int i = 1; i <= 9; i++) {
            printf("%d x %d = %d\n", dan, i, dan * i);
        }
    }
    else {
        printf("2~9 ���� ���� �Ǵ� 0�� �Է��ϼ���.\n");
    }
}

int main() {
    int dan;
    printf("����� ������ �ܼ� �Է� (2~9, 0�� ��ü ���): ");
    scanf_s("%d", &dan);

    gugudan_for(dan);
    return 0;
}