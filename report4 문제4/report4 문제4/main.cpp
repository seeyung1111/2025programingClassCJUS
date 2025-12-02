#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateLotto(int* lotto);
void inputUser(int* user);
int countMatch(int* lotto, int* user);

int main() {
    int lotto[6], user[6];

    srand((unsigned)time(NULL));

    generateLotto(lotto);
    inputUser(user);

    printf("\n=== 컴퓨터 로또 번호 ===\n");
    for (int i = 0; i < 6; i++)
        printf("%d ", lotto[i]);

    int match = countMatch(lotto, user);

    printf("\n일치 개수: %d\n", match);

    if (match == 6) printf("1등입니다!\n");
    else if (match == 5) printf("2등입니다!\n");
    else if (match == 4) printf("3등입니다!\n");
    else if (match == 3) printf("4등입니다!\n");
    else printf("낙첨입니다.\n");

    return 0;
}

void generateLotto(int* lotto) {
    int used[46] = { 0 };
    for (int i = 0; i < 6; i++) {
        int num;
        do {
            num = rand() % 45 + 1;
        } while (used[num]);
        lotto[i] = num;
        used[num] = 1;
    }
}

void inputUser(int* user) {
    printf("사람 로또 번호 6개 입력: ");
    for (int i = 0; i < 6; i++)
        scanf("%d", &user[i]); // _CRT_SECURE_NO_WARNINGS로 경고 무시
}

int countMatch(int* lotto, int* user) {
    int count = 0;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (lotto[i] == user[j])
                count++;
    return count;
}