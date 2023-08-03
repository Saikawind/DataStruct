#include <stdio.h>

int main() {
    int i = 5;
    float f = i / 2;
    printf("%f\n", f);
    float k = (float) i / 2;
    printf("%f\n", k);

    return 0;
}