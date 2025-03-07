#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//Implementando a função criar
struct No *criar(void) {
    return NULL;
}

//Implementando a função para inserir
struct No *inserir(struct No *lista, int mat, char *nome) { //*lista é a cabeça da lista
    struct No *newNode = (struct No *)malloc(sizeof(struct No));
    
    if(newNode == NULL) {
        printf("Erro ao alocar memória!\n");
        return lista;
    }

    newNode->mat = mat; //Atribuindo o número da matrícula ao novo nó
    newNode->nome = (char *)malloc(strlen(nome) + 1); //Alocando memória para o nome do aluno

    if(newNode->nome == NULL) {
        printf("Erro ao alocar memória para o nome!\n");
        free(newNode);
        return lista;
    }

    strcpy(newNode->nome, nome);

    newNode->ant = NULL;
    newNode->prox = NULL;

    //Verificando se a lista está vazia
    if (lista == NULL) {
        return newNode;
    }

    struct No *atual = lista; //O ponteiro atual está representando o primeiro elemento da lista
    struct No *anterior = NULL; //O ponteiro anterior está sendo inicializado com NULL porque não está apontando para ninguém

    //Vai pecorrer a lista
    while(atual != NULL && strcmp(nome, atual->nome) > 0) {
        anterior = atual;
        atual = atual -> prox;
    }

    if(anterior == NULL) {
        //Aqui estaremos inserindo o elemento no início da lista
        newNode->prox = lista;
        lista->ant = newNode;
        return newNode;
    } else {
        //Aqui estaremos inserindo o elemento no meio da lista
        anterior->prox = newNode;
        newNode->ant = anterior;

        if(atual != NULL) {
            newNode->prox = atual;
            atual->ant = newNode;
        }

        return lista;
    }
}

//Funçao para imprimir a lista no terminal
void imprimir(struct No *lista){
    struct No *atual = lista;

    if(atual == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    printf("Conteúdo da lista: \n");
    while(atual != NULL) {
        printf("Matrícula: %d, Aluno: %s\n", atual->mat, atual->nome);
        atual = atual->prox;
    }
}

//Implementando função para remover a matrícula
struct No *remover(struct No *lista, int mat) {
    struct No *anterior = NULL; //Ponteiro apontando para o elemento anterior
    struct No *atual = lista; //Ponteiro para pecorrer a lista
    
    //Procurando o elemento na lista e guardando no anteiror
    while(atual != NULL && atual->mat != mat) {
        anterior = atual; //Guarda a matrícula no nó anteiror
        atual = atual->prox; //Avança para o próximo nó
    }

    if(atual == NULL) {
        return lista; //Não achou o elemento, assim vai retornar a lista
    }

    if(anterior == NULL) {
        lista = atual->prox; //Retirar o elemento no início
    } else {
        anterior->prox = atual->prox; //Retirar o elemento no meio da lista
    }

    free(atual);

    return lista;
}

struct No *buscarMatricula(struct No *lista, int mat) {
    struct No *atual;

    for(atual = lista; atual != NULL; atual = atual->prox) {
        if(atual->mat == mat) {
            return atual;
        }
    }
    return NULL;
}

struct No *buscarNome(struct No *lista, char *nome) {
    struct No *atual;

    for(atual = lista; atual != NULL; atual = atual->prox) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
    }

    return NULL;
}

int tamanho(struct No *lista) {
    struct No *atual = lista;
    int count = 0;

    while(atual != NULL) {
        count++;
        atual = atual->prox;
    }

    return count;
}