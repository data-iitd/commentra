#include <iostream>
#include <string>
using namespace std;

void cout(string str) {
    cout << str << endl;
}

int main() {
    int n;
    string str, a = "", b = "";
    
    // Reading the integer input n
    cin >> n;
    cin.ignore(); // To ignore the newline character after the integer input
    
    // Reading the string input str
    getline(cin, str);
    
    // Constructing the string a by taking the first n/2 characters of str
    for (int i = 0; i < n / 2; i++) {
        a += str[i];
    }
    
    // Checking if str is equal to a + a and printing the result
    if (str == a + a)
        cout("Yes");
    else
        cout("No");
    
    return 0;
}

