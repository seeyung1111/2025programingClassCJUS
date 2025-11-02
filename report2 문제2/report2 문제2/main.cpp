#define _CRT_SECURE_NO_WARNINGS  // Visual Studio의 scanf 보안 경고 비활성화

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char doorStatusInput;   // 문 상태 ('O' for Open, 'C' for Closed)
    double temperature;     // 현재 온도 (섭씨)
    int doorOpenDuration;   // 문이 열려있던 시간 (초)

    // 1. 문 상태 입력
    printf("문 상태를 입력하세요 (O: 열림, C: 닫힘): ");
    if (scanf(" %c", &doorStatusInput) != 1) {
        printf("invalid input: 문 상태 입력이 잘못되었습니다.\n");
        exit(1);
    }

    // 2. 현재 온도 입력
    printf("현재 온도를 입력하세요 (섭씨): ");
    if (scanf("%lf", &temperature) != 1) {
        printf("invalid input: 온도 입력이 잘못되었습니다.\n");
        exit(1);
    }

    // 3. 문 열림 시간 입력
    printf("문이 열려있던 시간을 입력하세요 (초): ");
    if (scanf("%d", &doorOpenDuration) != 1) {
        printf("invalid input: 시간 입력이 잘못되었습니다.\n");
        exit(1);
    }

    // 4. 입력값 유효성 검사
    if ((doorStatusInput != 'O' && doorStatusInput != 'C') ||
        doorOpenDuration < 0 || temperature < -50 || temperature > 100) {
        printf("invalid input: 유효하지 않은 입력입니다. (문 상태, 시간, 온도 범위 확인)\n");
        exit(1);
    }

    // 5. 상태 판단 로직
    printf("\n--- 백신 냉장고 상태 판정 ---\n");

    if (doorStatusInput == 'O') {
        // 문이 열린 상태
        if (doorOpenDuration >= 60 && (temperature < 2.0 || temperature > 8.0)) {
            printf("결과: Critical (문이 열려 있고, 온도 이상 + 60초 이상)\n");
        }
        else {
            printf("결과: Normal (문이 열려 있지만 위험 조건은 아님)\n");
        }
    }
    else { // 문이 닫힌 상태 ('C')
        if (temperature >= 2.0 && temperature <= 8.0) {
            printf("결과: Normal (온도 정상 범위)\n");
        }
        else {
            if (doorOpenDuration <= 30) {
                printf("결과: Warning (온도 이상이지만 문 닫힘 + 30초 이하)\n");
            }
            else {
                printf("결과: Critical (온도 이상 + 문 닫힘 상태 30초 초과)\n");
            }
        }
    }

    // 콘솔창 닫힘 방지
    system("pause");
    return 0;
}