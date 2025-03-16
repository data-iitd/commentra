#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a struct to hold the data for the images
struct data {
	int n, m; // Dimensions of the images and their slices
	vector<string> nImg, mImg; // Slices to hold the image data
};

// Function to initialize a new data instance by reading image dimensions and data from standard input
data newData() {
	int n, m;
	cin >> n >> m; // Read the dimensions of the images
	
	// Load the images from standard input
	vector<string> nImg = load(n);
	vector<string> mImg = load(m);

	// Return a new data instance with the loaded images and dimensions
	return data{n, m, nImg, mImg};
}

// Function to read a specified number of strings from standard input and return them as a vector of strings
vector<string> load(int cnt) {
	vector<string> ret(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> ret[i]; // Read each string from standard input
	}
	return ret;
}

// Method to check if the smaller image exists within the larger image
bool exist(data d) {
	// Iterate over all possible positions where the smaller image could fit within the larger image
	for (int i = 0; i <= d.n-d.m; i++) {
		for (int j = 0; j <= d.n-d.m; j++) {
			if (match(d, i, j)) { // Check if the smaller image matches the corresponding part of the larger image at the current position
				return true;
			}
		}
	}
	return false;
}

// Method to check if the smaller image matches the corresponding part of the larger image at a given position
bool match(data d, int x, int y) {
	// Iterate over each pixel in the smaller image and compare it with the corresponding pixel in the larger image
	for (int i = 0; i < d.m; i++) {
		for (int j = 0; j < d.m; j++) {
			if (d.nImg[x+i][y+j] != d.mImg[i][j]) { // If any pixel does not match, return false
				return false;
			}
		}
	}
	return true; // If all pixels match, return true
}

int main() {
	// Create a new data instance
	data d = newData();
	
	// Check if the smaller image exists within the larger image and print the result
	if (exist(d)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}

