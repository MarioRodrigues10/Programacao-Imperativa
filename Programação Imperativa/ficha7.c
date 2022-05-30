typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista (Palavras) {
    Palavras atual = l;
    Palavras prox;
    while (atual != NULL) {
        prox = atual->prox;
        free(atual->palavra);
        free(atual);
        atual = prox;
    }
}


Lista quantasP (Palavras l) {
    Lista cont = 0;
    while (l != NULL) {
        cont++;
        l = l->prox;
    }
    return cont;
}

void listaPal (Palavras l){
    while (l != NULL) {
        printf("%s\n", l->palavra);
        l = l->prox;
    }
}

char * ultima (Palavras l) {
    while (l->prox != NULL) {
        l = l->prox;
    }
    return l->palavra;
}

Palavras acrescentaInicio (Palavras l, char *p){
    Palavras novo = (Palavras) malloc(sizeof(struct celula));
    novo->palavra = p;
    novo->ocorr = 1;
    novo->prox = l;
    return novo;
}

Palavras acrescentaFim (Palavras l, char *p){
    Palavras novo = (Palavras) malloc(sizeof(struct celula));
    novo->palavra = p;
    novo->ocorr = 1;
    novo->prox = NULL;
    Palavras atual = l;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
    return l;
}

Palavras acrescenta (Palavras l, char *p) {
    Palavras novo = (Palavras) malloc(sizeof(struct celula));
    novo->palavra = p;
    novo->ocorr = 1;
    novo->prox = NULL;
    Palavras atual = l;
    while (atual->prox != NULL) {
        if (strcmp(atual->palavra, p) == 0) {
            atual->ocorr++;
            return l;
        }
        atual = atual->prox;
    }
    if (strcmp(atual->palavra, p) == 0) {
        atual->ocorr++;
        return l;
    }
    atual->prox = novo;
    return l;
}

struct celula * maisFreq (Palavras l){
    Palavras atual = l;
    Palavras maisFreq = l;
    while (atual != NULL) {
        if (atual->ocorr > maisFreq->ocorr) {
            maisFreq = atual;
        }
        atual = atual->prox;
    }
    return maisFreq;
}