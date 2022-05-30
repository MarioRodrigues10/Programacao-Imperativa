#define Max 1000

struct staticStack {
    int sp;
    int values [Max];
} STACK, *SStack;

struct staticQueue {
    int front;
    int length;
    int values [Max];
} QUEUE, *SQueue;

void initStack(SStack s) {
    s->sp = 0;
}

int isEmpty(SStack s) {
    return s->sp == 0;
}

int Spush (SStack s, int x){
    if (s->sp == Max) {
        return 0;
    }
    s->values[s->sp] = x;
    s->sp++;
    return 1;
}

int Spop (SStack s){
    if (isEmpty(s)) {
        return 1;
    }
    s->sp--;
    return 0;
}

int Stop (SStack s, int *x){
    if (isEmpty(s)) {
        return 1;
    }
    *x = s->values[s->sp-1];
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////

void initQueue(SQueue q) {
    q->front = 0;
    q->length = 0;
}

int SisEmptyQ (SQueue q){
    return q->length == 0;
}

int Senqueue (SQueue q, int x){
    if (q->length == Max) {
        return 0;
    }
    q->values[q->front] = x;
    q->front = (q->front + 1) % Max;
    q->length++;
    return 1;
}

int Sdequeue (SQueue q, int *x){
    if (SisEmptyQ(q)) {
        return 1;
    }
    *x = q->values[q->front];
    q->front = (q->front + 1) % Max;
    q->length--;
    return 0;
}

int Sfront (SQueue q, int *x) {
    if (SisEmptyQ(q)) {
        return 1;
    }
    *x = q->values[q->front];
    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////
typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;

void initDStack(DStack s) {
    s->size = Max;
    s->sp = 0;
    s->values = (int*)malloc(sizeof(int)*Max);
}

int isEmptyDStack(DStack s) {
    return s->sp == 0;
}

int Dpush (DStack s, int x){
    if (s->sp == s->size) {
        return 0;
    }
    s->values[s->sp] = x;
    s->sp++;
    return 1;
}

int Dpop (DStack s){
    if (isEmptyDStack(s)) {
        return 1;
    }
    s->sp--;
    return 0;
}

int Dtop (DStack s, int *x){
    if (isEmptyDStack(s)) {
        return 1;
    }
    *x = s->values[s->sp-1];
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////

typedef struct dinQueue {
    int size; // guarda o tamanho do array values
    int front;
    int length;
    int *values;
} *DQueue;

void initDQueue(DQueue q) {
    q->size = Max;
    q->front = 0;
    q->length = 0;
    q->values = (int*)malloc(sizeof(int)*Max);
}

int isEmptyDQueue(DQueue q) {
    return q->length == 0;
}

int Denqueue (DQueue q, int x){
    if (q->length == q->size) {
        return 0;
    }
    q->values[q->front] = x;
    q->front = (q->front + 1) % Max;
    q->length++;
    return 1;
}

int Ddequeue (DQueue q, int *x){
    if (isEmptyDQueue(q)) {
        return 1;
    }
    *x = q->values[q->front];
    q->front = (q->front + 1) % Max;
    q->length--;
    return 0;
}

int Dfront (DQueue q, int *x) {
    if (isEmptyDQueue(q)) {
        return 1;
    }
    *x = q->values[q->front];
    return 0;
}