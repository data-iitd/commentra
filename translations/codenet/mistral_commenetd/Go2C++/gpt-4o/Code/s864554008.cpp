#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a custom data structure
struct Data {
    int n, m; // dimensions of the images
    vector<string> nImg, mImg; // image data as strings

    // Check if data already exists in the larger image
    bool exist() {
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
    bool match(int x, int y) {
        // Iterate through each pixel in smaller image
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                // Check if corresponding pixel in larger image matches
                if (nImg[x + i][y + j] != mImg[i][j]) {
                    // If mismatch is found, return false
                    return false;
                }
            }
        }
        // If all pixels match, return true
        return true;
    }
};

// Load image data as strings
vector<string> load(int cnt) {
    vector<string> ret(cnt);
    // Read image data from user input
    for (int i = 0; i < cnt; i++) {
        cin >> ret[i];
    }
    // Return loaded image data
    return ret;
}

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

// Main function
int main() {
    // Initialize a new data object
    Data d = newData();
    // Check if data already exists
    if (d.exist()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

// <END-OF-CODE>
