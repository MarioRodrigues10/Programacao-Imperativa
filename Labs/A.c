#include <stdio.h>

int main(){
	int x,y;
	if(scanf("%d %d", &x, &y)){
		if(x > y){
			printf("%d\n",x*x);
		}
		else if(y > x){
			printf("%d\n",y*y);
		}
		else{
			printf("IGUAIS\n");
		}
	}
	return 0;
}