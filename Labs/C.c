#include <stdio.h>

int testaFATORIAL();
int main(){
    int a,b,c;
   if(scanf("%d %d %d\n", &a, &b, &c)){
       if(a > b && b > c){
           if (testaFATORIAL(a) == 1) { printf("FATORIAL\n"); }
           else{ printf("%d %d %d\n", c,b,a);}
       }
       else if(a > c && c > b){
           if (testaFATORIAL(a) == 1) { printf("FATORIAL\n"); }
           else { 
               printf("%d %d %d\n", b,c,a); }
       }
       else if(b > c && c > a){
           if (testaFATORIAL(b) == 1) { printf("FATORIAL\n"); }
           else {printf("%d %d %d\n", a,c,b);}
       }
       else if(b > a && a > c){
           if (testaFATORIAL(b) == 1) { printf("FATORIAL\n"); }
           else {printf("%d %d %d\n", c,a,b); }
       }
       else if(c > b && b > a){
           if (testaFATORIAL(c) == 1) { printf("FATORIAL\n"); }
           else{ 
               printf("%d %d %d\n", a,b,c);}
       }
       else if (c > a && a > b){
           if (testaFATORIAL(c) == 1) { printf("FATORIAL\n"); }
           else{ 
               printf("%d %d %d\n", b,a,c);}
       }
   } 
}

int testaFATORIAL(int n){
    int f = 1, i = 1;
    while(f < n){
        f = f*i;
        i++;
    }
    if (f == n){
        return 1;
    }
    else{
        return 0;
    }
}
