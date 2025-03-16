#include <iostream>
#include <vector>
using namespace std;

bool search(const vector<int>& A, int n, int key) {
    int i = 0;
    vector<int> temp = A; // Create a copy of A
    temp.push_back(key); // Add key to the end of the copy
    while (temp[i] != key) i++;
    return i != n;
}

int main() {
    int n, q, key, sum = 0;

    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> key;
        if (search(A, n, key)) sum++;
    }
    cout << sum << endl;

    return 0;
}

// <END-OF-CODE>
