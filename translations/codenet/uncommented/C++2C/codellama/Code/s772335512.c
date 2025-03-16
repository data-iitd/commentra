#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100000

int G[MAX][MAX];
bool used[MAX];
int grundy[MAX];

void dfs(int v){
    used[v] = true;
    grundy[v] = 0;
    for(int i = 0; i < G[v][i]; i++){
        if(!used[G[v][i]]){
            dfs(G[v][i]);
            grundy[v] ^= (grundy[G[v][i]]+1);
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N-1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        G[x][y] = 1;
        G[y][x] = 1;
    }
    dfs(0);
    if(grundy[0] != 0){
        printf("Alice\n");
    }else{
        printf("Bob\n");
    }
}

