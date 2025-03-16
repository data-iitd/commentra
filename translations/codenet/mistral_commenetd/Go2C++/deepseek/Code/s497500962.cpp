#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

// Utility functions
int abs(int x) {
    return abs(x);
}

int min(int x, int y) {
    return min(x, y);
}

int max(int x, int y) {
    return max(x, y);
}

// Input related functions
int nextInt() {
    int i;
    cin >> i;
    return i;
}

float nextFloat() {
    float f;
    cin >> f;
    return f;
}

string nextString() {
    string s;
    cin >> s;
    return s;
}

int main() {
    // Initialize variables R, G, B, and N with next integers
    int R = nextInt();
    int G = nextInt();
    int B = nextInt();
    int N = nextInt();

    // Initialize variable ans with zero
    int ans = 0;

    // Nested for loops to iterate through all possible combinations of x and y within the range of N
    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N; y++) {
            // Calculate temporary variable tmp
            int tmp = N - R * x - G * y;

            // Check if tmp is non-negative and the remainder of tmp when divided by B is zero
            if (tmp >= 0 && tmp % B == 0) {
                // Increment the value of ans if the condition is true
                ans++;
            }
        }
    }

    // Print the value of ans
    cout << ans << endl;

    return 0;
}
