// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Nível Novato

#include <stdio.h>

int tabuleiro[10][10] = {0};
char index_Coluna[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int index_Linha[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//Declaração de variáveis globais para o tabuleiro e índices.

void exibirtabuleiro(){

    //função para exibir o tabuleiro
    printf("   ");
    for(int i = 0; i < 10; i++){
        printf(" %c", index_Coluna[i]);
    }
    printf("\n");
    for(int i = 0; i < 10; i++){
        printf("%2d ", index_Linha[i]);
        for (int j = 0; j < 10; j++){
            printf("%2d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
int main(){

    int linha, coluna;

    printf("Batalha Naval - Tabuleiro Inicial\n");
    exibirtabuleiro();
    printf("\n");
    printf("Escolha a posição que deseja colocar seu navio (linha e coluna)\n");
    printf("Sendo que linha varia de 1 a 10 e coluna de A a J (Ex de preechimento: 1  1)\n");
    printf("Voce escolheu a posição: A1...\n");
    printf("Esse navio deverá ocupar 3 posições consecutivas na horizontal:\n");
    for (int i = 0; i < 3; i++){
        scanf("%d %d", &linha, &coluna);
        if (linha > 10 || linha < 1 || coluna > 10 || coluna < 1){
            printf("Posição inválida! Tente novamente.\n");
            i--; // Decrementa i para repetir a iteração
            continue;
        }else if(tabuleiro[linha - 1][coluna - 1] == 3){
            printf("Posição já ocupada! Escolha outra posição.\n");
            i--; // Decrementa i para repetir a iteração
            continue;
        }
        tabuleiro[linha - 1][coluna - 1] = 3;
    }
    // Coloca um navio na posição escolhida e define o valor 3 para representar o navio
    // Valida a posição se já foi usada e se o valor escolhido não é maior que o tabuleiro
    // Exibir o tabuleiro atualizado
    printf("\nBatalha Naval - Tabuleiro Atualizado\n");
    exibirtabuleiro();
    printf("\n");
    printf("Seguindo a mesma lógica de preenchimento anterior.\n");
    printf("Agora posicione um navio que ocupe 3 posições consecutivas na vertical:\n");
    for (int i = 0; i < 3; i++){
        scanf("%d %d", &linha, &coluna);
        if (linha > 10 || linha < 1 || coluna > 10 || coluna < 1){
            printf("Posição inválida! Tente novamente.\n");
            i--; // Decrementa i para repetir a iteração
            continue;
        }else if(tabuleiro[linha - 1][coluna - 1] == 3){
            printf("Posição já ocupada! Escolha outra posição.\n");
            i--; // Decrementa i para repetir a iteração
            continue;
        }
        tabuleiro[linha - 1][coluna - 1] = 3;
    }
    // Coloca outro navio na posição escolhida e define o valor 3 para representar o navio
    // Valida a posição se já foi usada e se o valor escolhido não é maior que o tabuleiro
    // Exibir o tabuleiro atualizado
    printf("\nBatalha Naval - Tabuleiro Atualizado\n");
    exibirtabuleiro();
    printf("\n");
    return 0;
}
