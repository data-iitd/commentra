#include <iostream>
#include <string>

using namespace std;

void coutMessage(const string& str) {
    cout << str << endl;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after the integer input

    string str;
    getline(cin, str); // Reading the string input

    string a = "";

    // Constructing the string a by taking the first n/2 characters of str
    for (int i = 0; i < n / 2; i++) {
        a += str[i];
    }

    // Checking if str is equal to a + a and printing the result
    if (str == a + a) {
        coutMessage("Yes");
    } else {
        coutMessage("No");
    }

    return 0;
}

// <END-OF-CODE>
