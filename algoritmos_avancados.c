#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da sala (nó da árvore binária)
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// Função para criar uma sala dinamicamente
Sala* criarSala(const char* nome) {
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}

// Função para explorar a mansão
void explorar(Sala* salaAtual) {
    printf("\nVocê está na: %s\n", salaAtual->nome);
    
    // Se é um nó-folha, finaliza a exploração
    if (salaAtual->esquerda == NULL && salaAtual->direita == NULL) {
        printf("Fim da exploração! Esta sala não tem saídas.\n");
        return;
    }
    
    // Menu de opções
    printf("Opções:\n");
    if (salaAtual->esquerda != NULL) printf("(e) Esquerda\n");
    if (salaAtual->direita != NULL) printf("(d) Direita\n");
    printf("(s) Sair\n");
    printf("Escolha: ");
    
    char escolha;
    scanf(" %c", &escolha);
    
    // Navegação baseada na escolha
    switch(escolha) {
        case 'e':
            if (salaAtual->esquerda != NULL) {
                explorar(salaAtual->esquerda);
            } else {
                printf("Não há caminho à esquerda!\n");
                explorar(salaAtual);
            }
            break;
        case 'd':
            if (salaAtual->direita != NULL) {
                explorar(salaAtual->direita);
            } else {
                printf("Não há caminho à direita!\n");
                explorar(salaAtual);
            }
            break;
        case 's':
            printf("Exploração finalizada!\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            explorar(salaAtual);
            break;
    }
}

// Função principal - monta o mapa e inicia a exploração
int main() {
    printf("=== EXPLORAÇÃO DA MANSÃO ===\n");
    
    // Criando a árvore binária manualmente (mapa da mansão)
    Sala* hall = criarSala("Hall de Entrada");
    Sala* salaEstar = criarSala("Sala de Estar");
    Sala* cozinha = criarSala("Cozinha");
    Sala* quarto1 = criarSala("Quarto Principal");
    Sala* banheiro = criarSala("Banheiro");
    Sala* jardim = criarSala("Jardim");
    Sala* escritorio = criarSala("Escritório");
    
    // Montando a estrutura da árvore
    hall->esquerda = salaEstar;
    hall->direita = cozinha;
    
    salaEstar->esquerda = quarto1;
    salaEstar->direita = banheiro;
    
    cozinha->esquerda = jardim;
    cozinha->direita = escritorio;
    
    // Iniciando a exploração a partir do Hall
    explorar(hall);
    
    // Liberar memória (simplificado para este exemplo)
    free(quarto1);
    free(banheiro);
    free(jardim);
    free(escritorio);
    free(salaEstar);
    free(cozinha);
    free(hall);
    
    return 0;
}