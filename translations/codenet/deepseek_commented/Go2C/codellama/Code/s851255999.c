
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct work{
    int time;
    int limit;
}work;

int compare(const void *a, const void *b){
    work *w1 = (work *)a;
    work *w2 = (work *)b;
    return w1->limit - w2->limit;
}

int main(){
    int n;
    scanf("%d", &n);
    
    work *ws = (work *)malloc(n * sizeof(work));
    
    for(int i = 0; i < n; i++){
        scanf("%d %d", &ws[i].time, &ws[i].limit);
    }
    
    qsort(ws, n, sizeof(work), compare);
    
    long long sum = 0;
    
    for(int i = 0; i < n; i++){
        sum += ws[i].time;
        
        if(sum > ws[i].limit){
            printf("No\n");
            return 0;
        }
    }
    
    printf("Yes\n");
    
    return 0;
}

