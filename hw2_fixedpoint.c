#include <stdio.h>

int main() {

    int i = 1;

    /*
    This program checks whether the system uses
    one's complement or two's complement for integers.

    In two's complement system,
    negative number is represented as (~i + 1).

    So if -i equals (~i + 1),
    the system is using two's complement.
    */

    if (-i == (~i + 1))
    {
        printf("Two's complement system.\n");
    }
    else
    {
        printf("One's complement system.\n");
    }

    return 0;
}
