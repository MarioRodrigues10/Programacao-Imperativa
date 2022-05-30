typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;


LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
    r->valor = x; r->prox = xs;
    }
    return r;
}

typedef LInt Stack;

typedef struct {
    LInt inicio,fim;
} Queue;


////////////////////////////////////////////////////////////////////////////////

void initStack (Stack *s) {
    *s = NULL;
}

int StackEmpty (Stack s) {
    return s == NULL;
}

int push(Stack *s, int x) {
    *s = newLInt(x, *s);
    return 0;
}

int pop(Stack *s, int *x) {
    if (StackEmpty(*s)) return 1;
    *x = (*s)->valor;
    *s = (*s)->prox;
    return 0;
}

int top(Stack s, int *x) {
    if (StackEmpty(s)) return 1;
    *x = s->valor;
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////

void initQueue (Queue *q) {
    q->inicio = q->fim = NULL;
}

int QisEmptyQ (Queue *q) {
    return q->inicio == NULL;
}

int Qenqueue (Queue *q, int x) {
    q->fim = newLInt(x, q->fim);
    if (q->inicio == NULL) q->inicio = q->fim;
    return 0;
}

int Qdequeue (Queue *q, int *x) {
    if (QisEmptyQ(q)) return 1;
    *x = q->inicio->valor;
    q->inicio = q->inicio->prox;
    if (q->inicio == NULL) q->fim = NULL;
    return 0;
}

int  Qfront (Queue *q, int *x) {
    if (QisEmptyQ(q)) return 1;
    *x = q->inicio->valor;
    return 0;
}

