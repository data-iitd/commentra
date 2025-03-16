#include <iostream>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

class FastReader {
public:
    FastReader() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }

    int nextInt() {
        int x;
        cin >> x;
        return x;
    }
};

int main() {
    FastReader in;  // Initializing FastReader for reading input

    int n = in.nextInt();  // Reading the number of elements in the array

    set<int> left;  // Creating a set to store the indices of elements in the sorted order
    vector<int> answer(n, -1);  // Creating a vector to store the answer for each index

    // Adding all the indices to the set
    for (int i = 0; i < n; i++) {
        left.insert(i);
    }

    int q = in.nextInt();  // Reading the number of queries

    // Processing each query
    while (q-- > 0) {
        int l = in.nextInt() - 1;  // Reading the left index of the query range
        int r = in.nextInt() - 1;  // Reading the right index of the query range
        int win = in.nextInt();  // Reading the winning index

        // Updating the answer for the winning index and all the indices between the left and right indices
        auto it = left.lower_bound(l);
        while (it != left.end() && *it <= r) {
            int curr = *it;
            answer[curr] = win;
            it = left.erase(it);  // Remove current index and get the next iterator
        }

        // Updating the answer for the winning index in the answer array
        answer[win - 1] = 0;

        // Adding the winning index back to the set
        left.insert(win - 1);
    }

    // Printing the answer for each index in the answer array
    for (int i = 0; i < n; i++) {
        cout << answer[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;  // Printing the answer as a single line

    return 0;
}

// <END-OF-CODE>
