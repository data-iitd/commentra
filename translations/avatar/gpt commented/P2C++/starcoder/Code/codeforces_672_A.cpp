#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Initialize an empty list to store the results
    vector<int> li;
    // Initialize an index variable
    int ind = 0;

    // Loop through numbers from 1 to 370
    for (int i = 1; i <= 370; i++) {
        // Initialize a temporary list to hold digits
        vector<int> temp;
        // Assign the current number to p and q for processing
        int p = i, q = i;
        // Initialize a count variable to track the number of digits
        int count = 0;

        // Count the number of digits in the current number i
        while (p!= 0) {
            p /= 10;  // Remove the last digit
            count++;  // Increment the digit count
        }

        // If the number has 1 digit, add it directly to the list
        if (count == 1) {
            li.push_back(i);
        }

        // If the number has 2 digits
        if (count == 2) {
            temp.clear();  // Reset the temporary list
            // Extract digits of the number q
            while (q!= 0) {
                int x = q % 10;  // Get the last digit
                q /= 10;  // Remove the last digit
                temp.push_back(x);  // Append the digit to the temporary list
            }
            // Add the digits in reverse order to the main list
            li.insert(li.end(), temp.rbegin(), temp.rend());
        }

        // If the number has 3 digits
        if (count == 3) {
            temp.clear();  // Reset the temporary list
            // Extract digits of the number q
            while (q!= 0) {
                int x = q % 10;  // Get the last digit
                q /= 10;  // Remove the last digit
                temp.push_back(x);  // Append the digit to the temporary list
            }
            // Add the digits in reverse order to the main list
            li.insert(li.end(), temp.rbegin(), temp.rend());
        }
    }

    // Remove the last two elements from the list (not specified why)
    li.pop_back();
    li.pop_back();

    // Take user input for the index
    int n;
    cin >> n;
    // Print the n-th element from the list (1-based index)
    cout << li[n - 1] << endl;

    return 0;
}

