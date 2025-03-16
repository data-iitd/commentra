#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays

using namespace std; // Using the standard namespace

int main() { // Starting the main function
    int N; // Variable to store the number of elements in the array H
    long long M; // Variable to store the number of queries

    cin >> N; // Reading the number of elements in the array H
    cin >> M; // Reading the number of queries

    vector<long long> H(N); // Creating a vector of size N to store the heights
    vector<bool> ans(N, true); // Creating a boolean vector of size N to store the answer for each index, initialized to true

    for (int i = 0; i < N; i++) { // Reading the elements of the array H
        cin >> H[i];
    }

    for (long long query = 0; query < M; query++) { // Processing each query
        int temp1, temp2; // Variables to store the indices for the query
        cin >> temp1 >> temp2; // Reading the first and second index

        if (H[temp1 - 1] < H[temp2 - 1]) { // If the height of the first index is less than the second index
            ans[temp1 - 1] = false; // The first index cannot be in the left half
        } else if (H[temp1 - 1] > H[temp2 - 1]) { // If the height of the first index is greater than the second index
            ans[temp2 - 1] = false; // The second index cannot be in the left half
        } else { // If the heights are equal
            ans[temp1 - 1] = false; // Both the first and second indices cannot be in the left half
            ans[temp2 - 1] = false;
        }
    }

    int ans2 = 0; // Initializing a counter to store the number of elements in the left half
    for (int i = 0; i < N; i++) { // Iterating through the array to find the number of elements in the left half
        if (ans[i]) { // If an element is still assumed to be in the left half
            ans2++; // Increment the counter
        }
    }

    cout << ans2 << endl; // Printing the final answer
    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
