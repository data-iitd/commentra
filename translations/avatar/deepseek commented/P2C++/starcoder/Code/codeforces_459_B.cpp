#include <bits/stdc++.h>
using namespace std;

int main() {
    // Step 1: Take an integer input `n` which represents the number of elements in the list `l1`.
    int n;
    cin >> n;

    // Step 2: Take a space-separated string of integers, convert them into a list of integers, and store it in `l1`.
    vector<int> l1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l1.push_back(x);
    }

    // Step 3: Sort the list `l1` in ascending order.
    sort(l1.begin(), l1.end());

    // Step 4: Assign the last element of the sorted list `l1` to `a`, which is the maximum value in the list.
    int a = l1.back();

    // Step 5: Assign the first element of the sorted list `l1` to `b`, which is the minimum value in the list.
    int b = l1.front();

    // Step 6: Check if `a` is equal to `b`.
    if (a == b) {
        // Step 7: If `a` is equal to `b`, print the difference `a - b` and the number of ways to choose 2 elements from `n` elements.
        cout << a - b << " " << n * (n - 1) / 2 << endl;
    } else {
        // Step 8: If `a` is not equal to `b`, calculate the count of occurrences of `a` and `b` in the list `l1`.
        int ac = count(l1.begin(), l1.end(), a);
        int bc = count(l1.begin(), l1.end(), b);
        // Step 9: Print the difference `a - b` and the product of the counts of `a` and `b`.
        cout << a - b << " " << ac * bc << endl;
    }

    return 0;
}

