#include <iostream>
#include <vector>
using namespace std;

int main() {
    int i, n, ans; // Declare variables for iteration, size of vector, and answer count
    cin >> n; // Input the size of the vector
    vector<int> p(n); // Initialize a vector of size n

    // Input the elements of the vector
    for (i = 0; i < n; i++) {
        cin >> p[i]; // Read each element into the vector
    }

    ans = 0; // Initialize the answer counter to zero

    # Python code starts here
    for i in range(n - 1):
        if p[i] == i + 1:
            p[i + 1] = p[i]
            ans += 1
    # Python code ends here

    # Check if the last element matches its expected position
    if p[n - 1] == n:
        ans += 1

    print(ans)
}

