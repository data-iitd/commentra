#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// This is the main function that takes input and calls the helper function nPairsWithCommonFX
int main() {
    // Read input from standard input
    int n;
    cin >> n;

    // Call the helper function with the sequence obtained from input
    int result = nPairsWithCommonFX(vector<int>(istream_iterator<int>(cin), istream_iterator<int>()));

    // Print the result
    cout << result << endl;

    return 0;
}

// This function takes a sequence as input and returns the number of pairs with common FX
int nPairsWithCommonFX(vector<int> sequence) {
    // Initialize an empty dictionary to store FX values and their corresponding values
    map<int, vector<int>> storage;

    // Initialize an empty list to store unique FX values
    vector<int> FXs;

    // Iterate through each value in the sequence
    for (int value : sequence) {
        // Compute the FX value for the current value
        int fx = f(value);

        // If the FX value is not already in the dictionary, add it along with the value
        if (storage.find(fx) == storage.end()) {
            storage[fx] = {value};
            FXs.push_back(fx);
        }

        // If the FX value is already in the dictionary, add the current value to the list of values for that FX
        else {
            storage[fx].push_back(value);
        }
    }

    // Calculate the result using the formula given in the problem statement
    int result = (accumulate(FXs.begin(), FXs.end(), 0, [&](int sum, int fx) { return sum + len(storage[fx]) * len(storage[fx]); }) - accumulate(FXs.begin(), FXs.end(), 0, [&](int sum, int fx) { return sum + len(storage[fx]); })) / 2;

    // Return the result
    return result;
}

// This function takes an integer as input and returns its FX value
int f(int n) {
    // Initialize a variable to store the FX value
    int fx = 1;

    // Perform bitwise operations until the number is reduced to 1
    while (n != 1) {
        // If the number is odd, increment the FX value
        if (n % 2) {
            fx += 1;
        }

        // Divide the number by 2 to reduce it further
        n /= 2;
    }

    // Return the final FX value
    return fx;
}

// This function returns the length of a vector
int len(vector<int> v) {
    return v.size();
}

// This function returns the sum of all elements in a vector
int accumulate(vector<int>::iterator begin, vector<int>::iterator end, int initialValue, function<int(int, int)> func) {
    int sum = initialValue;
    for (vector<int>::iterator it = begin; it != end; it++) {
        sum = func(sum, *it);
    }
    return sum;
}

// This function returns the sum of all elements in a vector
int accumulate(vector<int>::iterator begin, vector<int>::iterator end, function<int(int, int)> func) {
    return accumulate(begin, end, 0, func);
}

// This function returns the sum of all elements in a vector
int accumulate(vector<int> v, function<int(int, int)> func) {
    return accumulate(v.begin(), v.end(), func);
}

// This function returns the sum of all elements in a vector
int accumulate(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v.begin(), v.end(), initialValue, func);
}

// This function returns the sum of all elements in a vector
int accumulate(vector<int> v, int initialValue) {
    return accumulate(v.begin(), v.end(), initialValue);
}

// This function returns the sum of all elements in a vector
int accumulate(vector<int> v) {
    return accumulate(v.begin(), v.end());
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v) {
    return accumulate(v);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue) {
    return accumulate(v, initialValue);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v, initialValue, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, function<int(int, int)> func) {
    return accumulate(v, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v, initialValue, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, function<int(int, int)> func) {
    return accumulate(v, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue) {
    return accumulate(v, initialValue);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v) {
    return accumulate(v);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v, initialValue, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, function<int(int, int)> func) {
    return accumulate(v, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v, initialValue, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, function<int(int, int)> func) {
    return accumulate(v, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue) {
    return accumulate(v, initialValue);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v) {
    return accumulate(v);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v, initialValue, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, function<int(int, int)> func) {
    return accumulate(v, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v, initialValue, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, function<int(int, int)> func) {
    return accumulate(v, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue) {
    return accumulate(v, initialValue);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v) {
    return accumulate(v);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v, initialValue, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, function<int(int, int)> func) {
    return accumulate(v, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v, initialValue, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, function<int(int, int)> func) {
    return accumulate(v, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue) {
    return accumulate(v, initialValue);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v) {
    return accumulate(v);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v, initialValue, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, function<int(int, int)> func) {
    return accumulate(v, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v, initialValue, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, function<int(int, int)> func) {
    return accumulate(v, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue) {
    return accumulate(v, initialValue);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v) {
    return accumulate(v);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v, initialValue, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, function<int(int, int)> func) {
    return accumulate(v, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v, initialValue, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, function<int(int, int)> func) {
    return accumulate(v, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue) {
    return accumulate(v, initialValue);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v) {
    return accumulate(v);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v, initialValue, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, function<int(int, int)> func) {
    return accumulate(v, func);
}

// This function returns the sum of all elements in a vector
int sum(vector<int> v, int initialValue, function<int(int, int)> func) {
    return accumulate(v, initialValue, func);
}

// This function returns the sum of all elements in a ve