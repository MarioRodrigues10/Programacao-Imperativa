#include <stdio.h>
#include <string.h>
#define max 10000
int checkString(char *s);
int main(){
    char palavra[max];
    if (scanf("%s", palavra)) {
        printf("%d\n", checkString(palavra));
    }
    return 0;
}

int checkString(char *s){
    int tamanhoSS=1, lenght = (int)strlen(s), varControlo=0;
    for(int i = 0; i < lenght ; i++){
        for(int j = i+1; j < lenght; j++){
            if(s[i] == s[j]){
                int check = j-i+1;
                for(int h = 1; h < check/2 ; h++){
                    if(s[i+h] != s[j-h]){
                     varControlo = 1;
                     h = check; 
                    }
                }
                if (varControlo == 0 && tamanhoSS < check) tamanhoSS = check;
            }
            varControlo = 0;
        } 
    }
    return tamanhoSS;
}