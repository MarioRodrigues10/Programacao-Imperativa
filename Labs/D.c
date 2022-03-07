/* COMO APENAS 7 ALUNOS (INCLUINDO EU) FORAM OS ÚNICOS A CONSEGUIR 100 PONTOS NÃO ACHEI POR BEM PARTILHAR (PRA JÁ) ESSA RESOLUÇÃO */
/* E COMO GRANDE PARTE JÁ CONSEGUIU OS 90 PONTOS INICIAIS, ESTÁ AQUI UM EXEMPLO DE SOLUÇÃO PARA OS MAIS ATRAPALHADOS */

#include <stdio.h>

int primos(int a,int b){
    int qntPrimos=0;
    if (a==1) a+=1;
    while(a<=b){
        int flag_var=0;
        for(int j=2; j<=a/2; j++)
        {
             if(a%j==0){
                flag_var = 1;
                break;
            }
        } 
            if(flag_var==0) qntPrimos++;
            a++;
    }
    return qntPrimos;
}
int triangulares(int a, int b){
    int contador = 0;
    while(a <= b){
        for(int i=1; i <= a; i++){
            if((i*(i+1)/2) == a) contador++;
            else if ((i*(i+1)/2) > a) break;      
        }
        a++;
    }
    return contador;
}

int main(){
    int x,y;
    if(scanf("%d %d\n",&x,&y)){
        if (x < y) printf("%d %d\n",triangulares(x,y),primos(x,y));
        else printf("%d %d\n",triangulares(y,x),primos(y,x));
    }
}
