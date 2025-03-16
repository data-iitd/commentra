

#include <iostream>
#include <vector>
#include <string>

// Define a custom data structure
struct data {
	int n, m; // dimensions of the images
	std::vector<std::string> nImg, mImg; // image data as strings
};

// Main function
int main() {
	// Initialize a new data object
	data d = newData();
	// Check if data already exists
	if (d.exist()) {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "No" << std::endl;
	}
}

// Initialize a new data object
data newData() {
	// Read dimensions from user input
	int n, m;
	std::cin >> n >> m;
	// Load image data as strings
	std::vector<std::string> nImg = load(n);
	std::vector<std::string> mImg = load(m);

	// Initialize data object with loaded data
	return data{n: n, m: m, nImg: nImg, mImg: mImg};
}

// Load image data as strings
std::vector<std::string> load(int cnt) {
	// Allocate memory for image data
	std::vector<std::string> ret(cnt);
	// Read image data from user input
	for (int i = 0; i < cnt; i++) {
		std::cin >> ret[i];
	}

	// Return loaded image data
	return ret;
}

// Check if data already exists in the larger image
bool data::exist() {
	// Iterate through all possible positions in larger image
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			// Check if current position matches the smaller image
			if (match(i, j)) {
				// If match is found, return true
				return true;
			}
		}
	}

	// If no match is found, return false
	return false;
}

// Check if smaller image matches at current position in larger image
bool data::match(int x, int y) {
	// Iterate through each pixel in smaller image
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			// Check if corresponding pixel in larger image matches
			if (nImg[x + i][y + j]!= mImg[i][j]) {
				// If mismatch is found, return false
				return false;
			}
		}
	}

	// If all pixels match, return true
	return true;
}

// End of code
