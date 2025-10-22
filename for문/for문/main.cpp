#include <stdio.h>

void gugudan_for(int dan) {
    if (dan == 0) {
        for (int d = 2; d <= 9; d++) {
            printf("--- %d단 ---\n", d);
            for (int i = 1; i <= 9; i++) {
                printf("%d x %d = %d\n", d, i, d * i);
            }
            printf("\n");
        }
    }
    else if (dan >= 2 && dan <= 9) {
        printf("--- %d단 ---\n", dan);
        for (int i = 1; i <= 9; i++) {
            printf("%d x %d = %d\n", dan, i, dan * i);
        }
    }
    else {
        printf("2~9 사이 숫자 또는 0만 입력하세요.\n");
    }
}

int main() {
    int dan;
    printf("출력할 구구단 단수 입력 (2~9, 0은 전체 출력): ");
    scanf_s("%d", &dan);

    gugudan_for(dan);
    return 0;
}