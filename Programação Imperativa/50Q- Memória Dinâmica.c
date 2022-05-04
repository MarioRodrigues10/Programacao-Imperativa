typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;


#include <stdio.h>
#include <stdlib.h>

//1
int length(LInt l) {
    int cont = 0;
    while (l != NULL) {
        cont++;
        l = l->prox;
    }
    return cont;
}

//2
void freeL(LInt l) {
    LInt aux;
    while (l != NULL) {
        aux = l;
        l = l->prox;
        free(aux);
    }
}

//3
void imprimeL(LInt l) {
    while (l != NULL) {
        printf("%d\n", l->valor);
        l = l->prox;
    }
}

//4
LInt reverseL(LInt l) {
    LInt ant = NULL;
    LInt prox = NULL;
    LInt atual = l;
    while (atual != NULL) {
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    return ant;
}

//5
void insertOrdered(LInt *l, int valor) {
    LInt novo = (LInt) malloc(sizeof(struct lligada));
    novo->valor = valor;
    LInt atual = *l;
    LInt ant = NULL;
    while (atual != NULL && atual->valor < valor) {
        ant = atual;
        atual = atual->prox;
    }
    if (ant == NULL) {
        novo->prox = *l;
        *l = novo;
    } else {
        novo->prox = atual;
        ant->prox = novo;
    }
}


//6 
int removeOneOrd(LInt *l, int x) {
    LInt prev = NULL;
    for(;*l && x != (*l)->valor; prev = *l, l = &((*l)->prox));
    if(!(*l)) return 1;
    if(!prev) (*l) = (*l)->prox;
    else prev->prox = (*l)->prox;
    return 0;
}

//7
void merge (LInt *r, LInt a, LInt b){
    if (a == NULL) {
        *r = b;
    } else if (b == NULL) {
        *r = a;
    } else if (a->valor <= b->valor) {
        *r = a;
        a = a->prox;
        merge(&(*r)->prox, a, b);
    } else {
        *r = b;
        b = b->prox;
        merge(&(*r)->prox, a, b);
    }
}

//8
void splitQS(LInt l, int x, LInt *mx, LInt *Mx) {
    if(!l) return;
    if(l->valor < x) {
        (*mx) = l;
        (*Mx) = NULL;
        splitQS(l->prox, x, &((*mx)->prox), Mx);
    }
    else {
        (*Mx) = l;
        (*mx) = NULL;
        splitQS(l->prox, x, mx, &((*Mx)->prox));
    }
}


//9
void split (LInt l, LInt *a, LInt *b) {
    LInt atual = l;
    LInt ant = NULL;
    int cont = 0;
    while (atual != NULL) {
        cont++;
        ant = atual;
        atual = atual->prox;
    }
    atual = l;
    while (cont > 0) {
        cont--;
        ant = atual;
        atual = atual->prox;
    }
    *a = l;
    *b = atual;
    if (ant != NULL) {
        ant->prox = NULL;
    }
}

//10
int removeAll(LInt *l, int x) {
    int rem = 0;
    LInt prev = NULL;
    while(*l) {
        if((*l)->valor == x) {
            if(!prev) (*l) = (*l)->prox;
            else prev->prox = (*l)->prox;
            rem++;
        }
        else {
            prev = (*l);
            l = &((*l)->prox);
        }
    }
    return rem;
}

//11 (sofia answer)
int removeDups(LInt *l) {
    int rem = 0;
    for(; *l; l = &((*l)->prox)) {
        LInt prevAux = (*l), aux = (*l)->prox;
        for(; aux; aux = prevAux->prox) {
            if(aux->valor == (*l)->valor) {
                prevAux->prox = aux->prox;
                rem++;
                free(aux);
            }
            else prevAux = aux;
        }
    }
    return rem;
}

//12
int removeMaiorL (LInt *l){
    LInt ant = NULL, atual = *l;
    int maior = atual->valor;
    while (atual != NULL) {
        if (atual->valor > maior) {
            maior = atual->valor;
            ant = atual;
        }
        atual = atual->prox;
    }
    if (ant == NULL) {
        *l = (*l)->prox;
    } else {
        ant->prox = (*l)->prox;
    }
    return maior;
}

//13 (sofia)
void removeLast(LInt *l){
    LInt prev = NULL;
    for( ;(*l)->prox; prev = *l, l = &((*l)->prox));
    if(!prev) {
        free(*l);
        *l = NULL;
    }
    else {
        prev->prox = NULL;
        free(*l);
    }
}

//14
void appendL(LInt *l, int x){
    LInt novo = (LInt) malloc(sizeof(struct lligada));
    novo->valor = x;
    novo->prox = NULL;
    if(*l == NULL) *l = novo;
    else {
        LInt atual = *l;
        while(atual->prox != NULL) atual = atual->prox;
        atual->prox = novo;
    }
}

//15
void concatL (LInt *a, LInt b) {
    if (*a == NULL) {
        *a = b;
    } else {
        LInt atual = *a;
        while (atual->prox != NULL) atual = atual->prox;
        atual->prox = b;
    }
}

//16
LInt cloneL (LInt l){
    LInt novo = NULL;
    LInt ant = NULL;
    while(l != NULL) {
        LInt novo = (LInt) malloc(sizeof(struct lligada));
        novo->valor = l->valor;
        novo->prox = NULL;
        if(ant == NULL) ant = novo;
        else ant->prox = novo;
        ant = novo;
        l = l->prox;
    }
    return ant;
}

//17
LInt cloneRev (LInt l){
    LInt novo = NULL;
    LInt ant = NULL;
    while(l != NULL) {
        LInt novo = (LInt) malloc(sizeof(struct lligada));
        novo->valor = l->valor;
        novo->prox = ant;
        ant = novo;
        l = l->prox;
    }
    return ant;
}

//18
int maximo (LInt l){
    int maior = l->valor;
    while(l != NULL) {
        if(l->valor > maior) maior = l->valor;
        l = l->prox;
    }
    return maior;
}

//19
void freeL (LInt head){
	LInt tmp;
	while (head != NULL){
		tmp = head;
		head = head->prox;
		free(tmp);
	} 
}

int take (int n, LInt *head){
	LInt current = *head;
	int i;
    for (i = 0; i < (n-1) && current != NULL; i++){
    	current = current->prox;
    } 
    if (current == NULL){
    	return i;
    }
    LInt freeMe = current->prox;
    current->prox = NULL;
    freeL(freeMe)
    return ++i;
}

//20 
void freeL (LInt head){
	LInt tmp;
	while (head != NULL){
		tmp = head;
		head = head->prox;
		free(tmp);
	} 
}

int length (LInt head){
    int i;
    for (i = 0; head != NULL; i++){
    	head = head->prox;
    }
    return i;
}

int drop (int n, LInt *head){
    LInt current = *head; 
    int len = length(current); 
    if (n >= len){
    	freeL(current);
    	*head = NULL;
    	return len;
    }
    int i;
    for (i = 0; i < (n-1); i++){
    	current = current->prox;
    } 

    LInt output = current->prox;
    current->prox = NULL;
    freeL(*head); 
    *head = output; 
    return n;
}


//21
LInt Nforward(LInt l, int n){
    LInt atual = l;
    int cont = 0;
    while(cont < n && atual != NULL) {
        atual = atual->prox;
        cont++;
    }
    return atual;
}

//22
int listToArray (LInt l, int v[], int N){
    int cont = 0;
    while(l != NULL && cont < N) {
        v[cont] = l->valor;
        l = l->prox;
        cont++;
    }
    return cont;
}

//23
LInt arrayToList (int v[], int N) {
    if(N == 0) return NULL;
    LInt new = malloc(sizeof(struct lligada));
    new->valor = (*v);
    new->prox = arrayToList(v + 1, N - 1);
    return new;
}

//24 (sofia)
LInt somasAcL (LInt l) {
    int sum = 0;
    LInt list = NULL, temp = NULL;
    for(;l; l = l->prox) {
        sum += l->valor;
        LInt new = malloc(sizeof(struct lligada));
        new->valor = sum;
        new->prox = NULL;
        if(!list) list = temp = new;
        else temp = temp->prox = new;
    }
    return list;
}

//25
void remreps (LInt l){
    LInt ant = NULL, atual = l;
    while(atual != NULL) {
        LInt prox = atual->prox;
        if(ant != NULL && ant->valor == atual->valor) {
            ant->prox = prox;
            free(atual);
        }
        else ant = atual;
        atual = prox;
    }
}
