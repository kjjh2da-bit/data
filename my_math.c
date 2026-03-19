#include "my_math.h"

// [최대공약수] 유클리드 호제법
int get_gcd(int a, int b) {
    int temp;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// [최소공배수] (A * B) / GCD
int get_lcm(int a, int b) {
    if (a == 0 || b == 0) return 0; 
    int gcd = get_gcd(a, b);
    return (a / gcd) * b; 
}
