#ifndef MY_FRACTION_H
#define MY_FRACTION_H

// 'C로 배우는 자료구조' 스타일로 깔끔하게 구조체 정의
typedef struct {
    int num; // 분자
    int den; // 분모
} Fraction;

Fraction reduce_fraction(Fraction f);
Fraction parse_fraction(const char* str);
void print_fraction(Fraction f);

Fraction add_fraction(Fraction f1, Fraction f2);
Fraction sub_fraction(Fraction f1, Fraction f2);
Fraction mul_fraction(Fraction f1, Fraction f2);
Fraction div_fraction(Fraction f1, Fraction f2);

#endif
