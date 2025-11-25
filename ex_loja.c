#include <stdio.h>
int main() {
    float matriz[5][4] = {
        {1245.00, 1160.00, 1334.00, 513.00},
        {726.00, 1409.00, 953.00, 838.00},
        {501.00, 769.00, 1328.00, 1497.00},
        {799.00, 1141.00, 757.00, 1242.00},
        {1253.00, 809.00, 1462.00, 1263.00}
    };
    int linhas = 5, colunas = 4;
    float total_vendas = 0;
    float total_semana[4] = {0};
    float total_vendedores[5] = {0};

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            total_vendas += matriz[i][j];
            total_semana[j] += matriz[i][j];
            total_vendedores[i] += matriz[i][j];
        }
    }

    printf("Total de vendas foi R$%.2f\n\n", total_vendas);
    printf("VENDAS DA SEMANA");
    printf("\n");
    for (int j = 0; j < colunas; j++) 
    {
        printf("Total de vendas da semana %d foi R$%.2f\n", j+1, total_semana[j]);
    }
    printf("\n");
    printf("TOTAL DE VENDAS POR VENDEDOR");
    printf("\n");
    printf("Total de vendas do vendedor Alencar foi R$%.2f\n", total_vendedores[0]);
    printf("Total de vendas do vendedor Meireles foi R$%.2f\n", total_vendedores[1]);
    printf("Total de vendas do vendedor Verissimo foi R$%.2f\n", total_vendedores[2]);
    printf("Total de vendas do vendedor Machado foi R$%.2f\n", total_vendedores[3]);
    printf("Total de vendas do vendedor Lobato foi R$%.2f\n", total_vendedores[4]);
    printf("\n");

    for (int j = 0; j < colunas; j++) {
        float maior_venda = 0;
        for (int i = 0; i < linhas; i++) {
            if (matriz[i][j] > maior_venda) {
                maior_venda = matriz[i][j];
            }
        }
        printf("Semana %d teve a maior venda de R$%.2f\n", j+1, maior_venda);
    }
    float maior_total_semana = 0;
    int semana_mais_lucrativa = 0;

    for (int j = 0; j < colunas; j++) {
        if (total_semana[j] > maior_total_semana) {
            maior_total_semana = total_semana[j];
            semana_mais_lucrativa = j;
        }
    }

    printf("\nSemana mais lucrativa: Semana %d com R$%.2f\n", semana_mais_lucrativa + 1, maior_total_semana);

    // salário 10	85,29%	dos vendedores
    float salario_fixo = 2000.00;
    float maior_salario = 0;
    int vendedor_maior_salario = -1;

    for (int i = 0; i < linhas; i++) {
        float salario_vendedor = salario_fixo + 0.1 * total_vendedores[i];
        if (salario_vendedor > maior_salario) {
            maior_salario = salario_vendedor;
            vendedor_maior_salario = i;
        }
    }
    char* nomes_vendedores[] = {"Alencar", "Meireles", "Verissimo", "Machado", "Lobato"};
    
    printf("\nVendedor que recebeu o maior salário: %s com R$%.2f\n", nomes_vendedores[vendedor_maior_salario], maior_salario);
    float lucro_total = total_vendas;
    for (int i = 0; i < linhas; i++) {
        lucro_total -= salario_fixo + 0.1 * total_vendedores[i];
    }
    printf("\nLucro total da loja: R$%.2f\n", lucro_total);
    printf("\n");
    return 0;
}