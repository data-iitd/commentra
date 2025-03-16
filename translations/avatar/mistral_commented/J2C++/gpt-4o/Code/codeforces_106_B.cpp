#include <iostream> // Including iostream for input and output
#include <vector> // Including vector for dynamic array
using namespace std;

int main() {
    int n; // Variable to store the number of items
    cin >> n; // Reading the number of items from the input

    vector<vector<int>> vec(n, vector<int>(4)); // Creating a 2D vector of size n x 4 to store the items

    // Initializing the 2D vector with input values
    for (int i = 0; i < n; i++) {
        cin >> vec[i][0]; // Reading the first element of the current item
        cin >> vec[i][1]; // Reading the second element of the current item
        cin >> vec[i][2]; // Reading the third element of the current item
        cin >> vec[i][3]; // Reading the fourth element of the current item
    }

    int ans = 500; // Initializing answer variables with default values
    int ansprice = 20000;

    // Finding the answer by comparing all items and keeping track of the minimum price item found so far
    for (int i = 0; i < n; i++) {
        int flag = 1; // Initializing a flag variable to check if the current item is smaller than all other items

        for (int j = 0; j < n; j++) {
            if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2]) {
                flag = 0; // If the current item is smaller than the other item, set the flag to 0
                break; // Exit the inner loop as we don't need to check further if the current item is smaller
            }
        }

        if (flag == 1) { // If the current item is not smaller than any other item, check if its price is lower than the current answer
            if (vec[i][3] < ansprice) {
                ansprice = vec[i][3]; // Update the answer price if the current item's price is lower
                ans = i + 1; // Update the answer index
            }
        }
    }

    // Printing the answer
    cout << ans << endl;
    return 0; // Return statement to indicate successful execution
}

// <END-OF-CODE>
