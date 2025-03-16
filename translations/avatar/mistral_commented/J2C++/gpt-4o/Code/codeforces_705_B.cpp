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

FastReader scan;  // Creating an instance of FastReader
int prevWinner = 0;  // Initializing the 'prevWinner' variable to 0

void solve() {
    int t = scan.nextInt();  // Reading the number of test cases
    vector<int> arr(t);  // Creating a vector of size 't' to store the input

    for (int i = 0; i < t; i++) {  // Iterating through the vector
        arr[i] = scan.nextInt();  // Reading each element

        if (arr[i] == 1) {  // Checking if the current element is 1
            if (prevWinner == 0) {  // If the previous winner was 0
                prevWinner = 2;  // Update the 'prevWinner' variable to 2
            }

            if ((i - 1) % 2 == 0) {  // Checking the parity of the current element's index
                cout << (prevWinner == 0 ? 2 : 1) << endl;  // Printing the output based on the 'prevWinner' value
                prevWinner = (prevWinner == 0 ? 2 : 1);  // Updating the 'prevWinner' variable for the next iteration
            }
        }
    }
}

int main() {
    int t = 1;  // Initializing the test case counter

    while (t-- > 0) {  // Running the solution process for all test cases
        solve();
    }

    return 0;
}

// <END-OF-CODE>
