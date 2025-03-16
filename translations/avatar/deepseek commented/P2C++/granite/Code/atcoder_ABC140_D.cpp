
#include <iostream>  // Include the necessary libraries for input/output operations
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <cassert>
#include <random>
#include <chrono>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;

const int MOD = 1e9 + 7;  // Define a constant for modulo operation

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    int seg_cnt = 0;  // Initialize a counter for the number of segments
    for (int i = 0; i < N - 1; i++) {  // Loop through the string to count segments
        if (S[i]!= S[i + 1]) {  // Check if the current character is different from the next
            seg_cnt++;  // Increment the segment counter if a change is found
        }
    }

    int cur_happy = N - 1 - seg_cnt;  // Calculate the initial happiness based on the number of segments

    if (2 * K >= seg_cnt) {  // Check if the number of operations allows for maximum happiness
        cout << N - 1 << endl;  // If yes, set the answer to the maximum possible happiness
    } else {
        cout << cur_happy + 2 * K << endl;  // Otherwise, adjust the happiness based on the number of operations
    }

    return 0;
}

