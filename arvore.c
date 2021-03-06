#include <stdio.h>
#include <stdlib.h>

typedef struct registro{
    char nome[30];
    int telefone;
}registro;

typedef struct No *Apontador;

typedef struct No{
     registro dado;
     Apontador pEsq, pDir;
  }No;

void insere(registro x, Apontador *p);
void retira(registro x, Apontador *p);
void inicializa(Apontador *agenda);
void antecessor(Apontador q, Apontador *r);
void preordem(Apontador *agenda);
void posordem(Apontador *agenda);
void central(Apontador *agenda);
void pesquisa( registro *x, Apontador agenda);
void insere(registro x, Apontador *p){

    if(*p == NULL){
        *p = (Apontador) malloc (sizeof(No));
        (*p)-> dado = x;
        (*p)->pEsq = NULL;
        (*p)->pDir = NULL;
        return;
    }
    if(x.telefone < (*p)->dado.telefone){
        insere(x, &(*p)->pEsq);
        return;
    }
    if(x.telefone > (*p)->dado.telefone){
        insere(x, &(*p)->pDir);
        return;
    }
    else{
        printf("Erro: Registro já existente.\n");
    }
}
void inicializa(Apontador *agenda){
    *agenda = NULL;
}
void retira(registro x, Apontador *p){
    Apontador aux;

    if(*p == NULL){
        printf("Erro: Registro não existente.\n");
        return;
    }
    if(x.telefone < (*p)->dado.telefone){
        retira(x, &(*p)->pEsq);
        return;
    }
    if(x.telefone > (*p)->dado.telefone){
        retira(x, &(*p)->pDir);
        return;
    }
    if((*p)->pDir == NULL){
        aux = *p;
        *p = (*p)->pEsq;
        free(aux);
        return;
    }

    if((*p)->pEsq != NULL){
        antecessor(*p, &(*p)->pEsq);
        return;
    }

    aux = *p;
    *p  = (*p)-> pDir;
    free(aux);

}
void antecessor(Apontador q, Apontador *r){

    Apontador aux;

    if((*r)->pDir != NULL){
        antecessor(q, &(*r)->pDir);
        return;
    }
    q-> dado = (*r)-> dado;
    aux = (*r);
    *r = (*r)->pEsq;
    free(aux);
}
void preordem(Apontador *agenda){

    if(*agenda == NULL){
        return;
    }
    else{
        printf("Nome: %s, telefone: %d.\n",(*agenda)->dado.nome, (*agenda)->dado.telefone);
        preordem(&((*agenda)->pEsq));
        preordem(&((*agenda)->pDir));

    }
}
void posordem(Apontador *agenda){

    if(*agenda == NULL){
        return;
    }
    else{
        posordem(&((*agenda)->pEsq));
        posordem(&((*agenda)->pDir));
        printf("Nome: %s, telefone: %d.\n",(*agenda)->dado.nome, (*agenda)->dado.telefone);
    }
}
void central(Apontador *agenda){

    if(*agenda == NULL){
        return;
    }
    else{
        central(&((*agenda)->pEsq));
        printf("Nome: %s, telefone: %d.\n",(*agenda)->dado.nome, (*agenda)->dado.telefone);
        central(&((*agenda)->pDir));
    }
}
void pesquisa( registro *x, Apontador agenda){

    if(agenda == NULL){
        printf("Erro : Registro nao esta presente na arvore\n");
        return;
    }
    if(x->telefone < agenda->dado.telefone){
        pesquisa(x, agenda->pEsq);
        return;
    }
    if(x->telefone > (agenda)->dado.telefone){
        pesquisa(x, agenda->pDir);
        return;
    }
    else{
        *x = agenda->dado;
    }
}

int main(){

    int e;
    registro aux;
    Apontador *agenda;

    inicializa(&agenda);
    do{
        printf("\nEscolha:\n1- Inserir\n2- Retirar \n3- Listar em preordem \n4- Listar em posordem \n5- Listar em central \n6- Pesquisa \nOutra opção para sair.\n");
        scanf("%d", &e);

        switch(e){
            case 1:
                printf("\nDigite o nome: ");
                scanf("%s", aux.nome);
                printf("\nDigite a telefone: ");
                scanf("%d", &aux.telefone);
                insere(aux, &agenda);
            break;
            case 2:
                printf("\nDigite a telefone: ");
                scanf("%d", &aux.telefone);
                retira(aux, &agenda);
            break;
            case 3:
                printf("\nPreordem:\n ");
                preordem(&agenda);
            break;
            case 4:
                printf("\nPosordem:\n ");
                posordem(&agenda);
            break;
            case 5:
                printf("\nCentral:\n ");
                central(&agenda);
            break;
            case 6:
                printf("\nDigite a telefone: ");
                scanf("%d", &aux.telefone);
                pesquisa(&aux, agenda);
            break;
        }
    }while(e<=5 && e>0);


    return 0;
}
