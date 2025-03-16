#include <stdio.h>
#include <stdbool.h>
#include <vector>

#define MAXN 100000

std::vector<int> G[MAXN];
bool used[MAXN];
int grundy[MAXN];

void dfs(int v){
    used[v] = true;
    grundy[v] = 0;
    for(int i = 0; i < G[v].size(); i++){
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
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(0);
    if(grundy[0] != 0){
        printf("Alice\n");
    }else{
        printf("Bob\n");
    }
}
