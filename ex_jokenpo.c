#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int jogador, computador;
    srand(time(NULL));
    printf("Escolha (1= Pedra, 2= Papel, 3= Tesoura): ");
    scanf("%d", &jogador);

    if (jogador < 1 || jogador > 3) 
    {
        printf("Opção inválida!\n");
        return 1;
    }

    computador = rand() % 3 + 1;
    printf("Você escolheu: %d\n", jogador);
    printf("Computador escolheu: %d\n", computador);

    switch (jogador) 
    {
        case 1: // Pedra
            switch (computador) 
            {
                case 1: printf("Empate!\n"); break;
                case 2: printf("Você perdeu!\n"); break;
                case 3: printf("Você ganhou!\n"); break;
            }
            break;

        case 2: // Papel
            switch (computador) 
            {
                case 1: printf("Você ganhou!\n"); break;
                case 2: printf("Empate!\n"); break;
                case 3: printf("Você perdeu!\n"); break;
            }
            break;

        case 3: // Tesoura
            switch (computador) 
            {
                case 1: printf("Você perdeu!\n"); break;
                case 2: printf("Você ganhou!\n"); break;
                case 3: printf("Empate!\n"); break;
            }
            break;
    }
    return 0;
}