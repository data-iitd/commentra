
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N;
    scanf("%d", &N);
    int G[100000][100000];
    int used[100000];
    int grundy[100000];
    for(int i = 0; i < N-1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        G[x][G[x].size()] = y;
        G[y][G[y].size()] = x;
    }
    dfs(0);
    if(grundy[0]!= 0){
        printf("Alice\n");
    }else{
        printf("Bob\n");
    }
}

