
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::string s; // Step 1: The program starts by taking a string input from the user.
    std::cin >> s;

    int count = 0; // Step 2: It initializes a counter to keep track of the lengths of consecutive valid characters.
    std::vector<int> counter;

    if (s == "") { // Step 3: It checks if the input string is empty and returns immediately if it is.
        return 0;
    }
    counter.push_back(0); // Step 4: It splits the input string into individual characters.
    std::vector<std::string> li;
    std::string temp = "";
    for (char c : s) {
        temp += c;
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
            count++;
        } else {
            li.push_back(temp);
            temp = "";
            counter.push_back(count);
            count = 0;
        }
    }
    li.push_back(temp);
    counter.push_back(count); // Step 5: It iterates through each character in the split string, incrementing the count for valid characters and resetting the count for invalid characters.

    std::sort(counter.begin(), counter.end()); // Step 6: It appends the final count to the counter array and sorts the array.
    std::cout << counter[counter.size() - 1] << std::endl; // Step 7: Finally, it prints the maximum value in the sorted counter array.

    return 0;
}
