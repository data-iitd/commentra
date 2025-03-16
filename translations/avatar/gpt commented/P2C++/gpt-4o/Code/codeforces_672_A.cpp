#include <iostream>
#include <vector>

int main() {
    // Initialize an empty vector to store the results
    std::vector<int> li;
    
    // Loop through numbers from 1 to 370
    for (int i = 1; i <= 370; ++i) {
        // Initialize a temporary vector to hold digits
        std::vector<int> temp;
        // Assign the current number to p and q for processing
        int p = i, q = i;
        // Initialize a count variable to track the number of digits
        int count = 0;
        
        // Count the number of digits in the current number i
        while (p != 0) {
            p /= 10;  // Remove the last digit
            count++;  // Increment the digit count
        }

        // If the number has 1 digit, add it directly to the vector
        if (count == 1) {
            li.push_back(i);
        }
        
        // If the number has 2 digits
        if (count == 2) {
            temp.clear();  // Reset the temporary vector
            // Extract digits of the number q
            while (q != 0) {
                int x = q % 10;  // Get the last digit
                q /= 10;  // Remove the last digit
                temp.push_back(x);  // Append the digit to the temporary vector
            }
            // Add the digits in reverse order to the main vector
            li.insert(li.end(), temp.rbegin(), temp.rend());
        }
        
        // If the number has 3 digits
        if (count == 3) {
            temp.clear();  // Reset the temporary vector
            // Extract digits of the number q
            while (q != 0) {
                int x = q % 10;  // Get the last digit
                q /= 10;  // Remove the last digit
                temp.push_back(x);  // Append the digit to the temporary vector
            }
            // Add the digits in reverse order to the main vector
            li.insert(li.end(), temp.rbegin(), temp.rend());
        }
    }

    // Remove the last two elements from the vector
    li.pop_back();
    li.pop_back();

    // Take user input for the index
    int n;
    std::cin >> n;
    // Print the n-th element from the vector (1-based index)
    std::cout << li[n - 1] << std::endl;

    return 0;
}

// <END-OF-CODE>
