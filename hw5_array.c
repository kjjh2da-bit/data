#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    srand((unsigned int)time(NULL));

    
    printf("배열 크기 N을 입력하세요: ");
    scanf("%d", &n);

    // 동적 할당 대신 가변 길이 배열 방식
    int data[100]; // 넉넉하게 선언
    int total = 0;

    printf("\n--- 1) 배열 출력 ---\n");
    for (int i = 0; i < n; i++) {
        data[i] = rand() % (n + 1);
        printf("%d ", data[i]);
    }

    printf("\n\n--- 뒤에서부터 출력 ---\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", data[i]);
    }

    int max_val = data[0];
    int min_val = data[0];
    for (int i = 0; i < n; i++) {
        total += data[i];
        if (data[i] > max_val) max_val = data[i];
        if (data[i] < min_val) min_val = data[i];
    }
    printf("\n\n총합: %d / 최대: %d / 최소: %d\n", total, max_val, min_val);


    // 2. 홀수 마방진
    printf("\n--- 2) %dx%d 마방진 ---\n", n, n);
    if (n % 2 == 0) {
        printf("홀수만 입력 가능합니다.\n");
        return 0;
    }

    int board[20][20] = {0}; // 2차원 배열 선언
    int r = 0;
    int c = n / 2;

    for (int num = 1; num <= n * n; num++) {
        board[r][c] = num;
        
        // 마방진 이동 규칙
        int nr = r - 1;
        int nc = c + 1;

        if (nr < 0) nr = n - 1;
        if (nc >= n) nc = 0;

        if (board[nr][nc] != 0) {
            r = r + 1;
            if (r >= n) r = 0;
        } else {
            r = nr;
            c = nc;
        }
    }

    // 출력 및 검증
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", board[i][j]);
        }
        printf("\n");
    }

    // 가로/세로/대각선 합 출력
    printf("\n[합계 검증]\n");
    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++) {
        int r_sum = 0, c_sum = 0;
        for (int j = 0; j < n; j++) {
            r_sum += board[i][j];
            c_sum += board[j][i];
            if (i == j) d1 += board[i][j];
            if (i + j == n - 1) d2 += board[i][j];
        }
        printf("%d행 합: %d, %d열 합: %d\n", i+1, r_sum, i+1, c_sum);
    }
    printf("대각선1 합: %d, 대각선2 합: %d\n", d1, d2);

    return 0;
}
