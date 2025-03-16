#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays

using namespace std; // Using the standard namespace

int main() { // Main function to start the program
    int n; // Variable to hold the number of elements in the arrays
    while (cin >> n) { // Reading input until the end of the file is reached
        vector<int> a(n); // Creating a vector 'a' of size 'n'
        vector<int> b(n, 0); // Creating a vector 'b' of size 'n' and initializing all elements to zero
        int s = -1; // Initializing the variable 's' to -1
        for (int i = 0; i < n; i++) { // Loop to read and initialize the arrays 'a' and 'b'
            cin >> a[i]; // Reading an integer value and storing it in the 'i'th position of vector 'a'
        }
        int tem = 1; // Initializing the variable 'tem' to 1
        int q = 0; // Initializing the variable 'q' to 0
        while (q != n) { // Main loop to find the sequence length
            s++; // Incrementing the variable 's'
            if (tem == 1) { // If 'tem' is 1, perform the first half of the loop
                for (int i = 0; i < n; i++) {
                    if (a[i] <= q && b[i] == 0) { // Check if the current element in vector 'a' is less than or equal to 'q' and its corresponding element in vector 'b' is 0
                        b[i] = 1; // If so, set the corresponding element in vector 'b' to 1 and increment 'q'
                        q++; // Incrementing 'q' when an element is found
                    }
                }
                tem = 0; // Switching the value of 'tem' to 0
            } else { // If 'tem' is 0, perform the second half of the loop
                for (int i = n - 1; i >= 0; i--) {
                    if (a[i] <= q && b[i] == 0) { // Check if the current element in vector 'a' is less than or equal to 'q' and its corresponding element in vector 'b' is 0
                        b[i] = 1; // If so, set the corresponding element in vector 'b' to 1 and increment 'q'
                        q++; // Incrementing 'q' when an element is found
                    }
                }
                tem = 1; // Switching the value of 'tem' to 1
            }
        }
        cout << s << endl; // Printing the length of the sequence found
    }
    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
