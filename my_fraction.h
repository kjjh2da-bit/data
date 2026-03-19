#ifndef MY_FRACTION_H
#define MY_FRACTION_H

typedef struct {
    int num; 
    int den; 
} Fraction;

Fraction reduce_fraction(Fraction f);
Fraction parse_fraction(const char* str);
void print_fraction(Fraction f);

Fraction add_fraction(Fraction f1, Fraction f2);
Fraction sub_fraction(Fraction f1, Fraction f2);
Fraction mul_fraction(Fraction f1, Fraction f2);
Fraction div_fraction(Fraction f1, Fraction f2);

#endif
