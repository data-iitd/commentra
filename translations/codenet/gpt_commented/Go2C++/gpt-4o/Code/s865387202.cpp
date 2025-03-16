#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

// Define a struct to represent a city with its prefecture, year, and position
struct City {
    int prefecture; // Prefecture number
    int position;   // Position in the input
    int year;       // Year associated with the city
};

// Comparator for sorting cities by year
bool compareCities(const City* a, const City* b) {
    return a->year < b->year;
}

int main() {
    int n, m; // n: number of prefectures, m: number of cities
    // Read the number of prefectures and cities from input
    cin >> n >> m;

    // Initialize a map to hold cities grouped by their prefecture
    map<int, vector<City*>> h;

    // Read city data from input
    for (int i = 0; i < m; i++) {
        int x, y; // x: prefecture number, y: year
        cin >> x >> y;

        // Create a new city and add it to the corresponding prefecture
        City* city = new City{x, i, y};
        h[x].push_back(city);
    }

    // Prepare a results vector to hold formatted output for each city
    vector<string> results(m);

    // Iterate over each group of cities in the map
    for (auto& entry : h) {
        // Sort the cities by year
        sort(entry.second.begin(), entry.second.end(), compareCities);
        // Format the output for each city based on its position and year
        for (size_t idx = 0; idx < entry.second.size(); idx++) {
            City* ci = entry.second[idx];
            results[ci->position] = 
                to_string(ci->prefecture).insert(0, 6 - to_string(ci->prefecture).length(), '0') +
                to_string(idx + 1).insert(0, 6 - to_string(idx + 1).length(), '0');
        }
    }

    // Print the results, joining them with newline characters
    for (const auto& result : results) {
        cout << result << endl;
    }

    // Clean up dynamically allocated memory
    for (auto& entry : h) {
        for (City* city : entry.second) {
            delete city;
        }
    }

    return 0;
}

// <END-OF-CODE>
