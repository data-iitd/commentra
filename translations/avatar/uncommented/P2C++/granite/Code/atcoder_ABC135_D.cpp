
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second

const int mod = 1e9 + 7;
const int mxn = 1e5 + 10;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(13));
    if(s[0] == '?'){
        for(int i = 0; i < 10; i++)
            dp[0][i] = 1;
    }
    else
        dp[0][s[0] - '0'] = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == '?'){
            for(int j = 0; j < 10; j++){
                for(int k = 0; k < 13; k++){
                    dp[i][(10 * k + j) % 13] += dp[i - 1][k];
                    dp[i][(10 * k + j) % 13] %= mod;
                }
            }
        }
        else{
            int j = s[i] - '0';
            for(int k = 0; k < 13; k++){
                dp[i][(10 * k + j) % 13] += dp[i - 1][k];
                dp[i][(10 * k + j) % 13] %= mod;
            }
        }
    }
    cout << dp[n - 1][5] << endl;

    return 0;
}

