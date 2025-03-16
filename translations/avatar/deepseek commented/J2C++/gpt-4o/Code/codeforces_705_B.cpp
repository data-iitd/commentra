#include <iostream>
#include <vector>
using namespace std;

class FastReader {
    public:
        FastReader() {}

        string next() {
            string s;
            cin >> s;
            return s;
        }

        int nextInt() {
            int x;
            cin >> x;
            return x;
        }

        long long nextLong() {
            long long x;
            cin >> x;
            return x;
        }

        double nextDouble() {
            double x;
            cin >> x;
            return x;
        }

        string nextLine() {
            string s;
            cin.ignore();
            getline(cin, s);
            return s;
        }
};

void solve() {
    FastReader scan;
    int t = scan.nextInt(); // Read the number of test cases
    vector<int> arr(t); // Initialize a vector to store the elements
    for (int i = 0; i < t; i++) {
        arr[i] = scan.nextInt(); // Read the elements of the array
    }
    int prevWinner = 0; // Initialize the previous winner variable
    for (int i = 0; i < t; i++) {
        if (arr[i] == 1) { // Check if the current element is 1
            if (prevWinner == 0) { // If no previous winner, set the winner to 2
                prevWinner = 2;
            }
        }
        if (prevWinner == 2 || prevWinner == 0) { // Check if the previous winner is 2 or unset
            if ((arr[i] - 1) % 2 == 0) { // Check if the condition for player 2 is met
                cout << 2 << endl; // Print the winner
                prevWinner = 2; // Update the previous winner
            } else {
                cout << 1 << endl; // Print the winner
                prevWinner = 1; // Update the previous winner
            }
        } else { // If the previous winner is 1
            if ((arr[i] - 1) % 2 == 0) { // Check if the condition for player 1 is met
                cout << 1 << endl; // Print the winner
                prevWinner = 1; // Update the previous winner
            } else {
                cout << 2 << endl; // Print the winner
                prevWinner = 2; // Update the previous winner
            }
        }
    }
}

int main() {
    int t = 1; // Number of test cases
    while (t-- > 0) {
        solve();
    }
    return 0;
}

// <END-OF-CODE>
