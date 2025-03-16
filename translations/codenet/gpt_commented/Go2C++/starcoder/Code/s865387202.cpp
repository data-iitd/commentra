#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Define a struct to represent a city with its prefecture, year, and position
struct city {
	int prefecture; // Prefecture number
	int position;   // Position in the input
	int year;       // Year associated with the city
};

// Define a map where the key is an integer (prefecture) and the value is a vector of cities
typedef map<int, vector<city>> cMap;

int main() {
	int n, m; // n: number of prefectures, m: number of cities
	cin >> n >> m;
	
	// Initialize a map to hold cities grouped by their prefecture
	cMap h;
	
	// Read city data from input
	for (int i = 0; i < m; i++) {
		int x, y; // x: prefecture number, y: year
		cin >> x >> y;
		
		// Check if the prefecture already exists in the map
		cMap::iterator it = h.find(x);
		if (it == h.end()) {
			// If it doesn't exist, create a new entry with the city
			h[x] = vector<city>{city{x, i, y}};
		} else {
			// If it exists, append the new city to the existing vector
			h[x].push_back(city{x, i, y});
		}
	}

	// Prepare a results vector to hold formatted output for each city
	vector<string> results(m);

	// Iterate over each group of cities in the map
	for (auto it = h.begin(); it!= h.end(); it++) {
		// Sort the cities by year using the Less method defined below
		sort(it->second.begin(), it->second.end(), [](city a, city b) {
			return a.year < b.year;
		});
		// Format the output for each city based on its position and year
		for (int i = 0; i < it->second.size(); i++) {
			results[it->second[i].position] = to_string(it->second[i].prefecture) + to_string(i + 1);
		}
	}
	
	// Print the results, joining them with newline characters
	cout << endl;
	for (string s : results) {
		cout << s << endl;
	}
}

