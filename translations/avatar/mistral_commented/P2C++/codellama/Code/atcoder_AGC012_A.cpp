#######
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#######
# Function to read integers from the standard input
#######

vector<int> readInts() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    return A;
}

#######
# Main function
#######

int main() {
    int n;
    cin >> n;
    vector<int> A = readInts();
    sort(A.begin(), A.end());
    int ans = 0;
    for (int i = A.size() - 2; i >= A.size() - 2 * n - 1; i -= 2) {
        ans += A[i];
    }
    cout << ans << endl;
    return 0;
}

#######
# END-OF-CODE
#######
