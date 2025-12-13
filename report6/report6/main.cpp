// Visual Studio 컴파일러 경고 및 정의 문제 해결을 위한 전처리기 지시문
//-----------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS   // scanf_s 사용을 강제하는 경고를 무시합니다.
#define _USE_MATH_DEFINES         // math.h에 정의된 M_PI와 같은 수학 상수들을 사용 가능하게 합니다.
//-----------------------------------------------------------------------------

#include <stdio.h> // 표준 입출력 함수(printf, scanf)를 사용하기 위한 헤더 파일
#include <math.h>  // 수학 함수(sin, cos, pow, M_PI)를 사용하기 위한 헤더 파일

// 상수 정의: 코드 내에서 변하지 않는 값들을 미리 정의하여 가독성을 높이고 유지보수를 쉽게 합니다.
#define GRAVITY 9.81     // 중력 가속도 (단위: m/s^2). 지구에서의 일반적인 값입니다.
#define TIME_STEP 0.1    // 시간 간격 (단위: 초). x, y 좌표를 계산할 때 얼마나 세분화하여 보여줄지 결정합니다.

//=============================================================================
// 함수 선언 (Function Prototypes) - 변경된 부분!
// horizontalRange 매개변수 추가
//=============================================================================
double degToRad(double angleDeg); // 도(degree) 단위를 라디안(radian) 단위로 변환하는 함수
// 이전: void printTrajectory(double initialVelocity, double launchAngleRad, double totalTime);
void printTrajectory(double initialVelocity, double launchAngleRad, double totalTime, double horizontalRange); // 물체의 궤적을 출력하는 함수

//=============================================================================
// 메인 함수 (Main Function)
// 프로그램의 시작점이며, 전체적인 흐름을 제어합니다.
//=============================================================================
int main() {
    // 변수 선언: 필요한 값들을 저장하기 위한 메모리 공간을 확보합니다.
    double initialVelocity;     // 물체의 초기 속도 (m/s)
    double launchAngleDeg;      // 물체의 발사 각도 (도, degree)
    double launchAngleRad;      // 발사 각도를 라디안으로 변환한 값 (radian)

    double maxHeight;           // 물체가 도달하는 최대 높이 (m)
    double totalFlightTime;     // 물체가 땅에 떨어질 때까지의 총 비행 시간 (s)
    double horizontalRange;     // 물체가 도달하는 수평 거리 (m)

    // 사용자 입력 부분
    printf("------------------------------------------\n");
    printf("    포물선 운동 분석 프로그램 시작\n");
    printf("------------------------------------------\n");

    // 초기 속도 입력 받기
    printf("1. 초기 속도를 입력하세요 (m/s): ");
    scanf("%lf", &initialVelocity); // %lf는 double형 변수 입력을 위한 형식 지정자입니다.

    // 발사 각도 입력 받기 (0도 ~ 90도 범위 권장)
    printf("2. 발사 각도를 입력하세요 (도, 0-90): ");
    scanf("%lf", &launchAngleDeg);

    // 입력 유효성 검사: 발사 각도가 유효한 범위(0~90도)에 있는지 확인
    if (launchAngleDeg < 0 || launchAngleDeg > 90) {
        printf("[오류] 발사 각도는 0도에서 90도 사이로 입력해주세요.\n");
        printf("프로그램을 종료합니다.\n");
        return 1; // 오류가 발생했음을 운영체제에 알림 (일반적으로 0은 성공, 0이 아닌 값은 실패를 의미)
    }

    printf("\n--- 입력된 값 ---\n");
    printf("초기 속도: %.2f m/s\n", initialVelocity);
    printf("발사 각도: %.2f 도\n", launchAngleDeg);
    printf("-----------------\n\n");

    // 도 단위를 라디안으로 변환: math.h의 삼각 함수들은 인자로 라디안 값을 요구합니다.
    launchAngleRad = degToRad(launchAngleDeg); // 위에서 선언한 degToRad 함수 호출

    //=============================================================================
    // 주요 파라미터 계산
    // 포물선 운동의 핵심 물리 공식을 사용하여 각 값을 계산합니다.
    //=============================================================================

    // 1. 총 비행 시간 (Total Flight Time, T) 계산: 물체가 발사되어 다시 땅에 떨어질 때까지의 시간
    // 공식: T = (2 * v0 * sin(theta)) / g
    totalFlightTime = (2 * initialVelocity * sin(launchAngleRad)) / GRAVITY;

    // 2. 최대 높이 (Max Height, H) 계산: 물체가 도달하는 가장 높은 지점
    // 공식: H = (v0^2 * sin(theta)^2) / (2 * g)
    maxHeight = (pow(initialVelocity, 2) * pow(sin(launchAngleRad), 2)) / (2 * GRAVITY);

    // 3. 수평 도달 거리 (Horizontal Range, R) 계산: 물체가 수평으로 이동한 총 거리
    // 공식: R = (v0^2 * sin(2 * theta)) / g
    // 또는 R = (v0 * cos(theta)) * T
    horizontalRange = (pow(initialVelocity, 2) * sin(2 * launchAngleRad)) / GRAVITY;
    // 참고: 발사 각도가 90도에 가까울 경우, totalFlightTime이 매우 커져서 오차가 발생할 수 있으므로,
    // 다른 공식을 사용하는 것이 더 정확할 수 있습니다. 여기서는 일반적인 공식을 사용합니다.

    //=============================================================================
    // 계산 결과 출력
    // 계산된 주요 값들을 사용자에게 보기 좋게 출력합니다.
    //=============================================================================
    printf("--- 포물선 운동 분석 결과 ---\n");
    printf("총 비행 시간:   %.2f 초\n", totalFlightTime);
    printf("최대 높이:      %.2f m\n", maxHeight);
    printf("수평 도달 거리: %.2f m\n", horizontalRange);
    printf("----------------------------\n\n");

    // 물체의 궤적 출력: 시간 변화에 따른 x, y 좌표를 표 형태로 출력합니다.
    if (totalFlightTime > 0) { // 비행 시간이 0보다 클 경우에만 궤적을 출력
        // printTrajectory 함수 호출 시 horizontalRange 값도 함께 넘겨줍니다. - 변경된 부분!
        printTrajectory(initialVelocity, launchAngleRad, totalFlightTime, horizontalRange);
    }
    else {
        printf("물체가 즉시 떨어지거나 비행 시간이 없습니다 (발사 각도 0도).\n");
    }

    printf("------------------------------------------\n");
    printf("    포물선 운동 분석 프로그램 종료\n");
    printf("------------------------------------------\n");

    return 0; // 프로그램이 성공적으로 종료되었음을 운영체제에 알림
}

//=============================================================================
// 도 단위를 라디안 단위로 변환하는 함수 구현
// (함수 선언부에서 정의한 내용을 실제 코드로 작성)
//=============================================================================
double degToRad(double angleDeg) {
    // 라디안 = 각도(도) * (M_PI / 180)
    return angleDeg * (M_PI / 180.0); // M_PI 상수를 직접 사용합니다.
}

//=============================================================================
// 물체의 궤적을 출력하는 함수 구현 - 변경된 부분!
// horizontalRange 매개변수 추가
//=============================================================================
void printTrajectory(double initialVelocity, double launchAngleRad, double totalTime, double horizontalRange) {
    double time = 0.0;     // 현재 시간 변수
    double xPosition;      // 현재 x 좌표 (수평 위치)
    double yPosition;      // 현재 y 좌표 (수직 위치)

    // 각도에 따른 초기 수평 및 수직 속도 성분 계산 (상수로 저장하여 반복 계산 줄임)
    double initialVx = initialVelocity * cos(launchAngleRad); // 초기 수평 속도
    double initialVy = initialVelocity * sin(launchAngleRad); // 초기 수직 속도

    printf("--- 시간별 궤적 (x, y 좌표) ---\n");
    printf("  시간(s)  |  x 좌표(m)  |  y 좌표(m)  \n");
    printf("------------------------------------------\n");

    // for 반복문을 사용하여 0초부터 총 비행 시간까지 TIME_STEP 간격으로 x, y 좌표를 계산하고 출력
    // time <= totalTime + TIME_STEP/2는 부동소수점 오차로 인해 마지막 스텝이 누락되는 것을 방지하기 위함
    for (time = 0.0; time <= totalTime + TIME_STEP / 2; time += TIME_STEP) {
        // 수평 위치 (x 좌표) 계산: x = Vx * t
        xPosition = initialVx * time;

        // 수직 위치 (y 좌표) 계산: y = Vy * t - 0.5 * g * t^2
        yPosition = initialVy * time - 0.5 * GRAVITY * pow(time, 2);

        // 물체가 땅에 닿으면 (y 좌표가 0보다 작아지면) 더 이상 출력하지 않고 반복문 종료
        // 부동소수점 오차 때문에 약간 음수가 될 수 있으므로, 매우 작은 음수까지는 허용
        if (yPosition < -0.01 && time > 0.0) {
            yPosition = 0.0; // 땅에 닿았다고 간주하여 y좌표를 0으로 고정

            // 마지막 지점은 totalTime, horizontalRange, 0.0으로 출력
            printf("   %.2f   |   %.2f   |   %.2f   \n", totalTime, horizontalRange, 0.0);
            break;
        }

        printf("   %.2f   |   %.2f   |   %.2f   \n", time, xPosition, yPosition);
    }
    printf("------------------------------------------\n");
}