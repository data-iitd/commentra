
#include <stdio.h>
#include <stdlib.h>

void out(int argc,...){
    va_list args;
    va_start(args, argc);
    for(int i = 0; i < argc; i++){
        printf("%d ", va_arg(args, int));
    }
    printf("\n");
    va_end(args);
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int **G = (int **)malloc(sizeof(int *) * N);
    for(int i = 0; i < N; i++){
        G[i] = (int *)malloc(sizeof(int) * N);
        for(int j = 0; j < N; j++){
            G[i][j] = 0;
        }
    }
    for(int i = 0; i < M; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        G[from - 1][to - 1] = 1;
        G[to - 1][from - 1] = 1;
    }
    for(int i = 0; i < N; i++){
        int count = 0;
        for(int j = 0; j < N; j++){
            count += G[i][j];
        }
        out(1, count);
    }
    for(int i = 0; i < N; i++){
        free(G[i]);
    }
    free(G);
    return 0;
}
