#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for using vectors
using namespace std; // Using the standard namespace

class Main { // Defining the Main class
public:
    void run() { // Method to run the program
        int N, M; // Declaring variables for the number of elements and queries
        cin >> N >> M; // Reading the first two integers from the input

        vector<int> a(N, 0); // Creating a vector of size N initialized with zeros

        // Reading the queries and updating the vector accordingly
        for (int i = 0; i < M; i++) {
            int k; // Number of elements to be updated
            cin >> k; // Reading the number of elements to be updated

            for (int j = 0; j < k; j++) { // Iterating through the elements to be updated
                int s; // Index of the element to be updated
                cin >> s; // Reading the index
                s--; // Decreasing the index by 1 as the vector index starts from 0

                // Updating the value of the element at the given index
                a[s] |= (1 << i);
            }
        }

        int p = 0; // Initializing a variable to store the XOR of all given integers

        // Reading the integers and computing their XOR
        for (int i = 0; i < M; i++) {
            int x; // Integer to read
            cin >> x; // Reading an integer from the input
            p |= (x << i); // Computing the XOR of the current integer with the previous result
        }

        int ans = 0; // Initializing a variable to store the count of valid answers

        // Iterating through all possible combinations of the vector elements
        for (int s = 0; s < (1 << N); s++) { // 1 << N represents 2^N
            int t = 0; // Initializing a variable to store the XOR of the current combination with the vector elements

            // Computing the XOR of the current combination with the vector elements
            for (int i = 0; i < N; i++) {
                if ((s >> i) & 1) { // Checking if the i-th bit of the current combination is set
                    t ^= a[i]; // Updating the XOR of the current combination
                }
            }

            // Checking if the XOR of the current combination and the vector elements is equal to the given integers
            if (p == t) {
                ans++; // Incrementing the count of valid answers
            }
        }

        cout << ans << endl; // Printing the count of valid answers
    }
};

int main() { // Main function to start the program
    Main main; // Creating an instance of the Main class
    main.run(); // Calling the run method to execute the program
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
