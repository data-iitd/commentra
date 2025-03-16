// Include necessary headers
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

// Function to read long lines from standard input
std::vector<std::string> ReadLongLines(int times) {
    std::vector<std::string> result(times);
    std::string line;

    for (int i = 0; i < times; i++) {
        std::ostringstream buffer;
        while (std::getline(std::cin, line)) {
            buffer << line;
            if (line.back() == '\n') {
                break;
            }
        }
        result[i] = buffer.str();
    }
    return result;
}

// Function to print a list of integers
void PrintList(const std::vector<int>& list) {
    for (size_t i = 0; i < list.size(); i++) {
        if (i == 0) {
            std::cout << list[i];
        } else {
            std::cout << " " << list[i];
        }
    }
    std::cout << std::endl;
}

// Main function
int main() {
    // Initialize a set to store unique integers
    std::set<int> uniqueIntegers;

    // Read long lines from the standard input
    auto lines = ReadLongLines(4);

    // Split the second line into integers and add them to the set
    std::istringstream iss(lines[1]);
    int n;
    while (iss >> n) {
        uniqueIntegers.insert(n);
    }

    // Read integers from the fourth line and add them to the set if they are not already present
    iss.clear();
    iss.str(lines[3]);
    while (iss >> n) {
        uniqueIntegers.insert(n);
    }

    // Convert the set to a vector and sort it
    std::vector<int> result(uniqueIntegers.begin(), uniqueIntegers.end());
    std::sort(result.begin(), result.end());

    // Print the sorted result
    PrintList(result);

    return 0;
}

// <END-OF-CODE>
