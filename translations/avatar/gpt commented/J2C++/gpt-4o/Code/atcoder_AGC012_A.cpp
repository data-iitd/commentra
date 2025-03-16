#include <iostream> // For input and output
#include <vector> // For using vectors
#include <algorithm> // For using sort function

using namespace std;

int main() {
    // Creating a variable to read input
    int n;
    
    // Reading the integer n which determines the size of the array
    cin >> n;
    
    // Initializing a vector of size 3*n to hold the input values
    vector<int> array(3 * n);
    
    // Filling the vector with user input values
    for (int i = 0; i < array.size(); i++) {
        cin >> array[i];
    }
    
    // Sorting the vector in ascending order
    sort(array.begin(), array.end());
    
    // Setting the head pointer to the second last element of the sorted vector
    int head = array.size() - 2;
    
    // Initializing a variable to accumulate the result
    long long res = 0;
    
    // Looping n times to sum up the required elements from the sorted vector
    for (int i = 0; i < n; i++) {
        res += array[head]; // Adding the current element pointed by head to the result
        head -= 2; // Moving the head pointer two positions to the left for the next iteration
    }
    
    // Printing the final result
    cout << res << endl;

    return 0;
}

// <END-OF-CODE>
