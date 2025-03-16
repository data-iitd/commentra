
#include <iostream>
#include <string>
#include <map>

int main() {
    // Initialize an empty string's' to store input elements
    std::string s;
    std::cin >> s;

    // Initialize an empty map 'dt' to store the count of each unique element
    std::map<char, int> dt;

    // Set a boolean variable 'x' to true to indicate whether there is an odd count element in the string
    bool x = true;

    // Iterate through each character 'i' in the string's'
    for (char i : s) {
        // Check if the character 'i' already exists as a key in the map 'dt'
        if (dt.find(i)!= dt.end()) {
            // If it does, increment its value by 1
            dt[i]++;
        } else {
            // If not, add it as a new key with a value of 1
            dt[i] = 1;
        }
    }

    // Initialize a counter 'cnt' to 0 and set 'x' to true
    int cnt = 0;
    x = true;

    // Iterate through each key-value pair ('key', 'value') in the map 'dt'
    for (auto const& [key, value] : dt) {
        // If the value is odd and 'cnt' is less than 1, increment 'cnt' by 1
        if (value % 2!= 0 && cnt < 1) {
            cnt++;
        }
        // If the value is odd and 'cnt' is already greater than or equal to 1, set 'x' to false and break the loop
        else if (value % 2!= 0 && cnt >= 1) {
            x = false;
            break;
        }
    }

    // After the loop, check the value of 'x'
    if (x) {
        // If it is true, print "First"
        std::cout << "First" << std::endl;
    } else if (!x && s.length() % 2 == 0) {
        // If it is false and the length of the string's' is even, print "Second"
        std::cout << "Second" << std::endl;
    } else if (!x && s.length() % 2!= 0) {
        // If it is false and the length of the string's' is odd, print "First"
        std::cout << "First" << std::endl;
    }

    return 0;
}
