
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <random>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <typeinfo>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int (i) = (0); (i) < (int)(n); (i)++)
#define REALL(i, n) for(ll (i) = (0); (i) < (ll)(n); (i)++)
#define FOR(i, a, b) for(int (i) = (a); (i) < (int)(b); (i)++)
#define FORR(i, a, b) for(int (i) = (b)-1; (i) >= (a); (i)--)
#define foreach(it, X) for(__typeof((X).begin()) it = (X).begin(); it!= (X).end(); it++)
#define ALL(X) (X).begin(), (X).end()
#define pb push_back
#define eb emplace_back

int N;
int a[100000];
int leftl[100000];
int rightl[100000];

int main(){
    scanf("%d", &N);
    REP(i, N) scanf("%d", a+i);
    queue<int> que;
    int index = 0;
    while(index < N){
        while(!que.empty() && a[que.front()] > a[index]){
            int ind = que.front(); que.pop();
            rightl[ind] = index - ind - 1;
        }
        que.push(index++);
    }
    while(!que.empty()){
        int ind = que.front(); que.pop();
        rightl[ind] = N - ind - 1;
    }
    index = N - 1;
    while(index >= 0){
        while(!que.empty() && a[que.front()] > a[index]){
            int ind = que.front(); que.pop();
            leftl[ind] = ind - index - 1;
        }
        que.push(index--);
    }
    while(!que.empty()){
        int ind = que.front(); que.pop();
        leftl[ind] = ind - index - 1;
    }
    long long ans = 0;
    REP(i, N){
        ans += (long long)a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    printf("%lld\n", ans);
    return 0;
}
