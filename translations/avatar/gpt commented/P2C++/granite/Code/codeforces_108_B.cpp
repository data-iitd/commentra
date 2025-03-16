
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s() {
    // Read an input line (not used in the logic)
    string input;
    getline(cin, input);
    
    // Read a line of integers, split by spaces, and convert them to a vector of integers
    vector<int> a;
    int num;
    while (cin >> num) {
        a.push_back(num);
    }
    
    // Sort the vector of integers in ascending order
    sort(a.begin(), a.end());
    
    // Iterate through the sorted vector starting from the second element
    for (int i = 1; i < a.size(); i++) {
        // Check if the current element is different from the previous one
        // and if it is less than double the previous element
        if (a[i]!= a[i - 1] && a[i] < a[i - 1] * 2) {
            // If the condition is met, return 'YES'
            return "YES";
        }
    }
    
    // If no such pair is found, return 'NO'
    return "NO";
}

int main() {
    // Call the function and print the result
    cout << s() << endl;
    
    return 0;
}

