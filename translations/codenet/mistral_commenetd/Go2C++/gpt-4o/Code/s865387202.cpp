// Include necessary headers
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <sstream>

// Define a custom city struct with three fields: prefecture, position, and year.
struct City {
    int prefecture;
    int position;
    int year;
};

// Define a custom cities type as a vector of pointers to City structs.
using Cities = std::vector<City*>;

// Define a custom cMap type as a map with an integer key and a Cities vector as the value.
using CMap = std::map<int, Cities>;

// Main function is the entry point of the program.
int main() {
    // Read the number of cities and events from the standard input.
    int n, m;
    std::cin >> n >> m;

    // Initialize an empty cMap named h.
    CMap h;

    // Read m pairs of integers x and y from the standard input.
    for (int i = 0; i < m; i++) {
        // Read an integer x from the standard input.
        int x;
        std::cin >> x;

        // Read an integer y from the standard input.
        int y;
        std::cin >> y;

        // Check if the prefecture x already exists in the cMap.
        if (h.find(x) == h.end()) {
            // If the prefecture x does not exist in the cMap, create a new Cities vector with one element and assign it to the key x in the cMap.
            h[x] = Cities{new City{x, i, y}};
        } else {
            // If the prefecture x already exists in the cMap, append a new City struct to the existing Cities vector.
            h[x].push_back(new City{x, i, y});
        }
    }

    // Initialize a vector named results with length m and empty strings.
    std::vector<std::string> results(m);

    // Iterate through each value v in the cMap.
    for (auto& pair : h) {
        Cities& v = pair.second;

        // Sort the cities vector v using a lambda function.
        std::sort(v.begin(), v.end(), [](City* a, City* b) {
            return a->year < b->year;
        });

        // Iterate through each City struct ci in the sorted cities vector v.
        for (size_t idx = 0; idx < v.size(); idx++) {
            City* ci = v[idx];
            // Format the result string using stringstream and assign it to the corresponding index in the results vector.
            std::ostringstream oss;
            oss << std::setw(6) << std::setfill('0') << ci->prefecture
                << std::setw(6) << std::setfill('0') << (idx + 1);
            results[ci->position] = oss.str();
        }
    }

    // Print the final result using a loop.
    for (const auto& result : results) {
        std::cout << result << std::endl;
    }

    // Clean up dynamically allocated memory
    for (auto& pair : h) {
        for (City* city : pair.second) {
            delete city;
        }
    }

    return 0;
}

// <END-OF-CODE>
