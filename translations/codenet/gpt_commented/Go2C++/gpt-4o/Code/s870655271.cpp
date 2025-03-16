#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Declare variables for input dimensions and the answer
    int N, M;
    int ans = 0;
    
    // Read input values for N and M
    cin >> N >> M;
    
    // Calculate the number of valid positions based on the dimensions
    if (N == 1 && M == 1) {
        // If both dimensions are 1, there's only one position
        ans += 1;
    } else if (N > 1 && M > 1) {
        // If both dimensions are greater than 1, calculate the inner positions
        ans += (N - 2) * (M - 2);
    } else {
        // If one dimension is 1, count the edge positions
        ans += (N * M) - 2;
    }

    // Output the calculated answer
    cout << ans << endl;

    return 0;
}

/*  ----------------------------------------  */

// max function returns the maximum value from a variable number of integers
int max(int x, int y) {
    return (x > y) ? x : y;
}

// min function returns the minimum value from a variable number of integers
int min(int x, int y) {
    return (x < y) ? x : y;
}

// pow function calculates x raised to the power of y
int pow(int x, int y) {
    return static_cast<int>(std::pow(x, y));
}

// abs function returns the absolute value of an integer
int abs(int x) {
    return (x < 0) ? -x : x;
}

// floor function returns the largest integer less than or equal to x
int floor(double x) {
    return static_cast<int>(std::floor(x));
}

// SortBy is a type that implements sorting based on absolute values
struct SortBy {
    vector<int> arr;

    bool operator<(const SortBy& other) const {
        return abs(arr[0]) < abs(other.arr[0]);
    }
};

// Custom sort function to sort based on absolute values
void sortByAbs(vector<int>& vec) {
    sort(vec.begin(), vec.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });
}

