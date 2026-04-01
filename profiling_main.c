#include <stdio.h>
#include <stdlib.h>
#include <time.h>    
#include "my_math.h" 

// 피보나치 수열 구하는 함수 (반복문)
int get_fibo(int n) {
    int a = 1, b = 1, temp, i; 
    
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;
    
    for (i = 3; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int i, j;
    int fn, fn_minus_1;
    clock_t start, end;
    double time_taken;

    printf("Fibonacci GCD Profiling\n");
    printf("--------------------------------------------------\n");
    printf("n\t GCD(F(n), F(n-1))\t Time(ms)\n");
    printf("--------------------------------------------------\n");

    // 패턴을 끝까지 보기 위해 60까지 돌림 (오버플로우 관찰용)
    for (i = 5; i <= 60; i++) {
        fn = get_fibo(i);
        fn_minus_1 = get_fibo(i - 1);

        start = clock();

        // 너무 빨리 끝나서 시간 측정을 위해 1000만 번 반복
        for (j = 0; j < 10000000; j++) {
            get_gcd(fn, fn_minus_1);
        }

        end = clock();

        time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

        // 출력
        printf("n=%d\t GCD(%d, %d)\t %.2f ms\n", i, fn, fn_minus_1, time_taken);
    }
    printf("--------------------------------------------------\n");

    return 0;
}
