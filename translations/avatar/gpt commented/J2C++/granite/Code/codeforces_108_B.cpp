
#include <iostream> // Including theiostream library for input/output
#include <algorithm> // Including the algorithm library for sorting
using namespace std;

int main() {
    // Creating a Scanner object to read input from the console
    // (Scanner is not available in C++, so we use cin instead)
    int n;
    cin >> n; // Reading the number of elements in the array
    
    // Initializing an array of size n
    int a[n];
    
    // Loop to read n integers from the user and store them in the array
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sorting the array in ascending order
    sort(a, a + n); // Using the sort function from the algorithm library
    
    // Loop to check the condition for adjacent elements in the sorted array
    for (int i = 0; i < n - 1; i++) {
        // Checking if the next element is less than double the current element
        // and ensuring they are not equal
        if (a[i + 1] < a[i] * 2 && a[i]!= a[i + 1]) {
            // If the condition is met, print "YES" and exit the program
            cout << "YES" << endl;
            return 0;
        }
    }
    
    // If no such pair is found, print "NO"
    cout << "NO" << endl;
    
    // End of code
    return 0;
}
