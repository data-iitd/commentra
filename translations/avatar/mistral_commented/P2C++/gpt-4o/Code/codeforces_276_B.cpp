#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int main() {
    // Initialize an empty vector 's' to store input elements
    std::string input;
    std::cin >> input;
    std::vector<char> s(input.begin(), input.end());

    // Initialize an empty unordered_map 'dt' to store the count of each unique element
    std::unordered_map<char, int> dt;

    // Set a boolean variable 'x' to true to indicate whether there is an odd count element in the list
    bool x = true;

    // Iterate through each element 'i' in the vector 's'
    for (char i : s) {
        // Increment the count of the element 'i' in the map 'dt'
        dt[i]++;
    }

    // Initialize a counter 'cnt' to 0
    int cnt = 0;

    // Iterate through each key-value pair ('key', 'value') in the unordered_map 'dt'
    for (const auto& pair : dt) {
        char key = pair.first;
        int value = pair.second;

        // If the value is odd and 'cnt' is less than 1, increment 'cnt' by 1
        if (value % 2 != 0 && cnt < 1) {
            cnt++;
        }
        // If the value is odd and 'cnt' is already greater than or equal to 1, set 'x' to false and break the loop
        else if (value % 2 != 0 && cnt >= 1) {
            x = false;
            break;
        }
    }

    // After the loop, check the value of 'x'
    if (x) {
        // If it is true, print "First"
        std::cout << "First" << std::endl;
    } else if (!x && s.size() % 2 == 0) {
        // If it is false and the length of the vector 's' is even, print "Second"
        std::cout << "Second" << std::endl;
    } else if (!x && s.size() % 2 != 0) {
        // If it is false and the length of the vector 's' is odd, print "First"
        std::cout << "First" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
