
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define MOD 100000007
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define IINF 100000000
#define LLINF 100000000000000000
#define SIZE 100000
#define MAX_N 100000

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int ball[MAX_N][2] = {0};
    rep(i,n){
        ball[i][0] = 1;
    }
    rep(i,m){
        int x,y;
        scanf("%d %d",&x,&y);
        x--;
        y--;
        if(ball[x][0] == 1){
            ball[x][0] = 0;
            ball[y][1]++;
        }else if(ball[x][1] == 1){
            ball[x][1] = 0;
            ball[y][0]++;
        }else if(ball[x][0] == 0){
            ball[x][0] = 1;
            ball[y][0]++;
        }else if(ball[x][1] == 0){
            ball[x][1] = 1;
            ball[y][1]++;
        }
    }
    int ans = 0;
    rep(i,n){
        if(ball[i][1] == 1) ans++;
    }
    printf("%d\n",ans);
    return 0;
}

