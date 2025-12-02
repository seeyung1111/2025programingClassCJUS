#include <stdio.h>
#include <math.h>

#define DT 0.01        // 시간 간격
#define G 9.81         // 중력 가속도
#define PI 3.14159265358979323846  // π 정의

// 물로켓 위치/속도 구조체
typedef struct {
    double x;
    double y;
    double vx;
    double vy;
} Rocket;

// 위치와 속도 업데이트 함수 (포인터 사용)
void updatePosition(Rocket* r, double dt) {
    r->x += r->vx * dt;
    r->y += r->vy * dt;
    r->vy -= G * dt;  // 중력 작용
}

int main() {
    Rocket rocket;
    double angle = 75.0; // 발사 각도 (deg)
    double speed = 15.0; // 초기 속도 (m/s)

    // 초기 속도 성분 계산
    rocket.vx = speed * cos(angle * PI / 180.0); // PI 사용
    rocket.vy = speed * sin(angle * PI / 180.0);
    rocket.x = 0.0;
    rocket.y = 0.0;

    double maxHeight = rocket.y;
    double time = 0.0;

    // 시간 반복
    while (rocket.y >= 0) {
        updatePosition(&rocket, DT);
        time += DT;
        if (rocket.y > maxHeight) maxHeight = rocket.y;
    }

    printf("체공시간: %.2f sec\n", time);
    printf("최고 도달 높이: %.2f m\n", maxHeight);
    printf("수평 사거리: %.2f m\n", rocket.x);

    return 0;
}