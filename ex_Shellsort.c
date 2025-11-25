#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

#define tchave int

typedef struct {
    tchave codigo;   
    float valor;
    char categoria;
} registro;

typedef struct {
    tchave chave;
    long pos;
} chave_pos;

typedef struct {
    int tamanho;
    chave_pos *item;
} tabela;

tabela cria_tabela() {
    chave_pos *tc;
    tabela tab;
    FILE *arq;
    registro reg;
    int qtd_reg, i = 0;

    arq = fopen("produtos.jlf", "rb");
    if (arq == NULL) {
        puts("Erro ao abrir o arquivo produtos.jlf");
        exit(1);
    }

    fseek(arq, 0, SEEK_END);
    int tamanho_arquivo = ftell(arq);
    qtd_reg = tamanho_arquivo / sizeof(registro);
    rewind(arq);

    tc = (chave_pos *) malloc(sizeof(chave_pos) * qtd_reg);
    tab.tamanho = qtd_reg;
    tab.item = tc;

    while (!feof(arq)) {
        tc[i].pos = ftell(arq);
        if (fread(&reg, sizeof(registro), 1, arq) != 1) break;
        tc[i].chave = reg.codigo;
        i++;
    }

    fclose(arq);
    return tab;
}

void shell_sort(tabela t) {
    int i, j, gap;
    chave_pos temp;
    chave_pos *v = t.item;
    int n = t.tamanho;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = v[i];
            for (j = i; j >= gap && v[j - gap].chave > temp.chave; j -= gap) {
                v[j] = v[j - gap];
            }
            v[j] = temp;
        }
    }
}

int main() {	
    tabela T;
    FILE *arq_idx;	
    int n;

    T = cria_tabela();
    shell_sort(T);

    arq_idx = fopen("produtos.idx", "wb");
    if (arq_idx == NULL) {
        puts("Erro ao criar arquivo produtos.idx");
        exit(1);
    }

    n = fwrite(T.item, sizeof(chave_pos), T.tamanho, arq_idx);
    if (n == T.tamanho)
        puts("Arquivo produtos.idx gravado com sucesso");
    else
        puts("Erro na gravacao do arquivo");

    fclose(arq_idx);
    return 0;
}
