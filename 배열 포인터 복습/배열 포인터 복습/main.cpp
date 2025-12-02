#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// 정렬 방향 선택용 enum
typedef enum { ASCENDING, DESCENDING } Order;

// 배열 출력 함수 (입력/출력 직접 결정)
void PrintArray(float* arr, int size) {
    printf("배열 내용:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// 정렬 함수: 오름차순/내림차순 선택 가능
void CalcSortArray(float* arr, int size, Order order) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((order == ASCENDING && arr[i] > arr[j]) ||
                (order == DESCENDING && arr[i] < arr[j])) {
                float tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

// 랜덤 실수 생성 예시, -100.0 ~ 100.0 범위
void GenerateRandomArray(float* arr, int size) {
    // 시드 초기화는 main에서 한 번만 하자
    for (int i = 0; i < size; i++) {
        float r = (float)rand() / RAND_MAX; // 0~1 실수 생성
        arr[i] = r * 200.0f - 100.0f;      // -100 ~ +100 변환
    }
}

int main() {
    float data[SIZE];

    srand((unsigned int)time(NULL));  // rand 시드 초기화

    GenerateRandomArray(data, SIZE);
    printf("생성된 랜덤 배열 (출력 전): \n");
    PrintArray(data, SIZE);

    // 오름차순 정렬
    CalcSortArray(data, SIZE, ASCENDING);
    printf("오름차순 정렬 결과: \n");
    PrintArray(data, SIZE);

    // 내림차순 정렬
    GenerateRandomArray(data, SIZE);
    printf("새로 생성된 랜덤 배열 (출력 전): \n");
    PrintArray(data, SIZE);

    CalcSortArray(data, SIZE, DESCENDING);
    printf("내림차순 정렬 결과: \n");
    PrintArray(data, SIZE);

    return 0;
}