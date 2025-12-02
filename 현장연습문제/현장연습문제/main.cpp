#include <stdio.h>
#include <math.h>

#define SIZE 10

void sortDescending(float arr[], int size, int sortedIdx[]);
void calculateStats(float arr[], int size, float* avg, float* var, float* stdDev);
void assignRanks(float arr[], int size, int ranks[]);

int main() {
    float data[SIZE];
    int ranks[SIZE];
    float avg, var, stdDev;

    // 10개 실수 입력 받기
    printf("실수 10개를 입력하세요:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf_s("%f", &data[i]);
    }

    // 통계 계산
    calculateStats(data, SIZE, &avg, &var, &stdDev);

    // 순위 계산
    assignRanks(data, SIZE, ranks);

    // 결과 출력
    printf("순번\t입력값\t순위\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t%.2f\t%d\n", i + 1, data[i], ranks[i]);
    }

    printf("전체 데이터 평균: %.2f\n", avg);
    printf("전체 데이터 분산: %.2f\n", var);
    printf("전체 데이터 표준편차: %.2f\n", stdDev);

    return 0;
}

// 평균, 분산, 표준편차 계산 함수
void calculateStats(float arr[], int size, float* avg, float* var, float* stdDev) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    *avg = sum / size;

    float sumSqDiff = 0.0;
    for (int i = 0; i < size; i++) {
        sumSqDiff += (arr[i] - *avg) * (arr[i] - *avg);
    }
    *var = sumSqDiff / size;
    *stdDev = sqrt(*var);
}

// 순위 계산 함수 (내림차순, 값이 클수록 1등)
void assignRanks(float arr[], int size, int ranks[]) {
    for (int i = 0; i < size; i++) {
        ranks[i] = 1; // 1등부터 시작
        for (int j = 0; j < size; j++) {
            if (arr[j] > arr[i]) {
                ranks[i]++;
            }
        }
    }
}