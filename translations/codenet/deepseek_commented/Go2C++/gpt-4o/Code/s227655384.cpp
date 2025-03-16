#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <algorithm>

void ReadLongLines(int times, std::vector<std::string>& lines) {
    std::string line;
    for (int i = 0; i < times; ++i) {
        std::getline(std::cin, line);
        lines.push_back(line);
    }
}

void PrintList(const std::vector<int>& list) {
    for (size_t i = 0; i < list.size(); ++i) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << list[i];
    }
    std::cout << std::endl;
}

int main() {
    // Create a set to store unique elements.
    std::unordered_set<int> uniqueElements;
    std::vector<std::string> lines;

    // Read 4 lines from input.
    ReadLongLines(4, lines);

    // Split the second line into individual elements and add them to the set.
    std::istringstream iss(lines[1]);
    int n;
    while (iss >> n) {
        uniqueElements.insert(n);
    }

    // Process the fourth line to toggle the presence of elements in the set.
    std::istringstream iss2(lines[3]);
    while (iss2 >> n) {
        if (uniqueElements.find(n) != uniqueElements.end()) {
            uniqueElements.erase(n);
        } else {
            uniqueElements.insert(n);
        }
    }

    // Extract the unique elements from the set and sort them.
    std::vector<int> result(uniqueElements.begin(), uniqueElements.end());
    std::sort(result.begin(), result.end());

    // Print the sorted list of unique elements.
    PrintList(result);

    return 0;
}

// <END-OF-CODE>
