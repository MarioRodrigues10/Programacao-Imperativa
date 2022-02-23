void quadrado(int n) {
     for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            printf("#");
        }
        printf("\n");
     }
    return 0;
}


void xadrez(int n){
 for(int i=0; i < n;i++){
    for(int j=0; j < n; j++){
        if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)){
            printf("#");
        }
        else{
            printf("_");
        }
    }
    printf("\n");
 }
}

void tri1(int n){
   for(int i = 0; i <= 2 * n; i++) {
        for(int j = 0; j <= 2 * n - i; j++) {
            if(j <= i){
                printf("#");
            }
        }
        printf("\n");
    }
}


void tri2(int n)
{
    int i,j;
    for(i=1; i<=n; i++)
        {
            for(j=1;j<=n-i; j++)
            {
                printf(" ");
            }
            for(j=1; j<=2*i-1; j++)
            {
                printf("#");
            }
            printf("\n");
    }
}

void circulo(int n) {
    int num = 0;
    float a,b,c;
    for (int i =  0; i < n*2+1; i++) {
        for (int j = 0; j < n*2+1; j++) {
            a = n - i;
            b = n - j;
            c = sqrt(a*a+ b*b);
            if (c <= n) {
                printf('#');
                num++;
            }
            else printf(' ');
        }
        printf('\n');
    }
    return 0;
}

