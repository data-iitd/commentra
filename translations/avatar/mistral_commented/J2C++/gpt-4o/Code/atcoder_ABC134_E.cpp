#include <iostream>  // Including the iostream library for input and output
#include <map>      // Including the map library for using std::map
using namespace std; // Using the standard namespace

int main() {  // Main function to start the program
    int n;  // Variable to store the number of test cases
    cin >> n;  // Reading the number of test cases from the console

    map<int, int> freqMap;  // Creating an empty map to store the frequency of each number

    while (n-- > 0) {  // Loop through each test case
        int num;  // Variable to store the current number
        cin >> num;  // Reading the number from the console

        if (freqMap.lower_bound(num) == freqMap.end()) {  // If the number is not present in the map
            int val = freqMap[num];  // Get the initial value of the number from the map (default is 0)
            freqMap[num] = ++val;  // Increment the value of the number in the map
        } else {  // If the number is already present in the map
            auto it = freqMap.lower_bound(num);  // Get the iterator to the first element not less than num
            --it;  // Move the iterator to the previous element (the largest key less than num)
            int key = it->first;  // Get the key (previous number) from the map
            int val = it->second;  // Get the value (frequency) of the previous number from the map

            if (val == 1) {  // If the frequency of the previous number is 1
                freqMap.erase(it);  // Remove the previous number from the map
            } else {  // If the frequency of the previous number is greater than 1
                freqMap[key] = --val;  // Decrement the frequency of the previous number in the map
            }

            int val = freqMap[num];  // Get the initial value of the current number from the map (default is 0)
            freqMap[num] = ++val;  // Increment the value of the current number in the map
        }
    }

    int ans = 0;  // Initializing the answer variable to 0

    for (const auto& pair : freqMap) {  // Iterating through each key-value pair in the map
        ans += pair.second;  // Adding the frequency of the current number to the answer
    }

    cout << ans << endl;  // Printing the answer to the console
    return 0;  // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
