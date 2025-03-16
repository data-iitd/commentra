#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the entire input
    string line;
    getline(cin, line); // Read the first line (not used)
    getline(cin, line); // Read the second line

    // Split the second line into a vector of integers
    vector<int> a;
    int num;
    istringstream iss(line);
    while (iss >> num) {
        a.push_back(num);
    }

    // Sort the vector
    sort(a.begin(), a.end());

    // Check if the smallest element is divisible by any other element
    int smallest = a[0];
    bool divisible = false;
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i] % smallest == 0) {
            divisible = true;
            break;
        }
    }

    // Print the result
    cout << (divisible ? smallest : -1) << endl;

    return 0;
}
// <END-OF-CODE>
