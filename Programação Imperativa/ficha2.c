// 1
float multInt1(int n , float x){
    int r = 0;
    for(int i=0; i < n; i++){
        r += x*i;
    }
    return r;
}

// 2
float multInt2 (int n, float m){
    float r = 0, i = 1;
    while (n > 0){
        if (n % 2 != 0){ 
            r += m; 
        }
        n = n / 2;
        m = m*2;
    }
    return r;
}

//3
int mdc1(int a,int b){
    int menor = a >= b ? a : b;
    int divisorComum; 
    for(int i=1; i <= menor; i++){
        if(a % i == 0 && b % i == 0){
            divisorComum = i;
        }
    }
    return divisorComum;
}

//4 
int mdc2(int a,int b){
   while (a != 0 || b != 0){
       if(a > b) {a = a-b;}
       else if(b > a){ b = b-a; }
       else { return a;}
   }
}

//5
int mdc3(int a,int b){
   while (a != 0 || b != 0){
       if(a > b) {a = a%b;}
       else if(b > a){ b = b%a ; }
       else { return a;}
   }
}

//6
int fib1(int n){
    if (n == 1) {
         return 1;
    }
    else{
        return fib1(n-1) + fib1(n-2);
    }
}

//7
int fib2(int n) {
    int i=2, v1=1, v2=1;
    while (i != n) {
        v2 += v1;
        v1 = v2 - v1;
        i++;
    }
    return v2;
}