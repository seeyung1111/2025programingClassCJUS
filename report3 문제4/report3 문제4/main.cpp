#include <stdio.h>   // 표준 입출력 함수 (printf, scanf_s)
#include <stdlib.h>  // 난수 생성 함수 (rand, srand)
#include <time.h>    // 난수 시드 설정을 위한 time 함수
#include <math.h>    // 수학 함수 (sqrt, pow)

#define COUNT 10      // 생성할 정수의 개수
#define MIN_RANGE 1   // 난수 최소 범위
#define MAX_RANGE 100 // 난수 최대 범위

// 1. 특정 범위 내 난수 하나를 생성하여 반환하는 함수
// num_min (최소값) 과 num_max (최대값) 사이의 난수를 생성합니다.
int generate_random_number(int num_min, int num_max) {
    // (rand() % (num_max - num_min + 1))은 0부터 (num_max - num_min) 사이의 값을 생성합니다.
    // 여기에 num_min을 더하면 num_min부터 num_max 사이의 난수가 됩니다.
    return (rand() % (num_max - num_min + 1)) + num_min;
}

// 2. 배열의 모든 요소의 총합을 계산하여 반환하는 함수
// arr[] (정수 배열) 과 size (배열의 크기)를 입력받습니다.
int calculate_sum(int arr[], int size) {
    int total_sum = 0; // 총합을 저장할 변수 초기화
    for (int i = 0; i < size; i++) { // 배열의 모든 요소에 접근하여
        total_sum += arr[i];         // 총합에 더합니다.
    }
    return total_sum; // 계산된 총합 반환
}

// 3. 배열의 평균을 계산하여 반환하는 함수
// arr[] (정수 배열) 과 size (배열의 크기)를 입력받습니다.
// 평균은 총합을 개수로 나눈 값입니다. float형으로 반환하여 소수점 이하 값도 유지합니다.
float calculate_average(int arr[], int size) {
    int total_sum = calculate_sum(arr, size); // 먼저 총합을 계산합니다.
    return (float)total_sum / size;          // 총합을 크기로 나누어 평균 반환 (float로 형변환 필수)
}

// 4. 배열의 분산을 계산하여 반환하는 함수
// arr[] (정수 배열) 과 size (배열의 크기)를 입력받습니다.
// 분산은 각 데이터가 평균으로부터 얼마나 떨어져 있는지 나타내는 값입니다.
// 편차의 제곱의 평균으로 계산됩니다.
float calculate_variance(int arr[], int size, float avg) {
    float total_diff_sq = 0.0; // 편차 제곱의 총합을 저장할 변수 초기화
    for (int i = 0; i < size; i++) { // 배열의 모든 요소에 대해
        float diff = arr[i] - avg;  // 각 요소와 평균의 차이(편차)를 계산
        total_diff_sq += pow(diff, 2); // 편차를 제곱하여 총합에 더합니다 (pow 함수는 거듭제곱 계산)
    }
    return total_diff_sq / size; // 편차 제곱의 총합을 개수로 나누어 분산 반환
}

// 5. 배열의 표준편차를 계산하여 반환하는 함수
// variance (분산)을 입력받습니다.
// 표준편차는 분산의 양의 제곱근입니다.
float calculate_std_dev(float variance) {
    return sqrt(variance); // sqrt 함수는 제곱근을 계산합니다.
}

// main 함수: 프로그램의 시작점
int main() {
    // 난수 시드 설정: 프로그램 실행 시마다 다른 난수를 생성하도록 현재 시간을 이용합니다.
    srand((unsigned int)time(NULL));

    int numbers[COUNT]; // 10개의 정수를 저장할 배열 선언

    printf("--- 무작위로 생성된 정수 %d개 (---\n", COUNT);
    for (int i = 0; i < COUNT; i++) {
        // generate_random_number 함수를 호출하여 난수를 생성하고 배열에 저장합니다.
        numbers[i] = generate_random_number(MIN_RANGE, MAX_RANGE);
        printf("%d ", numbers[i]); // 생성된 난수 출력
    }
    printf("\n"); // 줄 바꿈

    // 함수들을 사용하여 총합, 평균, 분산, 표준편차 계산
    int total_sum = calculate_sum(numbers, COUNT);
    float average = calculate_average(numbers, COUNT);
    float variance = calculate_variance(numbers, COUNT, average);
    float std_dev = calculate_std_dev(variance);

    printf("--------------------------------------\n");
    printf("총합: %d\n", total_sum);
    printf("평균: %.2f\n", average);    // 소수점 둘째 자리까지 출력
    printf("분산: %.2f\n", variance);   // 소수점 둘째 자리까지 출력
    printf("표준편차: %.2f\n", std_dev); // 소수점 둘째 자리까지 출력
    printf("--------------------------------------\n");

    return 0; // 프로그램 정상 종료
}
