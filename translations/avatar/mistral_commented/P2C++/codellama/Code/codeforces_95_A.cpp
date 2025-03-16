#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    int pya; // Initialize variables
    vector<string> arre;
    string oString, letter1, letter2;
    set<int> setcito;

    // Process strings input
    cin >> pya;
    while (pya--) {
        string x;
        cin >> x;
        arre.push_back(x);
    }

    // Get the original string and its first letter
    cin >> oString >> letter1;

    // Determine the second letter based on the first letter
    letter2 = 'a' + (letter1 != 'a');

    // Initialize a list of valid indices and a set to store the indices of the strings in the original string
    vector<int> valid(oString.length(), 0);

    // Find the indices of the strings in the original string
    for (string x : arre) {
        for (int i = oString.find(x); i != string::npos; i = oString.find(x, i + 1)) {
            setcito.insert(i);
        }
    }

    // Replace the letters in the original string based on the indices of the strings
    for (int i : setcito) {
        oString[i] = (oString[i] == letter1 ? letter2 : letter1);
    }

    // Print the modified string
    cout << oString << endl;

    return 0;
}

