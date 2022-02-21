#include <stdio.h>
#include <stdlib.h>

int main()
{
   int baseMaior, altura, baseMenor;
   if(scanf("%d %d %d", &baseMaior , &altura, &baseMenor)){
        int p = ((3.14*altura / 3) * (baseMaior*baseMaior + baseMaior*baseMenor + baseMenor*baseMenor));
        printf("%d", p);
    }
    return 0;
}