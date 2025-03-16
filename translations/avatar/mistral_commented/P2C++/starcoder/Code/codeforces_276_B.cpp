#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // Initialize an empty list's' to store input elements
    string s;
    cin >> s;

    // Initialize an empty dictionary 'dt' to store the count of each unique element
    map<char, int> dt;

    // Set a boolean variable 'x' to True to indicate whether there is an odd count element in the list
    bool x = true;

    // Iterate through each element 'i' in the list's'
    for (int i = 0; i < s.length(); i++) {
        // Check if the element 'i' already exists as a key in the dictionary 'dt'
        if (dt.find(s[i])!= dt.end()) {
            // If it does, increment its value by 1
            dt[s[i]]++;
        } else {
            // If not, add it as a new key with a value of 1
            dt[s[i]] = 1;
        }
    }

    // Initialize a counter 'cnt' to 0 and set 'x' to True
    int cnt = 0;
    x = true;

    // Iterate through each key-value pair ('key', 'value') in the dictionary 'dt'
    for (auto it = dt.begin(); it!= dt.end(); it++) {
        // If the value is odd and 'cnt' is less than 1, increment 'cnt' by 1
        if ((*it).second % 2!= 0 and cnt < 1) {
            cnt++;
        }
        // If the value is odd and 'cnt' is already greater than or equal to 1, set 'x' to False and break the loop
        else if ((*it).second % 2!= 0 and cnt >= 1) {
            x = false;
            break;
        }
    }

    // After the loop, check the value of 'x'
    if (x) {
        // If it is True, print "First"
        cout << "First" << endl;
    } else if (!x && s.length() % 2 == 0) {
        // If it is False and the length of the list's' is even, print "Second"
        cout << "Second" << endl;
    } else if (!x && s.length() % 2!= 0) {
        // If it is False and the length of the list's' is odd, print "First"
        cout << "First" << endl;
    }

    return 0;
}

