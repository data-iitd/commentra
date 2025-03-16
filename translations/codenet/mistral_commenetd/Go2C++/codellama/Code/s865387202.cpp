// Include the iostream header for input/output operations.
#include <iostream>

// Include the algorithm header for sorting.
#include <algorithm>

// Include the string header for string operations.
#include <string>

// Define a custom city struct with three fields: prefecture, position, and year.
struct city {
	int prefecture;
	int position;
	int year;
};

// Define a custom cities vector with a vector of pointers to city structs.
typedef std::vector<city*> cities;

// Define a custom cMap map with an integer key and a cities vector as the value.
typedef std::map<int, cities> cMap;

// Define a custom citiesLess function for comparing two cities structs.
bool citiesLess(city* a, city* b) {
	return a->year < b->year;
}

// Define a custom citiesSort function for sorting a cities vector.
void citiesSort(cities& v) {
	std::sort(v.begin(), v.end(), citiesLess);
}

// Define a custom citiesJoin function for joining a cities vector to a string.
std::string citiesJoin(cities& v) {
	std::string result;
	for (int i = 0; i < v.size(); i++) {
		result += std::to_string(v[i]->prefecture);
		result += std::to_string(i + 1);
	}
	return result;
}

// Define a custom citiesMap function for mapping a cMap to a string.
std::string citiesMap(cMap& h) {
	std::string result;
	for (auto it = h.begin(); it != h.end(); it++) {
		citiesSort(it->second);
		result += citiesJoin(it->second);
	}
	return result;
}

// Define a custom main function as the entry point of the program.
int main() {
	// Read the number of cities and events from the standard input.
	int n, m;
	std::cin >> n >> m;

	// Initialize an empty cMap named h.
	cMap h;

	// Read m pairs of integers x and y from the standard input.
	for (int i = 0; i < m; i++) {
		// Read an integer x from the standard input.
		int x;
		std::cin >> x;

		// Read an integer y from the standard input.
		int y;
		std::cin >> y;

		// Check if the prefecture x already exists in the cMap.
		auto it = h.find(x);

		// If the prefecture x does not exist in the cMap, create a new cities vector with one element and assign it to the key x in the cMap.
		if (it == h.end()) {
			cities v;
			v.push_back(new city{x, i, y});
			h[x] = v;
		} else {
			// If the prefecture x already exists in the cMap, append a new city struct to the existing cities vector.
			it->second.push_back(new city{x, i, y});
		}
	}

	// Print the final result using citiesMap and std::cout.
	std::cout << citiesMap(h) << std::endl;

	// End of code.
	return 0;
}

// End of code.
