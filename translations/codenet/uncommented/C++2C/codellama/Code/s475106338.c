#include <stdio.h>
int main(void){
    int i,t,n;
    for(i=0; i<4; i++){
        scanf("%d %d", &t, &n);
        if(t==1){
            printf("%d\n", 6000*n);
        }
        else if(t==2){
            printf("%d\n", 4000*n);
        }
        else if(t==3){
            printf("%d\n", 3000*n);
        }
        else if(t==4){
            printf("%d\n", 2000*n);
        }
    }
}
