#pragma execution_character_set("utf-8")
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>    
#include "my_math.h" 

// [피보나치 수열] 
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
   
    int i, j, fn, fn_minus_1;
    clock_t start, end;
    double time_taken;

    system("chcp 65001 > nul"); 

    printf("조교님 힌트 적용: 피보나치 GCD 프로파일링\n");
    printf("--------------------------------------------------\n");
    printf("순서(n)\t 계산 형태\t\t 걸린 시간(ms)\n");
    printf("--------------------------------------------------\n");

    for (i = 5; i <= 45; i++) {
        fn = get_fibo(i);
        fn_minus_1 = get_fibo(i - 1);

        // 시간 측정 시작
        start = clock();

        // 1000만 번 반복 (시간 증폭기)
        for (j = 0; j < 10000000; j++) {
            get_gcd(fn, fn_minus_1);
        }

        // 시간 측정 끝
        end = clock();

        time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

        printf("n=%d\t GCD(%d, %d)\t %.2f ms\n", i, fn, fn_minus_1, time_taken);
    }
    printf("--------------------------------------------------\n");

    return 0;
}
