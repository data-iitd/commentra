#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::string s; // Step 1: The program starts by taking a string input from the user.
    std::cin >> s;

    int count = 0; // Step 2: It initializes a counter to keep track of the lengths of consecutive valid characters.
    std::vector<int> counter;

    if (s.empty()) { // Step 3: It checks if the input string is empty and returns immediately if it is.
        return 0;
    }
    counter.push_back(0); // Step 4: It splits the input string into individual characters.

    for (char c : s) { // Step 5: It iterates through each character in the string, incrementing the count for valid characters and resetting the count for invalid characters.
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
            count++;
        } else {
            counter.push_back(count);
            count = 0;
        }
    }

    counter.push_back(count); // Step 6: It appends the final count to the counter array and sorts the array.
    std::sort(counter.begin(), counter.end());
    std::cout << counter.back() << std::endl; // Step 7: Finally, it prints the maximum value in the sorted counter array.

    return 0;
}

// <END-OF-CODE>
