// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Nível Mestre

#include <stdio.h>
#include <ctype.h> // Biblioteca necessária para a função toupper

int tabuleiro[10][10] = {0};
int octaedro[3][5];
int cruz[3][5];
int cone[3][5];
char index_Coluna[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int index_Linha[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int linha, coluna;
char LetraControl; // Variável para armazenar a letra da coluna inserida pelo usuário
//Declaração de variáveis globais para o tabuleiro e índices.

void HabCone(){

    // Função para exibir a habilidade cone
    int linhas = 3;
    int colunas = 5;
    int centro = colunas / 2;

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (j >= centro - i && j <= centro + i){
                cone[i][j] = 3;
            } else {
                cone[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%d", cone[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
void HabCruz(){

    // Função para exibir a habilidade cruz
    int linhas = 3;
    int colunas = 5;

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (i == linhas/2 || j == colunas/2){
                cruz[i][j] = 3;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%d", cruz[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
void Haboctaedro(){
    // Função para exibir a habilidade octaedro
    int linhas = 3;
    int colunas = 5;
    int centro = colunas / 2;

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (i == 1){
                if (j >= centro - 1 && j <= centro + 1) 
                    octaedro[i][j] = 3;
                else 
                    octaedro[i][j] = 0;
            } else {
                if (j == centro){
                    octaedro[i][j] = 3;
                } else { 
                    octaedro[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%d", octaedro[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
void Entradauser(){

    //função para entrada do usuário
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
}
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
void Ataqueuser(){
    const int acerto = 5;
    const int erro = 1;
    int escolha;
    int Line;

    printf("Escolha o ataque que deseja realizar:\n");
    printf("1. Cone\n");
    printf("2. Cruz\n");
    printf("3. Octaedro\n");
    if (scanf("%d", &escolha) != 1) {
        int c; while ((c = getchar()) != '\n' && c != EOF);
        printf("Entrada inválida.\n");
        return;
    }
    printf("Escolha a posição que deseja atacar (coluna A-J e linha 1-10). Ex: B2\n");
    if (scanf(" %c%d", &LetraControl, &linha) != 2) {
        int c; while ((c = getchar()) != '\n' && c != EOF);
        printf("Entrada inválida! Use formato B2.\n");
        return;
    }
    LetraControl = (char) toupper((unsigned char)LetraControl);
    coluna = (LetraControl - 'A'); // Converte 'A'->0, 'B'->1, utilizando a tabela ASCII.
    if (linha < 1 || linha > 10 || coluna < 0 || coluna > 9) {
        printf("Coordenada fora do intervalo. Use A-J e 1-10.\n");
        return;
    }
    int line = linha - 1;

    int Gravando_Line = 3, Gravando_coluns = 5, center = Gravando_coluns / 2;
    int (*gravando)[5] = NULL; // Ponteiro para a matriz de ataque

    switch (escolha){
        case 1: gravando = cone; 
        break;
        case 2: gravando = cruz; 
        break;
        case 3: gravando = octaedro; 
        break;
        default:
            printf("Opção inválida! Saindo.\n");
            return;
    }
    // Define a matriz de ataque com base na escolha do usuário

    // Aplica o padrão centrado na coordenada informada
    for (int i = 0; i < Gravando_Line; i++){
        for (int j = 0; j < Gravando_coluns; j++){
            if (gravando[i][j] != 3) continue; // só aplica células do padrão e ignora as outras
            int tr = line + i;                // linha alvo 
            int tc = coluna + (j - center);   // coluna alvo

            if (tr < 0 || tr >= 10 || tc < 0 || tc >= 10) continue; // fora do tabuleiro não faz nada
            if (tabuleiro[tr][tc] == 3) {
                tabuleiro[tr][tc] = acerto;   // acertou barco
            } else if (tabuleiro[tr][tc] == 0) {
                tabuleiro[tr][tc] = erro;  // acertou água
            }
        }
    }

    printf("Tabuleiro após ataque (Acertos = %d, Erros = %d):\n", acerto, erro);
    exibirtabuleiro();
}
int main(){
    printf("Batalha Naval - Tabuleiro Inicial\n");
    exibirtabuleiro();
    printf("\n");
    printf("Escolha a posição que deseja colocar seu navio (coluna A-J e linha 1-10)\n");
    printf("Exemplo de preenchimento: B2\n");
    printf("Esse navio deverá ocupar 3 posições consecutivas na horizontal:\n");
    Entradauser();
    
    // Coloca um navio na posição escolhida e define o valor 3 para representar o navio
    // Valida a posição se já foi usada e se o valor escolhido não é maior que o tabuleiro
    // Exibir o tabuleiro atualizado
    printf("\nBatalha Naval - Tabuleiro Atualizado\n");
    exibirtabuleiro();
    printf("\n");
    printf("Seguindo a mesma lógica de preenchimento anterior.\n");
    printf("Agora posicione um navio que ocupe 3 posições consecutivas na vertical:\n");
    Entradauser();

    // Coloca outro navio na posição escolhida e define o valor 3 para representar o navio
    // Valida a posição se já foi usada e se o valor escolhido não é maior que o tabuleiro
    // Exibir o tabuleiro atualizado
    printf("\nBatalha Naval - Tabuleiro Atualizado\n");
    exibirtabuleiro();
    printf("\n");
    printf("Agora posicione dois navios na diagonal no tabuleiro\n");
    printf("Cada navio ocupará 3 posições consecutivas na diagonal:\n");
    printf("Primeiro navio diagonal:\n");
    Entradauser();
    printf("Segundo navio diagonal:\n");
    Entradauser();
    printf("\nBatalha Naval - Tabuleiro Final\n");
    exibirtabuleiro();
    printf("\n");
    printf("Agora com todos os navios posicionados vamos começar os ataques!\n");
    printf("Voce pode usar algumas habilidades para causar maiores danos\n");
    printf("Habilidade Cone:\n");
    HabCone();
    printf("\n");
    printf("Habilidade Cruz:\n");
    HabCruz();
    printf("\n");
    printf("Habilidade Octaedro:\n");
    Haboctaedro();
    printf("\n");
    printf("Vamos testar alguns ataques no seu tabuleiro!\n");
    printf("Lembre-se que que o programa ira seguir a sua coordenada como ponto de origem pro ataque\n");
    Ataqueuser();
    

    // Até então não fiz uma validação para garantir que os navios fiquem realmente na diagonal
    // Ou na horizontal/vertical. Porém como não foi solicitado, deixei assim mesmo.
    // Mas daria para fazer uma verificação extra para garantir isso.
    return 0;
}