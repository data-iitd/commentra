

#include <iostream> // Importing the standard input/output stream
#include <vector> // Importing the vector container

using namespace std; // Using the standard namespace

int main() { // Starting the main method
    int N, M; // Declaring the variables N and M to store the number of elements and queries respectively
    cin >> N >> M; // Reading the values of N and M from the input

    vector<long long> H(N); // Creating a vector of size N to store the heights
    vector<bool> ans(N, true); // Creating a boolean vector of size N to store the answer for each index

    for (int i = 0; i < N; i++) { // Reading the elements of the vector H
        cin >> H[i];
    }

    for (int query = 0; query < M; query++) { // Processing each query
        int temp1, temp2; // Declaring the variables temp1 and temp2 to store the indices of the elements
        cin >> temp1 >> temp2; // Reading the values of temp1 and temp2 from the input

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
    for (int i = 0; i < N; i++) { // Iterating through the vector to find the number of elements in the left half
        if (ans[i]) { // If an element is still assumed to be in the left half
            ans2++; // Increment the counter
        }
    }

    cout << ans2 << endl; // Printing the final answer

    return 0; // Returning 0 to indicate successful execution
}

