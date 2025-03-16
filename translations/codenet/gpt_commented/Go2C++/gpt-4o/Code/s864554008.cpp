#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a struct to hold the dimensions and images
struct Data {
    int n, m; // n: number of rows in the first image, m: number of rows in the second image
    vector<string> nImg, mImg; // nImg: first image as a vector of strings, mImg: second image as a vector of strings

    // Method to check if the second image exists within the first image
    bool exist() {
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
    bool match(int x, int y) {
        // Iterate over each cell of the second image
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                // Compare the corresponding cells of the two images
                if (nImg[x + i][y + j] != mImg[i][j]) {
                    return false; // Return false if any cell does not match
                }
            }
        }
        // Return true if all cells match
        return true;
    }
};

// Function to read input dimensions and images, returning a Data instance
Data newData() {
    Data d;
    // Read the dimensions of the images from standard input
    cin >> d.n >> d.m;
    // Load the first image and the second image based on the dimensions
    d.nImg = load(d.n);
    d.mImg = load(d.m);
    return d;
}

// Function to load an image of given count from standard input
vector<string> load(int cnt) {
    vector<string> ret(cnt); // Create a vector to hold the image strings
    for (int i = 0; i < cnt; i++) {
        // Read each line of the image into the vector
        cin >> ret[i];
    }
    // Return the loaded image
    return ret;
}

int main() {
    // Create a new Data instance and check for the existence of a match
    Data d = newData();
    if (d.exist()) {
        cout << "Yes" << endl; // Print "Yes" if a match exists
    } else {
        cout << "No" << endl;  // Print "No" if no match is found
    }
    return 0;
}

// <END-OF-CODE>
