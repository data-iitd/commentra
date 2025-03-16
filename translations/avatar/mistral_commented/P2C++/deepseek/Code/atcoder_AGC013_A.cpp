#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cmath>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <sstream>
#include <climits>
#include <cstring>
#include <cstdio>
#include <tuple>
#include <iomanip>

using namespace std;

#define INT(...) 
#define INT(...) int, __VA_ARGS__
#define INT(...) vector<int>, __VA_ARGS__
#define LIST(...) vector<__VA_ARGS__>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    LIST(int) A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    A.erase(unique(A.begin(), A.end()), A.end());
    N = A.size();

    int i = 1;
    int ans = 0;

    while (i < N - 1) {
        if ((A[i - 1] < A[i] && A[i] > A[i + 1]) || (A[i - 1] > A[i] && A[i] < A[i + 1])) {
            ans++;
            i++;
        }
        i++;
    }

    cout << ans + 1 << '\n';

    return 0;
}
