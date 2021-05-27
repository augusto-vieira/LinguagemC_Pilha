//Arquivo PilhaSequencial.c
#include<stdio.h>
#include <stdlib.h>

#include "PilhaDin.h"

struct elemento
{
   struct aluno dados; 
   struct elemento *prox;
};

typedef struct elemento Elem;

Pilha* criar_Pilha()
{
    Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
    
    if(pi != NULL)
        *pi = NULL;

    return pi;    
}

void libera_Pilha(Pilha* pi)
{
    if(pi != NULL)
    {
        Elem* no;
        while ((*pi) != NULL ))
        {
            no = *pi;
            pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    } 
}

int tamanho_Pilha(Pilha* pi)
{
    if(pi == NULL)
        return 0;
    
    int cont = 0;
    Elem* no = *pi;

    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }

    return cont;
}

int Pilha_cheia(Pilha* pi)
{
    return 0;
}

int Pilha_vazia(Pilha* pi)
{
    // vazia == 1, != 0
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;

    return 0;
}

int insere_Pilha(Pilha* pi, struct aluno al)
{
    if(pi == NULL)
        return 0;

    Elem* no = (Elem*)malloc(sizeof(Elem));

    if(no == NULL)
        return 0;

    no->dados = al;     // Copio as infomações de "al" para o campo "dados" do novo nó
    no->prox  = (*pi);  // O nó aponta para o topo de Pilha
    *pi = no;           // Topo da pilha se torna o novo elemento

    return 1;
}

int remove_Pilha(Pilha* pi)
{
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    
    Elem* no = *pi;
    *pi = no->prox;
    free(no);
    
    return 1;
   
}

int consulta_topo_Pilha(Pilha* pi, struct aluno *al)
{
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    
    *al = (*pi)->dados;

    return 1;
}