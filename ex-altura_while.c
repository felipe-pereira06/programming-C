#include <stdio.h>
int main() 
{
    float chico = 1.50;
    float ze = 1.10;  
    float cresc_chico = 0.02;
    float cresc_ze = 0.03;
    int anos = 0;

    printf("Ano | Altura de Chico | Altura de Zé\n");
    printf("----|-----------------|--------------\n");

    while (ze < chico) {
        anos += 1;
        chico += cresc_chico;
        ze += cresc_ze;
        printf("%3d         %.2f m         %.2f m\n", anos, chico, ze);
    }

    printf("\nZé será mais alto que Chico em %d anos.\n", anos);
    return 0;
}