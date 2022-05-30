typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

// Errada , eu não sei calcular a nota de PI
// 1) Calcular a nota do aluno , com base nos critérios de PI
int nota(Aluno a){
    int soma = 0;
    for (int i = 0; i < 6; i++) {
        soma += a.miniT[i];
    }
    return (soma + a.teste);
}


// 2 ) Procurar um aluno num array ordenado
int procuraNum (int num, Aluno t[], int N) {
    for (int i = 0; i < N; i++) {
        if (t[i].numero == num) {
            return i;
        }
    }
    return -1;
}

// 3) Ordenar um array de Alunos por numero de aluno
void ordenaPorNum(Aluno t[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (t[i].numero < t[j].numero) {
                Aluno aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
}

// 4) 


// 5) imprime a turma em ordem númerica, alfabética e por notas
void imprimeTurma (int ind[], Aluno t[], int N){
    // ordena por numero de aluno
    ordenaPorNum(t, N);
    // ordenar por nome de aluno
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (strcmp(t[i].nome, t[j].nome) < 0) {
                Aluno aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    // imprime a turma
    for (int i = 0; i < N; i++) {
        printf("%d %s %d %d %d %d %d %f\n", t[i].numero, t[i].nome, t[i].miniT[0], t[i].miniT[1], t[i].miniT[2], t[i].miniT[3], t[i].miniT[4], t[i].teste);
    }
    
}