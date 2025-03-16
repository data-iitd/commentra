
```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,j) FOR(i,0,j)
#define mp std::make_pair

const int INF = 1 << 24;
const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

const int MOD = 1e9 + 7;

int main(){
    int H, N;
    std::cin >> H >> N;

    int a = 0;
    REP(i, N){
        int tmp;
        std::cin >> tmp;
        a += tmp;
    }

    if(H > a){
        std::cout << "No" << std::endl;
    }else{
        std::cout << "Yes" << std::endl;
    }

    return 0;
}

