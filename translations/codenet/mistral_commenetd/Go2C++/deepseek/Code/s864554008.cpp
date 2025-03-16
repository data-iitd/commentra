#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a custom data structure
struct Data {
    int n, m; // dimensions of the images
    vector<string> nImg, mImg; // image data as strings
};

// Initialize a new data object
Data newData() {
    // Read dimensions from user input
    int n, m;
    cin >> n >> m;
    // Load image data as strings
    vector<string> nImg = load(n);
    vector<string> mImg = load(m);

    // Initialize data object with loaded data
    return Data{n, m, nImg, mImg};
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
bool exist(const Data& d) {
    // Iterate through all possible positions in larger image
    for (int i = 0; i <= d.n - d.m; i++) {
        for (int j = 0; j <= d.n - d.m; j++) {
            // Check if current position matches the smaller image
            if (match(d, i, j)) {
                // If match is found, return true
                return true;
            }
        }
    }

    // If no match is found, return false
    return false;
}

// Check if smaller image matches at current position in larger image
bool match(const Data& d, int x, int y) {
    // Iterate through each pixel in smaller image
    for (int i = 0; i < d.m; i++) {
        for (int j = 0; j < d.m; j++) {
            // Check if corresponding pixel in larger image matches
            if (d.nImg[x + i][y + j] != d.mImg[i][j]) {
                // If mismatch is found, return false
                return false;
            }
        }
    }

    // If all pixels match, return true
    return true;
}

int main() {
    // Initialize a new data object
    Data d = newData();
    // Check if data already exists
    if (exist(d)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

