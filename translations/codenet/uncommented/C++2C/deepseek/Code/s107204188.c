#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int minA = (int)pow(10,9) + 1;
    int num = 0;
    
    int n, t, f = 0;
    scanf("%d %d", &n, &t);
    int A[n];
    
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    
    for(int i = 0; i < n; i++){
        if(minA > A[i]){
            minA = A[i];
        }else{
            
            if(f == A[i] - minA)num++;
            else if(f < A[i] - minA){
                num = 1;
                f = A[i] - minA;
            }
            
        }
    }
    
    printf("%d\n", num);
    
    
}
