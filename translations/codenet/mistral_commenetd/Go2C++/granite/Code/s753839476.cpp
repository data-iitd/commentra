

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, a;
    cin >> n >> t >> a;

    vector<float> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    float minDiff = abs(t - heights[0] * 0.006 - a);
    int minIdx = 0;

    for (int i = 1; i < n; i++) {
        float diff = abs(t - heights[i] * 0.006 - a);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i + 1;
        }
    }

    cout << minIdx << endl;

    return 0;
}

// Function to handle resource deallocation
void flash() {
    // Code to handle resource deallocation
}

// Function to calculate the absolute difference between two float numbers
float AbsDiffFloat(float n1, float n2) {
    return abs(n1 - n2);
}

// End of code
