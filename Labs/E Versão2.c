#include <stdio.h>
#include <string.h>
#define max_buffer 10000 // Máximo 10000 posições

char arr[max_buffer];
int palavra();
int main() { 
    if(scanf("%s", arr)){
        int a = strlen(arr);
        if (a == 1) printf("%d\n",a);
        else if (a == 2) printf("%d\n",a);
        else {
            printf("%d\n",palavra());
            printf("%d\n",a);
        }
    } 
    else return 1;
}
int palavra(){
    int maiorString=1,i=0;
    int tamanhoS = strlen(arr);
    int tamanhocima;
    int tamanhobaixo;
        while(i < tamanhoS){
                tamanhobaixo = i-1;
                tamanhocima = i+1;
                for(;tamanhobaixo >= 0 && arr[tamanhobaixo] == arr[i];tamanhobaixo--){
                    int tamanho = tamanhocima-tamanhobaixo+1;
                    if (tamanho > maiorString) maiorString =  tamanho;
                }
                for(;tamanhocima < tamanhoS && arr[tamanhocima] == arr[i];tamanhocima++){
                    int tamanho = tamanhocima-tamanhobaixo+1;
                    if (tamanho > maiorString) maiorString =  tamanho;
                }
                for(;tamanhocima < tamanhoS && tamanhobaixo >= 0  && arr[tamanhocima] == arr[tamanhobaixo]; tamanhobaixo--,tamanhocima++){
                     int tamanho = tamanhocima-tamanhobaixo+1;
                    if (tamanho > maiorString) maiorString =  tamanho;
                }
               
                i++;
            }  
        return maiorString;
        }  
