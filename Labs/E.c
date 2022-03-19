#include <stdio.h>
#define max_buffer 10000 // Máximo 10000 posições

char arr[max_buffer]; 

int tamanhoArray(){
    int i; // Necessário definir fora para dar return depois
    for(i = 0; arr[i] != '\0'; i++);
    return i;
}

int maiorSeq(){
    int max=1,vcontrolo;
    for(int i = 0; i < tamanhoArray(arr); i++){
        for(int j = i+1; j < tamanhoArray(arr); j++){
            if(arr[i] == arr[j]){
                int tamanho = j-i+1;
                for(int h = 1; h < tamanho/2; h++){
                    if(arr[i+h] != arr[j-h]){
                        vcontrolo = 1;
                        break;
                    }
                }
                if(vcontrolo==0 && max<tamanho) max = tamanho;
            }
            vcontrolo = 0;
        }
    }
    return max;
}

int main() {
    if (scanf("%s", arr)){
        printf("%d\n", maiorSeq());
    }
    return 0;
}