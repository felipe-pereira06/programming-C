#include <stdio.h>
int main() 
{
    float a, b, x;
    printf("Digite o valor de a: ");
    scanf("%f", &a);
    printf("Digite o valor de b: ");
    scanf("%f", &b);
        x = -b/a;
        printf("x = %.1f\n", x);
    return 0;
}