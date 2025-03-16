
#include <iostream>
#include <vector>
#include <string>

// Define a struct to hold the data for the images
struct data {
	int n, m; // Dimensions of the images and their slices
	std::vector<std::string> nImg, mImg; // Slices to hold the image data
};

int main() {
	// Create a new data instance
	data d = newData();
	
	// Check if the smaller image exists within the larger image and print the result
	if (d.exist()) {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "No" << std::endl;
	}
}

// Function to initialize a new data instance by reading image dimensions and data from standard input
data newData() {
	int n, m;
	std::cin >> n >> m; // Read the dimensions of the images
	
	// Load the images from standard input
	std::vector<std::string> nImg = load(n);
	std::vector<std::string> mImg = load(m);

	// Return a new data instance with the loaded images and dimensions
	return data{n: n, m: m, nImg: nImg, mImg: mImg};
}

// Function to read a specified number of strings from standard input and return them as a vector of strings
std::vector<std::string> load(int cnt) {
	std::vector<std::string> ret(cnt);
	for (int i = 0; i < cnt; i++) {
		std::cin >> ret[i]; // Read each string from standard input
	}
	return ret;
}

// Method to check if the smaller image exists within the larger image
bool data::exist() {
	// Iterate over all possible positions where the smaller image could fit within the larger image
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			if (match(i, j)) { // Check if the smaller image matches the corresponding part of the larger image at the current position
				return true;
			}
		}
	}
	return false;
}

// Method to check if the smaller image matches the corresponding part of the larger image at a given position
bool data::match(int x, int y) {
	// Iterate over each pixel in the smaller image and compare it with the corresponding pixel in the larger image
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (nImg[x + i][y + j]!= mImg[i][j]) { // If any pixel does not match, return false
				return false;
			}
		}
	}
	return true; // If all pixels match, return true
}

// END-OF-CODE