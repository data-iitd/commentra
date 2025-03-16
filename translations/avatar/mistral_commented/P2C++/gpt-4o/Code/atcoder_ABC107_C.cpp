#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Function to check the minimum number of moves required to make the sum of the first k elements equal to or less than 0
int check(int k, const vector<int>& lst_p, const vector<int>& lst_m) {
    int ans = numeric_limits<int>::max();
    int lastx = lst_p.size();
    int lasty = lst_m.size();

    for (int j = 0; j <= k; j++) {
        if (j > lastx || k - j > lasty) {
            continue;
        }

        int p = (j == 0) ? 0 : lst_p[j - 1];
        int m = (k - j == 0) ? 0 : lst_m[lasty - (k - j)];

        ans = min(ans, 2 * p + abs(m));
        ans = min(ans, p + 2 * abs(m));
    }

    return ans;
}

int main() {
    // Taking the number of elements N and the number of queries K as input
    int N, K;
    cin >> N >> K;

    // Creating a vector to store the numbers
    vector<int> lst(N);
    vector<int> lst_p, lst_m;

    // Taking the list of numbers as input
    for (int i = 0; i < N; i++) {
        cin >> lst[i];
        if (lst[i] == 0) {
            K--;
        } else if (lst[i] > 0) {
            lst_p.push_back(lst[i]);
        } else {
            lst_m.push_back(lst[i]);
        }
    }

    // Printing the minimum number of moves required to make the sum of the first K elements equal to or less than 0
    cout << check(K, lst_p, lst_m) << endl;

    return 0;
}

// <END-OF-CODE>
