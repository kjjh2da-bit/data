#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_math.h"
#include "my_fraction.h"

// 기약분수 
Fraction reduce_fraction(Fraction f) {
    if (f.den == 0) {
        printf("[에러] 분모는 0이 될 수 없습니다!\n");
        exit(1); 
    }
    
    int gcd = get_gcd(f.num, f.den);
    f.num /= gcd;
    f.den /= gcd;
    
    // 분모가 마이너스면 분자한테 부호 넘겨주기
    if (f.den < 0) {
        f.num = -f.num;
        f.den = -f.den;
    }
    return f;
}

// [글자를 분수로 변신] (가산점 요인 포함)
Fraction parse_fraction(const char* str) {
    Fraction f = {0, 1};
    
    if (strchr(str, '/')) {
        // "3/4" 같은 진짜 분수 형태
        sscanf(str, "%d/%d", &f.num, &f.den);
    } else if (strchr(str, '.')) {
        // "0.5" 같은 소수 형태
        double d;
        sscanf(str, "%lf", &d);
        f.num = (int)(d * 10000.0);
        f.den = 10000;
    } else {
        // "5" 같은 정수 형태
        sscanf(str, "%d", &f.num);
        f.den = 1;
    }
    return reduce_fraction(f); 
}

void print_fraction(Fraction f) {
    f = reduce_fraction(f);
    if (f.den == 1) {
        printf("%d", f.num); // 분모가 1이면 정수만 출력
    } else {
        printf("%d/%d", f.num, f.den);
    }
}

// [분수 더하기] (ad + bc) / bd
Fraction add_fraction(Fraction f1, Fraction f2) {
    Fraction res;
    res.num = (f1.num * f2.den) + (f2.num * f1.den);
    res.den = f1.den * f2.den;
    return reduce_fraction(res);
}

// [분수 빼기]
Fraction sub_fraction(Fraction f1, Fraction f2) {
    Fraction res;
    res.num = (f1.num * f2.den) - (f2.num * f1.den);
    res.den = f1.den * f2.den;
    return reduce_fraction(res);
}

// [분수 곱하기]
Fraction mul_fraction(Fraction f1, Fraction f2) {
    Fraction res;
    res.num = f1.num * f2.num;
    res.den = f1.den * f2.den;
    return reduce_fraction(res);
}

// [분수 나누기]
Fraction div_fraction(Fraction f1, Fraction f2) {
    if (f2.num == 0) {
        printf("[에러] 0으로 나눌 수 없습니다!\n");
        exit(1);
    }
    Fraction res;
    res.num = f1.num * f2.den;
    res.den = f1.den * f2.num;
    return reduce_fraction(res);
}
