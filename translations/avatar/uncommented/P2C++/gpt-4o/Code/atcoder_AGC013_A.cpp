#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

#define INT() ({ int x; cin >> x; x; })
#define LIST() ({ int n; cin >> n; vector<int> v(n); for (int &x : v) cin >> x; v; })

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = INT();
    vector<int> A = LIST();

    // Remove duplicates while maintaining order
    vector<int> uniqueA;
    unique_copy(A.begin(), A.end(), back_inserter(uniqueA));
    A = uniqueA;
    N = A.size();

    int ans = 0;
    for (int i = 1; i < N - 1; ) {
        if ((A[i - 1] < A[i] && A[i] > A[i + 1]) || (A[i - 1] > A[i] && A[i] < A[i + 1])) {
            ans++;
            i += 2; // Skip the next element as well
        } else {
            i++;
        }
    }

    cout << ans + 1 << endl;

    return 0;
}
// <END-OF-CODE>
