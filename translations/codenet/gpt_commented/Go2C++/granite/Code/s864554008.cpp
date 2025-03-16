
#include <iostream>
#include <vector>
#include <string>

// Define a struct to hold the dimensions and images
struct data {
	int n, m; // n: number of rows in the first image, m: number of rows in the second image
	std::vector<std::string> nImg, mImg; // nImg: first image as a vector of strings, mImg: second image as a vector of strings
};

int main() {
	// Create a new data instance and check for the existence of a match
	data d = newData();
	if (d.exist()) {
		std::cout << "Yes" << std::endl; // Print "Yes" if a match exists
	} else {
		std::cout << "No" << std::endl; // Print "No" if no match is found
	}
}

// Function to read input dimensions and images, returning a data instance
data newData() {
	int n, m;
	// Read the dimensions of the images from standard input
	std::cin >> n >> m;
	// Load the first image and the second image based on the dimensions
	std::vector<std::string> nImg = load(n);
	std::vector<std::string> mImg = load(m);

	// Return a data instance containing the dimensions and images
	return data{n: n, m: m, nImg: nImg, mImg: mImg};
}

// Function to load an image of given count from standard input
std::vector<std::string> load(int cnt) {
	std::vector<std::string> ret(cnt); // Create a vector to hold the image strings
	for (int i = 0; i < cnt; i++) {
		// Read each line of the image into the vector
		std::string line;
		std::cin >> line;
		ret[i] = line;
	}

	// Return the loaded image
	return ret;
}

// Method to check if the second image exists within the first image
bool data::exist() {
	// Iterate over possible starting positions in the first image
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			// Check if the second image matches the first image at the current position
			if (match(i, j)) {
				return true; // Return true if a match is found
			}
		}
	}

	// Return false if no match is found after checking all positions
	return false;
}

// Method to check if the second image matches the first image at a specific position
bool data::match(int x, int y) {
	// Iterate over each cell of the second image
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			// Compare the corresponding cells of the two images
			if (nImg[x + i][y + j]!= mImg[i][j]) {
				return false; // Return false if any cell does not match
			}
		}
	}

	// Return true if all cells match
	return true;
}

// END-OF-CODE