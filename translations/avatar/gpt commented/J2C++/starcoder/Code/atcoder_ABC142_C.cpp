#include <bits/stdc++.h>
using namespace std;

// Declaring a static list to hold integers (not used in the current code)
static vector<int> P;

int main() {
    // Creating a Scanner object to read input from the console
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Scanner scanner;
    scanner.sync_with_stdio(false);
    scanner.tie(NULL);
    scanner.exceptions(cin.exceptions());

    // Reading the number of elements (N) from the input
    int N;
    cin >> N;

    // Creating a HashMap to store the mapping of integer values to their order of input
    map<int, int> idorder;

    // Looping through the range from 1 to N to read N integers
    for (int i = 1; i <= N; i++) {
        // Reading an integer A from the input
        int A;
        cin >> A;
        // Storing the integer A in the map with its order of input (i)
        idorder[A] = i;
    }

    // Looping through the range from 1 to N to print the order of each integer
    for (int i = 1; i <= N; i++) {
        // Retrieving and printing the order of the integer i from the map
        cout << idorder[i];
        // Printing a space after each output
        cout << " ";
    }
}

