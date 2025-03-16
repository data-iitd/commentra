#include <iostream>
#include <string>

// Define a struct to hold the dimensions and images
struct data {
	int n, m;
	std::string nImg[1000];
	std::string mImg[1000];
};

int main() {
	// Create a new data instance and check for the existence of a match
	data d = newData();
	if (d.exist()) {
		std::cout << "Yes" << std::endl; // Print "Yes" if a match exists
	} else {
		std::cout << "No" << std::endl;  // Print "No" if no match is found
	}
}

// Function to read input dimensions and images, returning a data instance
data newData() {
	int n, m;
	// Read the dimensions of the images from standard input
	std::cin >> n >> m;
	// Load the first image and the second image based on the dimensions
	std::string nImg[1000];
	std::string mImg[1000];
	for (int i = 0; i < n; i++) {
		// Read each line of the image into the slice
		std::cin >> nImg[i];
	}
	for (int i = 0; i < m; i++) {
		// Read each line of the image into the slice
		std::cin >> mImg[i];
	}

	// Return a data instance containing the dimensions and images
	return data{n: n, m: m, nImg: nImg, mImg: mImg};
}

// Method to check if the second image exists within the first image
bool exist(data d) {
	// Iterate over possible starting positions in the first image
	for (int i = 0; i <= d.n-d.m; i++) {
		for (int j = 0; j <= d.n-d.m; j++) {
			// Check if the second image matches the first image at the current position
			if (match(d, i, j)) {
				return true; // Return true if a match is found
			}
		}
	}

	// Return false if no match is found after checking all positions
	return false;
}

// Method to check if the second image matches the first image at a specific position
bool match(data d, int x, int y) {
	// Iterate over each cell of the second image
	for (int i = 0; i < d.m; i++) {
		for (int j = 0; j < d.m; j++) {
			// Compare the corresponding cells of the two images
			if (d.nImg[x+i][y+j]!= d.mImg[i][j]) {
				return false; // Return false if any cell does not match
			}
		}
	}

	// Return true if all cells match
	return true;
}

