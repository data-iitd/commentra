
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s() {
    // Take input from the user
    cin.ignore();
    // Read the input, split it into a list of integers, and store it in 'a'
    vector<int> a;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int temp;
    while (ss >> temp) {
        a.push_back(temp);
    }
    // Sort the list 'a'
    sort(a.begin(), a.end());
    // Iterate through the sorted list starting from the second element
    for (int i = 1; i < a.size(); i++) {
        // Check if the current element is not equal to the previous element
        // and if the current element is less than twice the previous element
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
            // If the condition is met, return 'YES'
            return "YES";
        }
    }
    // If the loop completes without finding a match, return 'NO'
    return "NO";
}
// Print the result returned by the function 's()'
cout << s() << endl;