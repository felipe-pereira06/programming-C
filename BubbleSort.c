#include <stdio.h>
int main() {
    int vetor[100];
    int n, i, j, aux;
    int trocou;
    printf("Quantos elementos o vetor tera? ");
    scanf("%d", &n);
    printf("Digite os %d elementos:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    i = n - 1;
    trocou = 1;

    while (i > 0 && trocou == 1) {
        trocou = 0;
        for (j = 0; j < i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                trocou = 1;
            }
        }
        i--;
    }

    printf("\nVetor ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}