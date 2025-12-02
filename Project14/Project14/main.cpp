#include <stdio.h>
#include <math.h>

#define SIZE 10

void inputData(double data[], int size) {
    printf("10개의 실수를 입력하세요:\n");
    for (int i = 0; i < size; i++) {
        printf("%d번째 데이터: ", i + 1);
        scan_f("%lf", &data[i]);
    }
}

double calcMean(double data[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

double calcVariance(double data[], int size, double mean) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (data[i] - mean) * (data[i] - mean);
    }
    return sum / size;
}

void rankData(double data[], int size, int rank[]) {
    for (int i = 0; i < size; i++) {
        rank[i] = 1; // 초기 순위 1로 설정
        for (int j = 0; j < size; j++) {
            if (data[j] > data[i]) {
                rank[i]++;
            }
        }
    }
}

void printResults(double data[], int rank[], int size, double mean, double variance, double stddev) {
    printf("\n순번\t입력값\t순위\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%.3lf\t%d\n", i + 1, data[i], rank[i]);
    }
    printf("\n전체 데이터 평균: %.3lf\n", mean);
    printf("전체 데이터 분산: %.3lf\n", variance);
    printf("전체 데이터 표준편차: %.3lf\n", stddev);
}

int main() {
    double data[SIZE];
    int rank[SIZE];
    inputData(data, SIZE);

    double mean = calcMean(data, SIZE);
    double variance = calcVariance(data, SIZE, mean);
    double stddev = sqrt(variance);

    rankData(data, SIZE, rank);
    printResults(data, rank, SIZE, mean, variance, stddev);

    return 0;
}