
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#define MOD 100000007
#define ll long long
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Setting the modulus value
    const ll mod = 100000007;

    // Reading input values: N, A, and B
    ll N, A, B;
    cin >> N >> A >> B;

    // Initializing the answer variable to 0
    ll ans = 0;

    // Calculating the number of repetitions
    ll rep = N / (A + B);

    // Adding the number of blocks that can be fully covered by A and B in one repetition
    ans += rep * A;

    // Calculating the remaining number of blocks
    ll res = N - rep * (A + B);

    // Adding the number of blocks that can be covered by A in the remaining blocks
    ans += min(res, A);

    // Printing the final answer
    cout << ans << endl;

    return 0;
}

