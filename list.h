#ifndef __LIST_H__
#define __LIST_H__

struct No {
    int mat;
    char *nome;
    struct No *ant;
    struct No *prox;
};

struct No *criar(void);
struct No *inserir(struct No *lista, int mat, char *nome);
struct No *remover(struct No *lista, int mat);
struct No *buscarMatricula(struct No *lista, int mat);
struct No *buscarNome(struct No *lista, char *nome);

#endif