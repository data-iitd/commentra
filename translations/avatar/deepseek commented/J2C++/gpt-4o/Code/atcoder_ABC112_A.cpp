#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Reading the number of inputs
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after reading n

    // Processing the input based on the value of n
    if (n == 1) {
        // Outputting "Hello World" if n is 1
        cout << "Hello World" << endl;
    } else {
        // Reading two strings and calculating their sum if n is not 1
        string str1, str2;
        getline(cin, str1);
        getline(cin, str2);
        cout << stoi(str1) + stoi(str2) << endl;
    }

    return 0;
}

// <END-OF-CODE>
