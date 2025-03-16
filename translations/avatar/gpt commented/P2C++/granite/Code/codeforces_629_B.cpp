
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N = 368;
    vector<int> m(N, 0);  // Initialize 'M' list with N elements
    vector<int> f(N, 0);  // Initialize 'F' list with N elements

    int q;
    cin >> q;  // Read the number of operations from input

    for (int i = 0; i < q; i++) {
        char x;
        int a, b;
        cin >> x >> a >> b;  // Read the operation type and the indices a and b

        if (x == 'M') {
            m[a] += 2;  // Increment the value at index a in the 'M' list
            m[b] -= 2;  // Decrement the value at index b in the 'M' list
        } else {
            f[a] += 2;  // Increment the value at index a in the 'F' list
            f[b] -= 2;  // Decrement the value at index b in the 'F' list
        }
    }

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < N; i++) {
        a += m[i];  // Update cumulative sum for 'M'
        b += f[i];  // Update cumulative sum for 'F'

        if (min(a, b) > c) {
            c = min(a, b);  // Set c to the new minimum value
        }
    }

    cout << c << endl;  // Print the final minimum value found

    return 0;
}
