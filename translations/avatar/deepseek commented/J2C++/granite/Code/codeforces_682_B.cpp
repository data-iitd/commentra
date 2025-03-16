
#include <iostream> // Including necessary I/O streams
#include <vector> // Including necessary container classes
#include <algorithm> // Including necessary algorithmic functions

using namespace std;

int main() {
    int n; // Declaring and initializing the variable n
    cin >> n; // Reading the number of elements
    
    vector<int> list; // Creating a vector to store the elements
    
    // Reading the elements and adding them to the vector
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.push_back(x);
    }
    
    sort(list.begin(), list.end()); // Sorting the vector
    
    int c = 1; // Initializing the counter variable
    
    // Iterating through the sorted vector to find the smallest missing positive integer
    for (int i = 0; i < n; i++) {
        if (list[i] >= c) {
            c++;
        }
    }
    
    cout << c << endl; // Printing the result
    
    return 0; // Returning 0 to indicate successful execution
}


