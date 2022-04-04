#include <stdio.h>
#include <string.h>


void criarArrEComparar(char v[], int N);
char *ordenaLista(char *str){
	int i = 0, j = 0;
	while (str[i])
	{
		if (str[i] != ' '){
          str[j++] = str[i];
        }
		i++;
	}
	str[j] = '\0';
	return str;
}

int conta3[676];
char alfa3[676][2];
int main(){
    char lista[100000];
    //printf("%d",strlen(alfa1));
    int x; 
    for(int t=0; t < 676; t++){
        conta3[t] = 0;
    //printf("%d\n",i);
    }
    if(scanf("%d\n",&x) == 1){
        while(fgets(lista,100000,stdin) != NULL){
            ordenaLista(lista);
            criarArrEComparar(lista,strlen(lista));
        }
        for(int l = 0; l < 400; l++){
            if(x <= conta3[l] && alfa3[l][1] != ' '){
                printf("%c%c = %d\n",alfa3[l][0],alfa3[l][1],conta3[l]);
            }
            else if(x <= conta3[l] && alfa3[l][1] == ' '){
                printf("%c = %d\n",alfa3[l][0],conta3[l]);
            }
            else{
                continue;
            }
        }
    
    }
    return 0;
}

void criarArrEComparar(char v[], int N){   
char alfa1[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

// Valores do Array Com todas as condições possíveis -> Estado : Feito a Funcionar (MUDAR A ORDEM)
int h = 1;
for(int t=0; t < 26;t++){
    if(t == 0){
        alfa3[t][0] = alfa1[t];
        alfa3[t][1] = ' ';
    }
    else{
        alfa3[h][0] = alfa1[t];
        alfa3[h][1] = ' ';
        h++;
    }
        //printf("%c\n",alfa3[t][0]);
        for(int j=0; j < 26;j++){
            if (t != j && t < j){
                alfa3[h][0] = alfa1[t];
                alfa3[h][1] = alfa1[j];
                //printf("%c%c\n",alfa3[h][0],alfa3[h][1]);
                h++;
            }
        }
        //printf("%d %d\n",t,h);
    }
for(int i=0; i < 400; i++){
    if(i != 0 && alfa3[i][0] == 'A' && alfa3[i][1] == ' '){
        alfa3[i][0] = alfa1[i];
    }
    else{
        continue;
    }
}

for(int t=0; t < N; t++){
    for(int i=0; i < 400; i++){
        if(v[t] == alfa3[i][0] && alfa3[i][1] == ' ') {
        conta3[i] += 1;
        //printf("%c\n",alfa3[i][0],alfa3[i][1]);
        }
    }
    for(int p=t+1; p < N; p++){
        for(int j=0; j < 400; j++){
            if((v[t] == alfa3[j][0] && v[p] == alfa3[j][1]) || (v[p] == alfa3[j][0] && v[t] == alfa3[j][1])){
                conta3[j] += 1;
                //printf("%c%c\n",alfa3[j][0],alfa3[j][1]);
            }
        }
    }    


}
}
