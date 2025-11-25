#include <stdio.h>
//a
int soma_vetor(int *V, int n) {
    int soma = 0;
    int *ptr = V; 
    for (int i = 0; i < n; i++) {
        soma += *(ptr + i);
    }
    return soma;
//b
}
int tamanho_string(char *S) {
    char *ptr = S;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - S;
}
int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    char texto[] = "felipe pereira";
    printf("soma do vetor: %d\n", soma_vetor(vetor, n));
    printf("tamanho da string: %d\n", tamanho_string(texto));
    return 0;
}