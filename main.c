#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.c"

int main() {
    //Criando a lista
    struct No *lista = criar();

    lista = inserir(lista, 101, "Carlos");
    lista = inserir(lista, 102, "Ana");
    lista = inserir(lista, 103, "Daniel");

    int tam = tamanho(lista);
    printf("Tamanho da lista: %d", tam);

    imprimir(lista);

    lista = remover(lista, 102);

    imprimir(lista);

    lista = buscarNome(lista, "Daniel");

    imprimir(lista);
}