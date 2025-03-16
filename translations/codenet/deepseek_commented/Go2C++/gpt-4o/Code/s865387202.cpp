#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <sstream>

struct City {
    int prefecture; // Represents the prefecture number of the city
    int position;   // Represents the position of the city in its prefecture
    int year;       // Represents the year the city was established
};

using Cities = std::vector<City>; // A vector of City structs
using CMap = std::map<int, Cities>; // A map from prefecture numbers to vectors of City structs

int main() {
    int n, m; // Declares variables to hold the number of prefectures and cities
    std::cin >> n >> m; // Reads the number of prefectures and cities from input
    CMap h; // Initializes the map to store cities by their prefecture

    // Loop to read city entries
    for (int i = 0; i < m; i++) {
        int x, y; // Declares variables to hold prefecture number and year
        std::cin >> x >> y; // Reads the prefecture number and year from input
        h[x].push_back({x, i, y}); // Appends the city to the vector in the map
    }

    std::vector<std::string> results(m); // Initializes a vector to hold the formatted city strings

    // Loop to sort and format cities
    for (auto& pair : h) {
        Cities& cities = pair.second; // Get the vector of cities for the prefecture
        std::sort(cities.begin(), cities.end(), [](const City& a, const City& b) {
            return a.year < b.year; // Sorts cities by their establishment year
        });
        for (size_t idx = 0; idx < cities.size(); idx++) {
            const City& ci = cities[idx];
            std::ostringstream oss;
            oss << std::setw(6) << std::setfill('0') << ci.prefecture
                << std::setw(6) << std::setfill('0') << (idx + 1); // Formats the city string
            results[ci.position] = oss.str(); // Store the formatted string in the results
        }
    }

    // Joins the formatted city strings and prints them
    for (const auto& result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
