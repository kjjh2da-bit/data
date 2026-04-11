#include <stdio.h>
#include <time.h>

// 1. 순환적반복문 방법

long long fibo_iterative(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;
    
    long long a = 1, b = 1, temp;
    for (int i = 3; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// 2. 재귀적방법

long long fibo_recursive(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;
    
    // 자기 자신을 두 번씩 계속 호출합니다.
    return fibo_recursive(n - 1) + fibo_recursive(n - 2);
}

int main() {
    int max_n = 42; 
    clock_t start, end;
    double time_iter, time_rec;

    printf("피보나치 수열 프로파일링 (N=1 ~ %d)\n", max_n);
    printf("----------------------------------------------------\n");
    printf("N\t순환(반복) 시간\t\t재귀 시간\n");
    printf("----------------------------------------------------\n");

    for (int n = 1; n <= max_n; n++) {
        // [순환적 방법 측정]
        start = clock();
        fibo_iterative(n);
        end = clock();
        time_iter = (double)(end - start) / CLOCKS_PER_SEC * 1000.0; // ms 단위 변환

        // [재귀적 방법 측정]
        start = clock();
        fibo_recursive(n);
        end = clock();
        time_rec = (double)(end - start) / CLOCKS_PER_SEC * 1000.0; // ms 단위 변환

        
        printf("%d\t%.3f ms\t\t%.3f ms\n", n, time_iter, time_rec);
    }
    printf("----------------------------------------------------\n");

    return 0;
}
