
#include <iostream>  // Include the necessary libraries for input/output operations
#include <set>  // Include the set library for storing unique elements
#include <cmath>  // Include the math library for mathematical operations
#include <algorithm>  // Include the algorithm library for finding the greatest common divisor (GCD)

using namespace std;  // Use the standard namespace for convenience

int main() {
    int n, num;  // Declare and initialize two integers: n (an upper limit) and num (a number to be processed)
    cin >> n >> num;

    set<int> num_set;  // Declare a set to store unique numbers
    int temp;  // Declare a temporary variable for reading input
    while (cin >> temp) {  // Read a set of integers from input and insert them into the set
        num_set.insert(temp);
    }

    set<int> two_times_set;  // Declare an empty set to store values related to the two times condition
    for (auto i : num_set) {  // Iterate through each number in the set
        int count = 0;  // Initialize a counter for the number of times the number can be divided by 2
        while (i % 2 == 0) {  // Check if the number is divisible by 2
            i /= 2;  // Divide the number by 2
            count++;  // Increment the counter
        }
        two_times_set.insert(count);  // Add the count of divisions to the set
    }

    if (two_times_set.size()!= 1) {  // If more than one unique count of divisions by 2 is found, print 0 and exit
        cout << 0 << endl;
    } else {  // If the loop completes without breaking, proceed to calculate the least common multiple (LCM)
        vector<int> num_list(num_set.begin(), num_set.end());  // Convert the set to a vector for processing
        int lcm = num_list[0];  // Initialize LCM with the first element of the vector

        for (int i = 1; i < num_list.size(); i++) {  // Calculate the LCM of all numbers in the vector
            lcm = lcm * num_list[i] / __gcd(lcm, num_list[i]);  // Update LCM using the GCD
        }

        int result = (num - lcm / 2) / lcm + 1;  // Calculate the final result based on the LCM and the input number
        cout << result << endl;  // Print the result
    }

    return 0;  // Return 0 to indicate successful execution
}

