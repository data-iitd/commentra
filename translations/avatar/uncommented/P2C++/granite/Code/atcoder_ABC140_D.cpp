
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <stack>
#include <numeric>
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define pi pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int seg_cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (S[i]!= S[i + 1]) {
            seg_cnt++;
        }
    }
    int cur_happy = N - 1 - seg_cnt;
    if (2 * K >= seg_cnt) {
        cout << N - 1 << endl;
    } else {
        cout << cur_happy + 2 * K << endl;
    }
    return 0;
}

