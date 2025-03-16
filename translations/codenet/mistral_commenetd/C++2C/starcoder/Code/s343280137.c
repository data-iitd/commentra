#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

#define MAX 1000000000
#define MOD 1000000007

int main(){
    int n,c;
    scanf("%d %d",&n,&c);
    int x[n+1],v[n+1];
    for(int i = 1; i < n+1; i++){
        scanf("%d %d",&x[i],&v[i]);
    }

    int lefttotal[n+1],maxlefttotal[n+1];
    lefttotal[0] = 0;
    maxlefttotal[0] = 0;
    for(int i = 1; i < n+1; i++){
        lefttotal[i] = lefttotal[i-1] + v[i];
        maxlefttotal[i] = max(maxlefttotal[i-1],lefttotal[i]-x[i]);
    }

    int righttotal[n+1],maxrighttotal[n+1];
    righttotal[0] = 0;
    maxrighttotal[0] = 0;
    for(int i = 1; i < n+1; i++){
        righttotal[i] = righttotal[i-1] + v[n-i+1];
        maxrighttotal[i] = max(maxrighttotal[i-1],righttotal[i] -(c - x[n+1-i]));
    }

    int ans = 0;
    for(int i = 1; i < n+1; i++){
        ans = max(ans,lefttotal[i]-x[i]);
        ans = max(ans,lefttotal[i]-2*x[i]+maxrighttotal[n-i]);
        ans = max(ans,righttotal[i]-(c -x[n+1-i]));
        ans = max(ans,righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i]);
    }

    printf("%d\n",ans);

    return 0;
}

