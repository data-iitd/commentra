
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Define a struct to represent a city with its prefecture, year, and position
struct city {
	int prefecture; // Prefecture number
	int position; // Position in the input
	int year; // Year associated with the city
};

// Define a vector of city pointers for sorting
typedef vector<city*> cities;

// Define a map where the key is an integer (prefecture) and the value is a vector of cities
typedef map<int, cities> cMap;

int main() {
	int n, m; // n: number of prefectures, m: number of cities
	
	// Read the number of prefectures and cities from input
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
			cities v;
			v.push_back(new city{x, i, y});
			h[x] = v;
		} else {
			// If it exists, append the new city to the existing vector
			h[x].push_back(new city{x, i, y});
		}
	}

	// Prepare a results vector to hold formatted output for each city
	vector<string> results(m);

	// Iterate over each group of cities in the map
	for (cMap::iterator it = h.begin(); it != h.end(); it++) {
		// Sort the cities by year using the Less method defined below
		sort(it->second.begin(), it->second.end(), Less);
		// Format the output for each city based on its position and year
		for (int idx = 0; idx < it->second.size(); idx++) {
			city* ci = it->second[idx];
			results[ci->position] = to_string(ci->prefecture) + to_string(idx+1);
		}
	}
	
	// Print the results, joining them with newline characters
	for (int i = 0; i < m; i++) {
		cout << results[i] << endl;
	}
	
	return 0;
}

// Implement the Less method for sorting cities by year
bool Less(city* a, city* b) {
	return a->year < b->year;
}

