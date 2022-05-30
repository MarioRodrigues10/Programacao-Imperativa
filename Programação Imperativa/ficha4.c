// 1 - Conta Vogais

int contaVogais(char *s) {
    int cont = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            cont++;
        }
    }
    return cont;
}

// 2 - Remove Vogais Repetidas (Esta retorna quantas vogais foram removidas)

int removeVogaisRep(char *s){
    int count = 0;
    for (int j = 0; s[j] != '\0'; j++) {
        if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
            if (s[j+1] != 'a' && s[j+1] != 'e' && s[j+1] != 'i' && s[j+1] != 'o' && s[j+1] != 'u') {
                count++;
                j++;
            }
        }
    }
    return count;
}

// Esta retorna a string com as vogais removidas
char* removeVogaisString(char *s){
    char *nova = (char*)malloc(sizeof(char)*(strlen(s)+1));
    int i = 0;
    for (int j = 0; s[j] != '\0'; j++) {
        if ((s[j] == 'a' && s[j+1] == 'a') || (s[j] == 'e' && s[j+1] == 'e') || (s[j] == 'i' && s[j+1] == 'i') || (s[j] == 'o' && s[j+1] == 'o') || (s[j] == 'u' && s[j+1] == 'u')) {
                nova[i] = s[j];
                i++;
                j++;
        }
        else {
            nova[i] = s[j];
            i++;
        }
    }
    nova[i] = '\0';
    return nova;
}

// 3 - Duplica Vogais (retorna quantas vogais têm de ser duplicadas)

int duplicaVogais(char *s){
    int count = 0;
    for (int j = 0; s[j] != '\0'; j++) {
        if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
            count++;
        }
    }
    return count;
}


// devolve a String com as vogais duplicadas
char* duplicaVogaisString(char *s){
    char *nova = (char*)malloc(sizeof(char)*(strlen(s)+1));
    int i = 0;
    for (int j = 0; s[j] != '\0'; j++) {
        if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
            nova[i] = s[j];
            i++;
            nova[i] = s[j];
            i++;
        }
        else {
            nova[i] = s[j];
            i++;
        }
    }
    nova[i] = '\0';
    return nova;
}

// ARRAYS

// 1 - Verificar se um array está ordenado

int ordenado(int v[], int N){
    for (int i = 0; i < N-1; i++) {
        if (v[i] > v[i+1]) {
            return 0;
        }
    }
    return 1;
}

// 2 - Merge (recebe 2 arrays ordenados e retorna um array ordenado)

void merge(int a[], int na, int b[], int nb , int r[]){
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) {
        if (a[i] < b[j]) {
            r[k] = a[i];
            i++;
        }
        else {
            r[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < na) {
        r[k] = a[i];
        i++;
        k++;
    }
    while (j < nb) {
        r[k] = b[j];
        j++;
        k++;
    }
}

// 3 
int partition (int v[], int N, int x){
    int i = 0;
    for (int j = 0; j < N; j++) {
        if (v[j] < x) {
            i++;
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    return i;
}

