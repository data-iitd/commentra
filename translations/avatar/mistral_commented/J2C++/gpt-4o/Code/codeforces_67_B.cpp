#include <iostream>  // Including the iostream library for input and output
#include <vector>   // Including the vector library for using dynamic arrays
using namespace std;

class Main {
public:
    Main() {  // Constructor for the Main class
        // No specific initialization needed here
    }

    void main() {
        int n;  // Variable to store the number of elements in the array 'bb'
        int k;  // Variable to store the value of 'k'
        cin >> n >> k;  // Reading the number of elements and the value of 'k' from standard input

        vector<int> bb(n);  // Creating a vector 'bb' of size 'n'
        for (int i = 0; i < n; i++) {
            cin >> bb[i];  // Reading each element of the array 'bb' from standard input
        }

        vector<int> aa(n);  // Creating a vector 'aa' of size 'n'
        int m = 0;  // Initializing an integer variable 'm' to keep track of the index of the last element added to 'aa'

        for (int a = n - 1; a >= 0; a--) {  // Iterating through the array 'bb' from the last index to the first index
            int j = 0;
            while (bb[a] > 0) {  // While there are still elements in 'bb' at index 'a' to be processed
                if (aa[j] >= a + k) {  // Checking if the current element in 'aa' is greater than or equal to the index 'a' plus 'k'
                    bb[a]--;  // If true, decrement the number of elements in 'bb' at index 'a'
                }
                j++;  // Incrementing j to check the next element in 'aa'
            }

            for (int j_ = m++; j_ > j; j_--) {  // Iterating through the array 'aa' from the last index added to the current index 'j'
                aa[j_] = aa[j_ - 1];  // Swapping the elements at indices 'j_' and 'j_ - 1'
            }

            aa[j] = a;  // Adding the current index 'a' to the array 'aa' at index 'j'
        }

        for (int i = 0; i < n; i++) {  // Iterating through the array 'aa' and printing each element to the console
            cout << aa[i] + 1 << " ";  // Outputting the index (1-based)
        }

        cout << endl;  // Printing a newline character to the console
    }
};

int main() {
    Main o;  // Creating an instance of the Main class
    o.main();  // Calling the main method of the Main class
    return 0;  // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
