// 1)

// y = x - pos na memória de x[0]
// z = x+3 - pos na memória de x[3]

// Output: 1 1 4
// x[0] = 1
// *y = elemento no endereço de memória y = 1
// *z = elemento no endereço de memória z = 4

// y = próxima posição de um int na memória, ou seja x[1]
// z = 2 posições á frente na memória de int , ou seja x[5]

// Output: 2 2 6
// x[1] = 2
// *y = elemento no endereço de memória y = 2
// *z = elemento no endereço de memória z = 6

// etc...

// 1-b)
// i = 3; j = 5
// a = endereço de memória de i 
// b = endereço de memória de j
// i = 4
// j = 4 + 5 = 9
// b = a = endereço de memória de i 
// j = 9 + 4 = 13

//2
void swapM(int *x , int *y){
    int aux = *y;
    *y = *x;
    *x = aux;
}

//3 (não tenho 100% de certeza não percebi bem o enunciado se era isto mas deve ser)
void swap(int v[], int i, int j){
    int aux = j;
    j = i;
    i = aux;
}

//4
int soma (int v[], int N) {
    int somaT = v[0]; 
        for(int i=1; i < N; i++){
            somaT += v[i];
        }
    return somaT;
}

//5 - a)
void inverteArray(int v[], int N){
    for(int i=0 ; i < N/2 ; i++) {
        swap(v,i,N-i-1);
    }
}

// # As diferenças entre o 5-a) e o 5-b) 
// 5-a) inverte a partir do valor do elementos
// 5-b) inverte a partir dos endereços de memória onde estão guardados os elementos

//5 - b)
void inverteArray(int v[], int N){
    for(int i=0 ; i < N/2 ; i++){
         swapM(v+i, v+N-i-1);
    }
}

//6 
int maximum (int v[], int N, int *m) {
    if (N < 1) return -1;
    *m = v[0]
    for(int i=0; i < N;i++){
        if (*m < v[i]) *m = v[i];
    }
    return 0;
}

//7 
void quadrados (int q[], int N){
    for(int i=0; i < N; i++){
        q[i] = i*i;
    }
}

//8 - a)
void pascal (int v[], int N){
        for(int i = 1; i <= N; i++) {
            v[i-1] = 1; 
            for (int j = i-2; j > 0; j--) {
                v[j] = v[j] + v[j-1];
            }
        }
}

//8 - b)
void pascal2(int v[], int N){
    if(N == 0){ v[0] = 1;}
    else{
    for(int i = 1; i <= N; i++) {
        v[i-1] = 1; 
        for (int j = i-2; j > 0; j--) {
            v[j] = v[j] + v[j-1];
        }
    }
    }
    for(int i=0; i < N ; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void desenha(int N){
  for(int i = 0; i < N ; i++){
    int q[i+1];
    pascal2(q, i+1);
   }
}