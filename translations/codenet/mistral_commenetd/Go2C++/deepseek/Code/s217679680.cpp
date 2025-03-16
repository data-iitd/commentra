#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    // Read the input line from stdin
    string line;
    getline(cin, line);
    // Initialize a stringstream to parse the input line
    stringstream ss(line);
    // Initialize an empty vector to store the integers
    vector<int> arr;
    // Initialize a variable to store each integer
    string s;
    // Parse the input line by space and convert each element to integer
    while (ss >> s) {
        // Convert the string to integer and append it to the vector
        arr.push_back(stoi(s));
    }
    // Initialize variables a and b with the first two elements of the vector
    int a = arr[0], b = arr[1];
    // Initialize variables tap and consent with default values
    int tap = 0, consent = 1;
    // Loop until consent is greater than or equal to b
    while (consent < b) {
        // Increment consent by the sum of a and consent minus one
        consent = consent + a - 1;
        // Increment tap by one for each iteration
        tap++;
    }
    // Print the result, i.e., the number of taps required
    cout << tap << endl;
    return 0;
}

