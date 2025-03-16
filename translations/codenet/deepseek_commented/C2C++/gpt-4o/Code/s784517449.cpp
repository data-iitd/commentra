#include <iostream>
#include <vector>

using namespace std;

/* 
 * binarySearch function performs a binary search on the vector A to find a given key.
 * It returns true if the key is found, otherwise it returns false.
 */
bool binarySearch(const vector<int>& A, int n, int key) {
    int left = 0;
    int right = n;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (key == A[mid]) return true; /* keyを発見 */
        if (key > A[mid]) left = mid + 1; /* 後半を探索 */
        else right = mid; /* 前半を探索 */
    }
    return false;
}

/* 
 * main function is the entry point of the program.
 * It reads the size of the array and the elements of the array from the user.
 * It then reads the number of queries and performs binary search for each query.
 * Finally, it prints the number of elements found.
 */
int main() {
    int n, q, k, sum = 0;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> k;
        if (binarySearch(A, n, k))
            sum++;
    }
    cout << sum << endl;
    return 0;
}

// <END-OF-CODE>
