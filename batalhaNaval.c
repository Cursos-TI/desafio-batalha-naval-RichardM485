// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Nível Novato

#include <stdio.h>
#include <ctype.h> // Biblioteca necessária para a função toupper

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
    char LetraControl; // Variável para armazenar a letra da coluna inserida pelo usuário

    printf("Batalha Naval - Tabuleiro Inicial\n");
    exibirtabuleiro();
    printf("\n");
    printf("Escolha a posição que deseja colocar seu navio (coluna A-J e linha 1-10)\n");
    printf("Exemplo de preenchimento: B2\n");
    printf("Esse navio deverá ocupar 3 posições consecutivas na horizontal:\n");

    for (int i = 0; i < 3; i++){
        if (scanf(" %c%d", &LetraControl, &linha) != 2) { // Verifica se a entrada possui o formato correto
            int c; while ((c = getchar()) != '\n' && c != EOF); // Limpa buffer e pede de novo
            printf("Entrada inválida! Use formato B2 ou B 2. Tente novamente.\n"); 
            i--; // Decrementa i para repetir a iteração
            continue;
        }
        LetraControl = (char) toupper((unsigned char)LetraControl); // Essa linha converte a letra para maiúscula
        coluna = (LetraControl - 'A') + 1; // Converte 'A'->1, 'B'->2, utilizando a tabela ASCII.
        if (linha < 1 || linha > 10 || coluna < 1 || coluna > 10){
            printf("Posição inválida! Use A-J para coluna e 1-10 para linha. Tente novamente.\n");
            i--; // Decrementa i para repetir a iteração
            continue;
        } else if(tabuleiro[linha - 1][coluna - 1] == 3){
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
        if (scanf(" %c%d", &LetraControl, &linha) != 2) { // Verifica se a entrada possui o formato correto
            int c; while ((c = getchar()) != '\n' && c != EOF); // Limpa buffer e pede de novo
            printf("Entrada inválida! Use formato B2 ou B 2. Tente novamente.\n"); 
            i--; // Decrementa i para repetir a iteração
            continue;
        }
        LetraControl = (char) toupper((unsigned char)LetraControl); // Essa linha converte a letra para maiúscula
        coluna = (LetraControl - 'A') + 1; // Converte 'A'->1, 'B'->2, utilizando a tabela ASCII.
        if (linha < 1 || linha > 10 || coluna < 1 || coluna > 10){
            printf("Posição inválida! Use A-J para coluna e 1-10 para linha. Tente novamente.\n");
            i--; // Decrementa i para repetir a iteração
            continue;
        } else if(tabuleiro[linha - 1][coluna - 1] == 3){
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
    printf("Agora posicione dois navios na diagonal no tabuleiro\n");
    printf("Cada navio ocupará 3 posições consecutivas na diagonal:\n");
    printf("Primeiro navio diagonal:\n");
    for (int i = 0; i < 3; i++){
        if (scanf(" %c%d", &LetraControl, &linha) != 2) { // Verifica se a entrada possui o formato correto
            int c; while ((c = getchar()) != '\n' && c != EOF); // Limpa buffer e pede de novo
            printf("Entrada inválida! Use formato B2 ou B 2. Tente novamente.\n"); 
            i--; // Decrementa i para repetir a iteração
            continue;
        }
        LetraControl = (char) toupper((unsigned char)LetraControl); // Essa linha converte a letra para maiúscula
        coluna = (LetraControl - 'A') + 1; // Converte 'A'->1, 'B'->2, utilizando a tabela ASCII.
        if (linha < 1 || linha > 10 || coluna < 1 || coluna > 10){
            printf("Posição inválida! Use A-J para coluna e 1-10 para linha. Tente novamente.\n");
            i--; // Decrementa i para repetir a iteração
            continue;
        } else if(tabuleiro[linha - 1][coluna - 1] == 3){
            printf("Posição já ocupada! Escolha outra posição.\n");
            i--; // Decrementa i para repetir a iteração
            continue;
        }
        tabuleiro[linha - 1][coluna - 1] = 3;
    }
    printf("Segundo navio diagonal:\n");
    for (int i = 0; i < 3; i++){
        if (scanf(" %c%d", &LetraControl, &linha) != 2) { // Verifica se a entrada possui o formato correto
            int c; while ((c = getchar()) != '\n' && c != EOF); // Limpa buffer e pede de novo
            printf("Entrada inválida! Use formato B2 ou B 2. Tente novamente.\n"); 
            i--; // Decrementa i para repetir a iteração
            continue;
        }
        LetraControl = (char) toupper((unsigned char)LetraControl); // Essa linha converte a letra para maiúscula
        coluna = (LetraControl - 'A') + 1; // Converte 'A'->1, 'B'->2, utilizando a tabela ASCII.
        if (linha < 1 || linha > 10 || coluna < 1 || coluna > 10){
            printf("Posição inválida! Use A-J para coluna e 1-10 para linha. Tente novamente.\n");
            i--; // Decrementa i para repetir a iteração
            continue;
        } else if(tabuleiro[linha - 1][coluna - 1] == 3){
            printf("Posição já ocupada! Escolha outra posição.\n");
            i--; // Decrementa i para repetir a iteração
            continue;
        }
        tabuleiro[linha - 1][coluna - 1] = 3;
    }
    printf("\nBatalha Naval - Tabuleiro Final\n");
    exibirtabuleiro();
    printf("\n");

    // Até então não fiz uma validação para garantir que os navios fiquem realmente na diagonal
    // Ou na horizontal/vertical. Porém como não foi solicitado, deixei assim mesmo.
    // Mas daria para fazer uma verificação extra para garantir isso.
    return 0;
}