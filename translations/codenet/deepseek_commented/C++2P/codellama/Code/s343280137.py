#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    # Step 1: Input Reading
    LL n, c;
    cin >> n >> c;

    # Step 2: Vector Initialization
    vector<LL> x(n+1, 0), v(n+1, 0);

    # Step 3: Reading Positions and Values
    for(int i = 1; i < n+1; i++){
        cin >> x[i] >> v[i];
    }

    # Step 4: Calculate Total Value Moving Left
    vector<LL> lefttotal(n+1, 0), maxlefttotal(n+1, 0);
    for(int i = 1; i < n+1; i++){
        lefttotal[i] = lefttotal[i-1] + v[i];
    }

    # Step 5: Calculate Maximum Value Left
    for(int i = 1; i < n+1; i++){
        maxlefttotal[i] = max(maxlefttotal[i-1], lefttotal[i] - x[i]);
    }

    # Step 6: Calculate Total Value Moving Right
    vector<LL> righttotal(n+1, 0), maxrighttotal(n+1, 0);
    for(int i = 1; i < n+1; i++){
        righttotal[i] = righttotal[i-1] + v[n-i+1];
    }

    # Step 7: Calculate Maximum Value Right
    for(int i = 1; i < n+1; i++){
        maxrighttotal[i] = max(maxrighttotal[i-1], righttotal[i] - (c - x[n+1-i]));
    }

    # Step 8: Calculate the Maximum Value
    LL ans = 0;
    for(int i = 1; i < n+1; i++){
        ans = max(ans, lefttotal[i] - x[i]);
        ans = max(ans, lefttotal[i] - 2*x[i] + maxrighttotal[n-i]);
        ans = max(ans, righttotal[i] - (c - x[n+1-i]));
        ans = max(ans, righttotal[i] - 2*(c - x[n+1-i]) + maxlefttotal[n-i]);
    }

    # Step 9: Output the Result
    cout << ans << endl;
    
    return 0;
}

