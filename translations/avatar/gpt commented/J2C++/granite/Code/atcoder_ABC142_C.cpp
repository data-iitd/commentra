
#include <iostream> // Including necessary libraries
#include <map>
#include <vector>

using namespace std;

int main() {
    // Declaring a static list to hold integers (not used in the current code)
    vector<int> P;

    // Creating a Scanner object to read input from the console
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    // Reading the number of elements (N) from the input
    int N;
    cin >> N;

    // Creating a map to store the mapping of integer values to their order of input
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
        cout << idorder[i] << " ";
    }
    // Ending the program
    return 0;
}
