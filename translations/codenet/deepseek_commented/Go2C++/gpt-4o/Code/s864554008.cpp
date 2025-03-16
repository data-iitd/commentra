#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a struct to hold the data for the images
struct Data {
    int n, m; // Dimensions of the images and their slices
    vector<string> nImg, mImg; // Vectors to hold the image data
};

// Function to initialize a new Data instance by reading image dimensions and data from standard input
Data newData() {
    int n, m;
    cin >> n >> m; // Read the dimensions of the images

    // Load the images from standard input
    vector<string> nImg(n);
    vector<string> mImg(m);
    
    for (int i = 0; i < n; i++) {
        cin >> nImg[i]; // Read each string for the larger image
    }
    
    for (int i = 0; i < m; i++) {
        cin >> mImg[i]; // Read each string for the smaller image
    }

    // Return a new Data instance with the loaded images and dimensions
    return Data{n, m, nImg, mImg};
}

// Method to check if the smaller image exists within the larger image
bool exist(const Data& d) {
    // Iterate over all possible positions where the smaller image could fit within the larger image
    for (int i = 0; i <= d.n - d.m; i++) {
        for (int j = 0; j <= d.n - d.m; j++) {
            if (match(d, i, j)) { // Check if the smaller image matches the corresponding part of the larger image at the current position
                return true;
            }
        }
    }
    return false;
}

// Method to check if the smaller image matches the corresponding part of the larger image at a given position
bool match(const Data& d, int x, int y) {
    // Iterate over each pixel in the smaller image and compare it with the corresponding pixel in the larger image
    for (int i = 0; i < d.m; i++) {
        for (int j = 0; j < d.m; j++) {
            if (d.nImg[x + i][y + j] != d.mImg[i][j]) { // If any pixel does not match, return false
                return false;
            }
        }
    }
    return true; // If all pixels match, return true
}

int main() {
    // Create a new Data instance
    Data d = newData();
    
    // Check if the smaller image exists within the larger image and print the result
    if (exist(d)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

// <END-OF-CODE>
