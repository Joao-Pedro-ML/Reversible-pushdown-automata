#ifndef PILHADIN_H
#define PILHADIN_H

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STDBOOL_H
#include <stdbool.h>
#endif

#ifndef _STRING_H
#include <string.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char chave;
} objetoDin;

typedef struct NoPilha *ponteiroNoPilha;

typedef struct NoPilha {
    objetoDin obj;
    ponteiroNoPilha proximo;
} NoPilha;

typedef struct {
    ponteiroNoPilha topo;
    int tamanho;
} pilhadim;

void iniciaPilhaDin(pilhadim *pilha) {
    pilha->topo = NULL;
    pilha->tamanho = 0;
} //função que inicia a pilha

int tamanhoDin(pilhadim *pilha) {
    return pilha->tamanho;
} //função que retorna o tamanho da pilha

bool estaVaziaDin(pilhadim *pilha) {

    if(pilha->tamanho == 0)
        return true;
    
    return false;
} //função que verifica se a pilha está vazia

void pushDin(objetoDin obj, pilhadim *pilha) {
    ponteiroNoPilha aux;
    aux = (ponteiroNoPilha) malloc(sizeof (NoPilha));
    aux->obj = obj;
    aux->proximo = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho = pilha->tamanho + 1;
} // Função que insere um elemento na pilha

void popDin(pilhadim *pilha, objetoDin *item) {

    if (!estaVaziaDin(pilha)) {
        *item = pilha->topo->obj;
        ponteiroNoPilha aux;
        aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(aux);
        pilha->tamanho = pilha->tamanho - 1;
    }
} //função que remove um elemento da pilha e o retorna num objeto

void topoDin(pilhadim *pilha, objetoDin obj) {
    
    printf("Topo da pilha: %c\n", obj.chave);
}//função que retorna o elemento do topo da pilha

void printDin(pilhadim *pilha) {
    printf("{");
    ponteiroNoPilha p;
    for (p = pilha->topo; p != NULL; p = p->proximo) {
        printf("%c ", p->obj.chave);
    }
    printf("}\n");
} //função que mostra a pilha


#ifdef __cplusplus
}
#endif

#endif /* PILHADIN_H */
