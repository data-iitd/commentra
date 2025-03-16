#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct to represent an arm with left and right endpoints.
struct Arm {
    int l, r;
};

// Function to read an integer from standard input.
int scanInt() {
    int x;
    cin >> x;
    return x;
}

int main() {
    // Reads the number of arms.
    int n = scanInt();
    
    // Creates a vector to store the arms.
    vector<Arm> arms(n);
    
    // Reads each arm's range and stores the left and right endpoints.
    for (int i = 0; i < n; i++) {
        int x = scanInt();
        int l = scanInt();
        arms[i].l = x - l;
        arms[i].r = x + l;
    }
    
    // Sorts the arms based on their right endpoints.
    sort(arms.begin(), arms.end(), [](const Arm &a, const Arm &b) {
        return a.r < b.r;
    });
    
    // Initializes the answer and the right endpoint reference.
    int ans = 1;
    int r = arms[0].r;
    
    // Iterates through the sorted arms to count non-overlapping arms.
    for (int i = 1; i < n; i++) {
        if (arms[i].l >= r) {
            ans++;
            r = arms[i].r;
        }
    }
    
    // Prints the count of non-overlapping arms.
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
