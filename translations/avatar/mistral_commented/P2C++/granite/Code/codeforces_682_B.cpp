
#include <bits/stdc++.h>
using namespace std;

// Function to read a list of integers from standard input
vector<int> I(int n) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    return v;
}

// Function to read an integer from standard input
int IS() {
    int x;
    cin >> x;
    return x;
}

// Function to read an integer from standard input and convert it to an integer
int IN() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a float from standard input
float IF() {
    float x;
    scanf("%f", &x);
    return x;
}

int main() {
    // Read the number of test cases 'n'
    int n = IN();

    // Read the list 'l' of length 'n' containing 'n' integers
    vector<int> l = I(n);

    // Initialize variable 'f' to 1
    int f = 1;

    // Sort the list 'l' in ascending order
    sort(l.begin(), l.end());

    // Initialize variable 'c' to 0
    int c = 0;

    // Iterate through the list 'l'
    for (int i = 0; i < n; i++) {
        // If the current element 'i' is greater than the previous count 'c', increment 'c' by 1
        if (l[i] > c) {
            c += 1;
        }
    }

    // Print the final result, which is the number of unique elements in the list 'l' plus 1
    cout << c + 1 << endl;

    return 0;
}

