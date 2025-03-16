#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int G[100000][100000];
int used[100000];
int grundy[100000];

void dfs(int v){
    used[v] = 1;
    grundy[v] = 0;
    for(int i = 0; i < G[v][0]; i++){
        if(!used[G[v][i+1]]){
            dfs(G[v][i+1]);
            grundy[v] ^= (grundy[G[v][i+1]]+1);
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
        G[x][0]++;
        G[x][G[x][0]] = y;
        G[y][0]++;
        G[y][G[y][0]] = x;
    }
    dfs(0);
    if(grundy[0]!= 0){
        printf("Alice\n");
    }else{
        printf("Bob\n");
    }
}

