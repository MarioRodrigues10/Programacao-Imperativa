//1
int maxElement(){
    int n,max=0;
    while(n != 0){
        scanf("%d", &n);
        if(n > max) max = n;
    }
    return max;
}

//2
float mediaSeq(){
    int n=1, i=0;
    float media=0;
    while(n != 0){
        scanf("%d", &n);
        media += n;
        i++;
    }
    media = media/i;
    return media;
}

//3
int segundoMaior(){
    int n=1, max=0,max2=0;
    while(n != 0){
        scanf("%d", &n);
        if(n >= max){
            max2 = max;
            max = n;
        }
        else if(n > max2 && n < max){
            max2 = n;
        }
    }
    return max2;
}

//4 
int bitsUm(unsigned int n){
    int uns=0;
    while(n > 0){
        if(n % 2 == 1) uns++;
        n = n/2;
    }
}

//5 
int trailingZ(unsigned int n){
    int zeros = 0;
     while(n > 0){
        if(n % 2 == 0) zeros++;
        n = n/2;
    }   
}


//6
int qDig(unsigned int n){
  int x = 10,i=0;
  for(i; n > 1; i++){
      n = n / 10;
  }
  printf("%d\n", i);
  return i;
}


//7
char *strcat(char s1[], char s2[]){
    int i,j;
    for(i=0; s1[i] != '\0'; i++);
    for(j=i; s2[i] != '\0'; j++,i++){
        s1[i] = s2[j];
    }
    return s1;
}

//8
char *strcpy(char *dest, char *source){
    int i;
    for( i=0; source[i] != '\0'; i++){
        dest[i] = source[i];
    }
    dest[i] = '\0';
}

//9
int strcmp(char s1[], char s2[]){
    int i;
    for(i=0; s1[i] != '\0' && s2[i] != '\0'; i++){
        if(s1[i] != s2[i]) return s1[i] - s2[i];
    }
    return s1[i] - s2[i];
}

//10
char *strstr(char s1[], char s2[]){
  int i,j,k;
  if (s2[0] == '\0') return s1;
  for(i=0; s1[i] != '\0'; i++){
    for(j=i,k=0; s2[k] != '\0' && s1[j] == s2[k]; j++,k++);
    if(k == strlen(s2)) return s1+i;
  }
  return NULL;
}

//11
void strrev(char s[]){
  int i,j;
  for(i=0,j=strlen(s)-1; i<j; i++,j--){
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}

//12
void strnoV (char t[]){
    int i, pos;
    for (i = 0, pos = 0; t[i] != '\0';i++) {
        if (t[i] != 'a' && t[i] != 'e' && t[i] != 'i' && t[i] != 'o' && t[i] != 'u' && t[i] != 'A' && t[i] != 'E' &&t[i] != 'I' &&t[i] != 'O' &&t[i] != 'U') {
			t[pos++] = t[i];
		}
    }
    t[pos] = '\0';
}

//13
void truncW(char t[], int n) {
    int i = 0;
    int j = 0;
    int count = 0;
    while (t[i] != '\0') {
        if (!isspace(t[i])) {
            if (count < n) {
                t[j] = t[i];
                j++;
            }
            count++;
        } else {
            count = 0;
            t[j] = ' ';
            j++;
        }
        i++;
    }
    t[j] = '\0';
}

//14
char charMaisFreq(char s[]){
  int i,j,k,maisFreq=0,freq=0,pos=0;
  for(i=0; s[i] != '\0'; i++){
    for(j=i,k=0; s[j] != '\0'; j++,k++){
      if(s[i] == s[j]){
        freq++;
      }
    }
    if(freq > maisFreq){
      maisFreq = freq;
      pos = i;
    }
    freq = 0;
  }
  return s[pos];
}

//15
int iguaisConsecutivos(char s[])
{
    char a, mf;
    int count,max=0;
    for(int i=0; s[i] != '\0';i++){
        count = 0;
        a = s[i];
        for(int j=i+1; s[j] != '\0'; j++){
            if(a == s[j]){
                count++;
            }
            else {
                j = strlen(s);
            }
        }
        if (max < count){
            mf = a;
            max = count;
        }
    }
    return max;
}


//16 (hard) (Sofia solution)
int difConsecutivos(char s[]) {
    int ans = 0;
    for(size_t i = 0; s[i]; i++) {
        int consec = 0;
        for(size_t j = i; s[j]; j++) {
            if(not_in_prev(s,i,j)) consec++;
            else break;
        }
        if (consec > ans) ans = consec;
    }
    return ans;
}

//17
int maiorPrefixo(char s1[],char s2[]){
    int i,j,k;
    for(i=0;s1[i]!='\0';i++);
    for(j=0;s2[j]!='\0';j++);
    for(k=0;s1[k]==s2[k]&&k<i;k++);
    return k;
}

//18
int maiorSufixo(char s1[],char s2[]){
    int i, j, ans = -1;
    for(i = 0; s1[i]; i++);
    for(j = 0; s2[j]; j++);
    while(s1[i--] == s2[j--]) ans++;
    return ans;
}

//19
int sufPref(char s1[], char s2[]){
        int ans = 0, i, j = 0;
    for(i = 0; s1[i]; i++) {
        if(s1[i] == s2[j++]) ans++;
        else ans = j = 0;
    }
    return ans;
}

//20
int contaPal(char s[]){
    int word = 0, total = 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] == ' ' || s[i] == '\n') {
            if(word) total++;
            word = 0;
        }
        else word = 1;
    }
    if(word) total++;
    return total;
}

//21
int contaVogais(char s[]){
    int i,count = 0;
    for(i =0 ; s[i] != '\0'; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            count++;
        }
    }
    return count;
}

//22
int contida(char s1[],char s2[]){
    int i,j;
    for(i=0;s1[i]!='\0';i++){
        for(j=0;s2[j]!='\0';j++){
            if(s1[i]==s2[j]){
                break;
            }
        }
        if(s2[j]=='\0'){
            return 0;
        }
    }
    return 1;
}

//23
int palindrome(char s[]){
    int i, j;
    for(i = 0, j = strlen(s)-1; i < j; i++, j--)
        if(s[i] != s[j]) return 0;
    return 1;
}

//24
int remRep(char x[]){
    int i, j;
    for (i = 0, j = 0; x[i] != '\0'; i++) {
        if (x[i] != x[i+1]) {
        x[j] = x[i];
        j++;
        }
    }
    x[j] = '\0';
    return j;
}

//25
int limpaEspacos(char t[]){
    int i, j;
    for(i = 0, j = 0; t[i] != '\0'; i++){
        if(t[i] != ' ' || (t[i] == ' ' && t[i+1] != ' ')){
        t[j] = t[i];
        j++;
        }
    }
    t[j] = '\0';
    return j;
}

//26
void insert(int v[],int N, int x){
    for(int i = 0; i < N; i++) {
        if(v[i] > x) {
            for(int j = N; j > i; j--) {
                v[j] = v[j - 1];
            }
            v[i] = x;
            break;
        }
        if(i == N - 1) {
            v[N] = x;
        }
    }
}

//27
void merge (int r [], int a[], int b[], int na, int nb) {
    int i = 0, j = 0, k = 0;
    while(k < na + nb) {
        if((a[i] < b[j] && i < na) || j >= nb)
            r[k++] = a[i++];
        else
            r[k++] = b[j++];
    }
}

//28
int crescente(int a[],int i,int j){
    for(int k = i; k < j; k++) {
        if(a[k] > a[k+1]) {
            return 0;
        }
    }
    return 1;
}

//29
int retiraNeg (int v[],int N){
    int i, j;
    for(i = 0, j = 0; i < N; i++) {
        if(v[i] >= 0) {
            v[j] = v[i];
            j++;
        }
    }
    return j;
}


//30 
int menosFreq (int v[], int N) {
    int freq = 1, minFreq = N, ans = v[0], i;
    for(i = 1; i < N; i++) {
        if(v[i] == v[i - 1]) freq++;
        if(v[i] != v[i - 1]) {
            if(freq < minFreq) {
                minFreq = freq;
                ans = v[i - 1];
            }
            freq = 1;
        }
    }
    if(freq < minFreq) {
        minFreq = freq;
        ans = v[i - 1];
    }
    return ans;
}

//31
int maisFreq (int v[], int N){
    int i, j, maior = 0, freq = 0, aux = 0;
    for(i = 0; i < N; i++){
        for(j = i; j < N; j++){
        if(v[i] == v[j]){
            aux++;
        }
        }
        if(aux > freq){
        freq = aux;
        maior = v[i];
        }
        aux = 0;
    }
    return maior;
}


//32
int maxCresc (int v[], int N){
    int i, j, max = 0, aux = 0;
    for(i=0; i < N; i++){
        aux = 1;
        for(j=i; j < N; j++){
            if(v[j] <= v[j+1]){
                aux++;
            }
            else{
                break;
            }
        }
        if (max < aux){
            max = aux;
        }
    }
    return max;
}


//33
int elimRep(int v[],int n){
    int i,j,k;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
        if(v[i] == v[j]){
            for(k=j; k<n; k++){
            v[k] = v[k+1];
            }
            n--;
            j--;
        }
        }
    }
    return n;
}

//34
int elimRepOrd (int v[], int n){
    int i,j,k;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
        if(v[i] == v[j]){
            for(k=j; k<n; k++){
            v[k] = v[k+1];
            }
            n--;
            j--;
        }
        }
    }
    return n;
}

//35
int comunsOrd (int a[], int na, int b[], int nb) {
    int i = 0, j = 0, ans = 0;
    while(i < na && j < nb) {
        if(a[i++] == b[j++]) {
            ans++;
            i++;
            j++;
        }
        else if(a[i] > b[j]) j++;
        else i++;
    }
    return ans;
}

//36
int comuns (int a[], int na, int b[], int nb) {
    int ans = 0;
    for(int i = 0; i < na; i++) {
        for(int j = 0; j < nb; j++) {
            if(a[i] == b[j]){
                ans++;
            }
        }
    }
    return ans;
}

//37
int minInd(int v[],int n){
    int min=v[0];
    int ind=0;
    for(int i=1; i < n;i++){
        if(v[i] < min){
            min = v[i];
            ind = i;
        }
    }
    return ind;
}
int minInd(int v[],int n){
    int min=v[0];
    int ind=0;
    for(int i=1; i < n;i++){
        if(v[i] < min){
            min = v[i];
            ind = i;
        }
    }
    return ind;
}


//38
void somasAc(int v[], int Ac[], int N){
    int i;
    for(int j=0; j < N; j++){
        Ac[j] = 0;
    }
    for(i=0; i < N; i++){
        for(int j=0; j <= i; j++){
            Ac[i] += v[j];
        }
    }
    for(int i=0; i < N; i++){
        printf("%d ", Ac[i]);
    }
}

//39
int triSup (int N, float m [N][N]){
    int i,j;
    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
        if(i > j && m[i][j] != 0){
            return 0;
        }
        }
    }
    return 1;
}

//40
void transposta (int N, float m[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            float temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

//41 (not sure)
void addTo(int N, int M, int A[N][M], int B[N][M]){
    for(int i=0; i< N ; i++){
        for(int j=0; j < M ; j++){
            A[i][j] += B[i][j];
        }
    }
}

// 42
int unionSet (int N, int v1[N], int v2[N], int r[N]) {
    int count = 0;
    for(int i = 0; i < N; i++) {
        r[i] = v1[i] || v2[i];
        count += r[i];
    }
    return count;
}

// 43
int intersectSet (int N, int v1[N], int v2[N],int r[N]) {
    int count = 0;
    for(int i = 0; i < N; i++) {
        r[i] = v1[i] && v2[i];
        count += r[i];
    }
    return count;
}

// 44
int intersectMSet (int N, int v1[N], int v2[N],int r[N]) {
    int count = 0;
    for(int i = 0; i < N; i++) {
        if( v1[i] < v2[i]){
            r[i] = v1[i];
        }
        else {
            r[i] = v2[i];
        }
        count += r[i]; 
    }
    return count;
}

// 45
int unionMSet (int N, int v1[N], int v2[N], int r[N]){
	int i;
	int res = 0;
	for (i = 0; i < N; i++){
		if (v1[i] > v2[i]){
			r[i] = v1[i];
			res += v1[i];
		} else {
			r[i] = v2[i];
			res += v2[i];
		}
	}
	return res;
}
// 46
int cardinalMSet (int N, int v[N]) {
    int count = 0;
    for(int i = 0; i < N; i++) {
        count += v[i];
    }
    return count;
}

// Definições para representar as posições e movimentos de um robot
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;

//47
Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i= 0;
    for(; i< N; i++){
        if(mov[i]== Norte) inicial.y++;
        if(mov[i]== Sul) inicial.y--;
        if(mov[i]==Este) inicial.x++;
        if(mov[i]== Oeste) inicial.x--;
    }
    return inicial;
}

//48
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i= 0;
    for(; i< N; i++){
        if(final.y< inicial.y){
            mov[i]= Sul; inicial.y--;
        }
        else if(final.y> inicial.y){
            mov[i]= Norte; inicial.y++;
        }
        else break;
    }
    int j= i;
    for(; j< N; j++){
        if(final.x< inicial.x){
            mov[j]= Oeste;
            inicial.x--;
        }
        else if(final.x> inicial.x){
            mov[j]= Este;
            inicial.x++;
        }
        else break;
    }
    if(inicial.x!= final.x || inicial.y!= final.y) return -1;
    else return j;
}

//49
int maiscentral(Posicao pos[], int N) {
    int indice_mais_central = 0;
    int i;
    double distancia_mais_proxima = sqrt(pos[0].x * pos[0].x + pos[0].y * pos[0].y);
    for (i = 1; i < N; i++) {
        double distancia = sqrt(pos[i].x * pos[i].x + pos[i].y * pos[i].y);
        if (distancia < distancia_mais_proxima) {
            indice_mais_central = i;
            distancia_mais_proxima = distancia;
        }
    }
    return indice_mais_central;
}

//50
int vizinhos (Posicao p, Posicao pos[], int N){
    int i= 0, count= 0;
    for(; i< N; i++){
        if((pos[i].x +1== p.x && pos[i].y== p.y) || (pos[i].x -1== p.x && pos[i].y== p.y) || (pos[i].y +1== p.y && pos[i].x== p.x) || (pos[i].y- 1== p.y && pos[i].x== p.x))count++;
    }
    return count;
}
