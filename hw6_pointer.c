#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    srand((unsigned int)time(NULL));

   
    printf("배열 크기 N을 입력하세요: ");
    scanf("%d", &n);

    // 크기가 N인 정수 배열 동적 할당
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    int total = 0;
    
    // 0 ~ N 사이의 임의의 수로 배열 채우기
    for (int i = 0; i < n; i++) {
        *(arr + i) = rand() % (n + 1);
    }

    
    printf("\n--- 1) 배열 출력 ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }

    // 뒤에서부터 처음까지 출력
    printf("\n\n--- 뒤에서부터 출력 ---\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }

    // 총합, 최대값, 최소값
    int max_val = *(arr + 0);
    int min_val = *(arr + 0);
    for (int i = 0; i < n; i++) {
        total += *(arr + i);
        if (*(arr + i) > max_val) max_val = *(arr + i);
        if (*(arr + i) < min_val) min_val = *(arr + i);
    }
    printf("\n\n총합: %d / 최대: %d / 최소: %d\n", total, max_val, min_val);

    // 1차원 배열 메모리 해제
    free(arr); 


    // 2. 홀수 마방진 (2차원 동적 할당 및 이중 포인터)
    int magic_n;
    printf("\n------------------------------------\n");
    printf("마방진 크기 N을 입력하세요 (홀수): ");
    scanf("%d", &magic_n);

    if (magic_n % 2 == 0) {
        printf("홀수만 입력 가능합니다.\n");
        return 0;
    }

    // N * N 크기의 2차원 배열 동적 할당 (포인터의 포인터 배열)
    int **board = (int **)malloc(magic_n * sizeof(int *));
    for (int i = 0; i < magic_n; i++) {
        *(board + i) = (int *)malloc(magic_n * sizeof(int));
        
        // 배열 전체를 0으로 초기화
        for (int j = 0; j < magic_n; j++) {
            *(*(board + i) + j) = 0;
        }
    }

    int r = 0;
    int c = magic_n / 2;

    // 마방진 채우기 알고리즘
    for (int num = 1; num <= magic_n * magic_n; num++) {
        *(*(board + r) + c) = num; // 현재 위치에 숫자 대입
        
        int nr = r - 1;
        int nc = c + 1;

        if (nr < 0) nr = magic_n - 1;
        if (nc >= magic_n) nc = 0;

        
        if (*(*(board + nr) + nc) != 0) {
            r = r + 1;
            if (r >= magic_n) r = 0;
        } else {
            r = nr;
            c = nc;
        }
    }

    // 마방진 배열 출력
    printf("\n--- 2) %dx%d 마방진 ---\n", magic_n, magic_n);
    for (int i = 0; i < magic_n; i++) {
        for (int j = 0; j < magic_n; j++) {
            printf("%3d ", *(*(board + i) + j));
        }
        printf("\n");
    }

    // 가로/세로/대각선 합 검증 출력
    printf("\n[합계 검증]\n");
    int d1 = 0, d2 = 0;
    for (int i = 0; i < magic_n; i++) {
        int r_sum = 0, c_sum = 0;
        for (int j = 0; j < magic_n; j++) {
            r_sum += *(*(board + i) + j); // 가로 합
            c_sum += *(*(board + j) + i); // 세로 합
            
            if (i == j) d1 += *(*(board + i) + j);
            if (i + j == magic_n - 1) d2 += *(*(board + i) + j);
        }
        printf("%d행 합: %d, %d열 합: %d\n", i + 1, r_sum, i + 1, c_sum);
    }
    printf("대각선1 합: %d, 대각선2 합: %d\n", d1, d2);

    // 2차원 배열 메모리 해제 (안쪽부터 순차적으로 해제)
    for (int i = 0; i < magic_n; i++) {
        free(*(board + i));
    }
    free(board);

    return 0;
}
