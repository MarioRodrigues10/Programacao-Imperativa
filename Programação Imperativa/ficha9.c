typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;


ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
    a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}


int altura (ABin a){
    if (a == NULL) return 0;
    int e = altura(a->esq);
    int d = altura(a->dir);
    return 1 + (e > d ? e : d);
}

int nFolhas(ABin a){
    if (a == NULL) return 0;
    if (a->esq == NULL && a->dir == NULL) return 1;
    return nFolhas(a->esq) + nFolhas(a->dir);
}

ABin maisEsquerda (ABin a){
    if (a == NULL) return NULL;
    if (a->esq == NULL) return a;
    return maisEsquerda(a->esq);
}

ABin maisDireita (ABin a){
    if (a == NULL) return NULL;
    if (a->dir == NULL) return a;
    return maisDireita(a->dir);
}

void imprimeNivel (ABin a, int l){
    if (a == NULL) return;
    if (l == 1) printf("%d ", a->valor);
    else {
        imprimeNivel(a->esq, l-1);
        imprimeNivel(a->dir, l-1);
    }
}

// Árvores Binárias de Procura não saiem , por isso não estão aqui os exercícios