#include <bits/stdc++.h>
using namespace std;

// Function to read integers from input
vector<int> readInts() {
    string line;
    getline(cin, line);
    vector<int> ret;
    istringstream iss(line);
    for (int i; iss >> i;) {
        ret.push_back(i);
        if (iss.peek() == ',')
            iss.ignore();
    }
    return ret;
}

// Main function
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

