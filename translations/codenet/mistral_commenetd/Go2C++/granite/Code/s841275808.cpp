

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> X(N), Y(N);
    for(int i=0; i<N; i++){
        cin >> X[i];
        Y[i] = X[i];
    }
    sort(Y.begin(), Y.end());
    int m1 = Y[N/2-1];
    int m2 = Y[N/2];
    for(int i=0; i<N; i++){
        if(X[i] <= m1) cout << m2 << endl;
        else cout << m1 << endl;
    }
    return 0;
}

// 