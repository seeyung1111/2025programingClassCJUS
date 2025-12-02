#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void generateRandom(int* arr, int size, int min, int max);
int extractRange(int* src, int size, int* dst, int low, int high);
double calcMean(int* arr, int n);
double calcVariance(int* arr, int n, double mean);

int main() {
    int arr[100];
    int extracted[100];
    char buffer[100];
    int min = 1, max = 100;
    int low, high;

    srand((unsigned)time(NULL));

    // 1) 난수 생성
    generateRandom(arr, 100, min, max);

    // 2) 안전한 범위 입력
    while (1) {
        printf("추출할 범위 입력 (예: 10 30, 하나만 입력하면 최대값 사용): ");
        fgets(buffer, sizeof(buffer), stdin);

        int n = sscanf(buffer, "%d %d", &low, &high);

        if (n == 2) {
            // 두 숫자 입력됨 → 그대로 사용
            break;
        }
        else if (n == 1) {
            // 한 숫자만 입력됨 → high를 최대값으로 설정
            high = max;
            break;
        }

        // 입력 오류
        printf("입력 오류! 정수 한 개 또는 두 개를 입력하세요.\n");
    }

    // 3) 범위 내 값 추출
    int count = extractRange(arr, 100, extracted, low, high);

    if (count < 10) {
        printf("해당 범위의 값이 10개보다 적습니다.\n");
        return 0;
    }

    printf("\n추출된 10개 값:\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", extracted[i]);

    // 4) 통계 계산
    double mean = calcMean(extracted, 10);
    double var = calcVariance(extracted, 10, mean);
    double stddev = sqrt(var);

    printf("\n\n합: %.2f\n", mean * 10);
    printf("평균: %.2f\n", mean);
    printf("분산: %.2f\n", var);
    printf("표준편차: %.2f\n", stddev);

    return 0;
}

// ?? 난수 생성 함수
void generateRandom(int* arr, int size, int min, int max) {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % (max - min + 1) + min;
}

// ?? 범위 내 값 추출 함수
int extractRange(int* src, int size, int* dst, int low, int high) {
    int count = 0;
    for (int i = 0; i < size; i++)
        if (src[i] >= low && src[i] <= high)
            dst[count++] = src[i];
    return count;
}

// ?? 평균 계산 함수
double calcMean(int* arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum / n;
}

// ?? 분산 계산 함수
double calcVariance(int* arr, int n, double mean) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += (arr[i] - mean) * (arr[i] - mean);
    return sum / n;
}