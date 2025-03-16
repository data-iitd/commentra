#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

// Initialize a new scanner object
class Scanner {
public:
    Scanner(istream& is) : is_(is) {}

    // Read a single token from the standard input
    string Next() {
        string token;
        is_ >> token;
        return token;
    }

    // Read a line from the standard input
    string NextLine() {
        string line;
        getline(is_, line);
        return line;
    }

    // Read an integer from the standard input
    int NextInt() {
        int value;
        is_ >> value;
        return value;
    }

    // Read an array of integers from the standard input
    vector<int> NextIntArray() {
        string line;
        getline(is_, line);
        vector<int> result;
        stringstream ss(line);
        int value;
        while (ss >> value) {
            result.push_back(value);
        }
        return result;
    }

    // Read a map from the standard input
    map<int, bool> NextMap() {
        map<int, bool> result;
        string line;
        getline(is_, line);
        stringstream ss(line);
        int value;
        while (ss >> value) {
            result[value] = true;
        }
        return result;
    }

private:
    istream& is_;
};

int main() {
    Scanner sc(cin);

    // Read the number of elements in the array from the standard input
    int n = sc.NextInt();

    // Allocate memory for the array of size n
    vector<double> arr(n);

    // Read n integers from the standard input and store them in the array
    for (int i = 0; i < n; i++) {
        arr[i] = sc.NextInt();
    }

    // Sort the array in ascending order
    sort(arr.begin(), arr.end());

    // Initialize a variable prev to store the previous element in the sorted array
    double prev = arr[0];

    // Iterate through the sorted array from the second element to the last
    for (int i = 1; i < arr.size(); i++) {
        // Calculate the average of the previous and current elements
        prev = (prev + arr[i]) / 2;
    }

    // Print the result to the standard output
    cout << fixed << setprecision(10) << prev << endl;

    return 0;
}
