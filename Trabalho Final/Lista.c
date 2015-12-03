#include "Lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void inicializa_lista(Lista *l, size_t t)
{
    l->tamInfo = t;
    l->cabeca = NULL;
}

int listaVazia(Lista *l) 
{
    if (l->cabeca == NULL) 
        return 1;
    else
        return 0;
}

int insereNoInicio(Lista *l, void *info)
{
    Elemento *p = aloca_elemento(l->tamInfo, info);
    p->proximo = l->cabeca;
    l->cabeca = p;
    return 1; //Sucesso
}

int removeDoInicio(Lista *l, void *info)
{
    if (l->cabeca == NULL)
    {
        return ERRO_LISTA_VAZIA;
    }
    Elemento *p = l->cabeca;
    l->cabeca = p->proximo;
    memcpy(info, p->info, l->tamInfo);
    free(p->info);
    free(p);
    return 1; //Sucesso
}

int insereNoFim(Lista *l, void *info)
{
    if(l->cabeca == NULL)
    {
        return insereNoInicio(l, info);
    }

    Elemento *aux = l->cabeca;
    while(aux->proximo != NULL)
    {
        aux = aux->proximo;
    }

    Elemento *p = aloca_elemento(l->tamInfo, info);
    p->proximo = NULL;
    aux->proximo = p;
    return 1; //Sucesso
}

int removeDoFim(Lista *l, void *info)
{
    if (l->cabeca == NULL)
        return ERRO_LISTA_VAZIA;

    if(l->cabeca->proximo == NULL)
        return removeDoInicio(l, info);

    Elemento *aux = l->cabeca;
    while(aux->proximo->proximo != NULL)
    {
        aux = aux->proximo;
    }
    memcpy(info, aux->proximo->info, l->tamInfo);
    free(aux->proximo->info);
    free(aux->proximo);
    aux->proximo = NULL;
    return 1; //Sucesso
}

int insereNaPosicao(Lista *l, void *info, int pos)
{
    if(pos < 0)
        return ERRO_POSICAO_INVALIDA;
    if(pos == 0)
        return insereNoInicio(l, info);

    Elemento *aux = l->cabeca;
    int cont = 0;
    while(cont < pos-1 && aux->proximo != NULL)
    {
        aux = aux->proximo;
        cont++;
    }
    if(cont != pos-1)
        return ERRO_POSICAO_INVALIDA;

    Elemento *novo = aloca_elemento(l->tamInfo, info);
    if(novo == NULL)
        return 0; //Fracasso
    novo->proximo = aux->proximo;
    aux->proximo = novo;
    return 1; //Sucesso
}

int removeNaPosicao(Lista *l, void *info, int pos)
{
    if(pos < 0)
        return ERRO_POSICAO_INVALIDA;
    if(pos == 0)
        return removeDoInicio(l, info);

    Elemento *aux = l->cabeca;
    int cont = 0;
    while(cont < pos-1 && aux->proximo != NULL)
    {
        aux = aux->proximo;
        cont++;
    }
    if (cont != pos-1 || aux->proximo == NULL)
        return ERRO_POSICAO_INVALIDA;

    memcpy(info, aux->proximo->info, l->tamInfo);

    Elemento *aux2 = aux->proximo;
    aux->proximo = aux->proximo->proximo;

    free(aux2->info);
    free(aux2);
    return 1; //Sucesso
}

int insereEmOrdem(Lista *l, void *info, int (*compara_float)(void*, void *))
{
    int cont = 0;
    Elemento *aux = l->cabeca;
    while(aux != NULL && compara_float(aux->info, info) < 0)
    {
        aux = aux->proximo;
        cont++;
    }
    return insereNaPosicao(l, info, cont);
}

int removeInfo(Lista *l, void *info)
{
    if(l->cabeca == NULL)
        return ERRO_LISTA_VAZIA;
    int cont = 0;
    Elemento *aux = l->cabeca;
    while(aux->proximo != NULL && memcmp(aux->info, info, l->tamInfo) != 0)
    {
        aux = aux->proximo;
        cont++;
    }
    if (memcmp(aux->info, info, l->tamInfo) == 0)
        return removeNaPosicao(l, info, cont);
}

int modificaNaPosicao(Lista *l, void *info, int pos)
{
    if(pos < 0)
        return ERRO_POSICAO_INVALIDA;

    Elemento *aux = l->cabeca;
    int cont = 0;
    while(cont != pos && aux->proximo != NULL)
    {
        aux = aux->proximo;
        cont++;
    }
    if(cont != pos)
        return ERRO_POSICAO_INVALIDA;
    memcpy(aux->info, info, l->tamInfo);
    return 1; //Sucesso
}

int leNaPosicao(Lista *l, void *info, int pos)
{
    if(pos < 0)
        return ERRO_POSICAO_INVALIDA;

    Elemento *aux = l->cabeca;
    int cont = 0;
    while(cont != pos && aux->proximo != NULL)
    {
        aux = aux->proximo;
        cont++;
    }
    if(cont != pos)
        return ERRO_POSICAO_INVALIDA;

    memcpy(info, aux->info, l->tamInfo);
    return 1; //Sucesso
}

Elemento *aloca_elemento(size_t t, void *info)
{
    Elemento *p;
    p = (Elemento*) malloc(sizeof(Elemento));

    if(p == NULL)
        return NULL;

    p->info = malloc(t);
    if (p->info == NULL)
    {
        free(p);
        return NULL;
    }
    memcpy(p->info, info, t);
    return p;
}

int limpa_lista(Lista *l)
{
    Elemento *aux = l->cabeca;
    // Lista vazia
    if (aux == NULL)
        return 1;

    while (aux != NULL)
    {
        if (aux->proximo == NULL)
        {
            l->cabeca = NULL;
            free(aux->info);
            free(aux);
            return 1;
        }

        while (aux->proximo->proximo != NULL)
        {
            aux = aux->proximo;
        }

        free(aux->proximo->info);
        free(aux->proximo);
        aux->proximo = NULL;
        aux = l->cabeca;
    }

    return 1;
}

int elementoExiste(Lista *l, void *info, int (*compara_info)(void *, void *))
{
    Elemento *aux = l->cabeca;
    if (aux == NULL)
        return -1;
    int cont = 0;
    while(aux != NULL)
    {
        if (compara_info(aux->info, info) == 0)
        {
            return cont;
        }
        aux = aux->proximo;
        cont++;
    }

    return -1;

}

void mostra_lista(Lista l, void (*mostra_info)(void *))
{
    Elemento *aux = l.cabeca;
    if (aux == NULL)
        return;

    while(aux != NULL)
    {
        //printf("%d: ", cont++);
        mostra_info(aux->info);
        aux = aux->proximo;
    }
    printf("\n");
}

int buscaElemento(Lista *l, void *info, int (*compara_info)(void *, void *))
{
    Elemento *aux = l->cabeca;
    if (aux == NULL)
        return ERRO_ELEMENTO_NAO_ENCONTRADO;

    while (aux != NULL)
    {
        if (compara_info(info, aux->info) == 0)
        {
            memcpy(info, aux->info, l->tamInfo);
            return 1; // Sucesso
        }
        aux = aux->proximo;
    }

    return ERRO_ELEMENTO_NAO_ENCONTRADO;
}
