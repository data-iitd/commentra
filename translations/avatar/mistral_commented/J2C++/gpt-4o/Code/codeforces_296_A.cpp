#include <iostream> // Including required header for input and output
#include <vector>   // Including vector for dynamic array
#include <algorithm> // Including algorithm for max function
#include <sstream>  // Including sstream for string stream
using namespace std;

class InputReader {
    istream &input; // Reference to input stream
public:
    InputReader(istream &stream) : input(stream) {} // Constructor to initialize input stream

    int nextInt() {
        int x;
        input >> x; // Reading an integer from input
        return x;
    }
};

class Task {
public:
    void solve(InputReader &in, ostream &out) { // Method to solve the problem
        int n = in.nextInt(); // Reading the number of elements in the array
        vector<int> array(1001, 0); // Creating a vector of size 1001 to store the frequency of each element

        for (int i = 0; i < n; i++) { // Loop to read and store the elements in the array
            int index = in.nextInt();
            array[index]++; // Incrementing the frequency of the element at the given index
        }

        int countMax = -1; // Initializing the maximum frequency to -1
        for (int i = 1; i < array.size(); i++) { // Loop to find the maximum frequency
            countMax = max(countMax, array[i]);
        }

        if (n % 2 == 0) { // Checking if the number of elements is even
            if (countMax <= n / 2) { // If the maximum frequency is less than or equal to half of the number of elements
                out << "YES" << endl; // Printing "YES" as the output
            } else {
                out << "NO" << endl; // Else printing "NO" as the output
            }
        } else { // If the number of elements is odd
            if (countMax <= n / 2 + 1) { // If the maximum frequency is less than or equal to half of the number of elements plus one
                out << "YES" << endl; // Printing "YES" as the output
            } else {
                out << "NO" << endl; // Else printing "NO" as the output
            }
        }
    }
};

int main() {
    InputReader in(cin); // Creating InputReader object for reading input
    Task solver; // Creating Task object to solve the problem
    solver.solve(in, cout); // Calling the solve method of Task object to solve the problem
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
