
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a custom data structure
struct data {
    int n, m; // dimensions of the images
    vector<string> nImg, mImg; // image data as strings
};

// Main function
int main() {
    // Initialize a new data object
    data d = newData();
    // Check if data already exists
    if (d.exist()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

// Initialize a new data object
data newData() {
    // Read dimensions from user input
    int n, m;
    cin >> n >> m;
    // Load image data as strings
    vector<string> nImg = load(n);
    vector<string> mImg = load(m);

    // Initialize data object with loaded data
    data d = {n, m, nImg, mImg};

    return d;
}

// Load image data as strings
vector<string> load(int cnt) {
    // Allocate memory for image data
    vector<string> ret(cnt);
    // Read image data from user input
    for (int i = 0; i < cnt; i++) {
        cin >> ret[i];
    }

    // Return loaded image data
    return ret;
}

// Check if data already exists in the larger image
bool data::exist() {
    // Iterate through all possible positions in larger image
    for (int i = 0; i <= n-m; i++) {
        for (int j = 0; j <= n-m; j++) {
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
            if (nImg[x+i][y+j] != mImg[i][j]) {
                // If mismatch is found, return false
                return false;
            }
        }
    }

    // If all pixels match, return true
    return true;
}

