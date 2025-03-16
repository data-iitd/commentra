#include <iostream>
#include <vector>

using namespace std;

// Function to read a single integer from standard input.
int nextInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read `n` integers from input and return them as a vector.
vector<int> nextInts(int n) {
    vector<int> slice(n);
    for (int i = 0; i < n; i++) {
        slice[i] = nextInt();
    }
    return slice;
}

int main() {
    int n = nextInt();
    int k = nextInt();
    vector<int> a = nextInts(n);
    // Set the first element of `a` to 0 to avoid unused variable error.
    a[0] = 0;

    int sum = k;
    int ans = 1;
    // Loop to increment `sum` and `ans` until `sum` is less than `n`.
    while (sum < n) {
        sum = sum - 1 + k;
        ans++;
    }
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
