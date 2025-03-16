

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int pya;
    cin >> pya;  // Read the number of inputs to be taken
    string arre[pya];  // Initialize an array to store the inputs

    // Read pya number of inputs and convert them to lowercase, then append to arre
    for (int i = 0; i < pya; i++) {
        cin >> arre[i];
        transform(arre[i].begin(), arre[i].end(), arre[i].begin(), ::tolower);
    }

    string oString;
    cin >> oString;  // Read the original string
    string lowString = oString;
    transform(lowString.begin(), lowString.end(), lowString.begin(), ::tolower);

    char letter1;
    cin >> letter1;  // Read the first letter
    char letter2 = 'a';
    if (letter1 == 'a') {
        letter2 = 'b';
    }

    set<int> setcito;  // Initialize an empty set to store indices

    // Iterate over each string in arre and check if it exists in lowString
    for (int i = 0; i < pya; i++) {
        size_t pos = lowString.find(arre[i]);  // Find the index of the substring
        while (pos!= string::npos) {
            for (int j = pos; j < pos + arre[i].length(); j++) {
                setcito.insert(j);  // Add the indices to the set
            }
            pos = lowString.find(arre[i], pos + 1);
        }
    }

    // Convert oString to a vector for easy manipulation
    vector<char> oStringVec(oString.begin(), oString.end());

    // Update the characters in oString based on the setcito indices and letter rules
    for (auto it = setcito.begin(); it!= setcito.end(); it++) {
        char letter = letter1;
        if (lowString[*it]!= letter1) {
            letter = letter2;
        }
        if (islower(oStringVec[*it])) {
            oStringVec[*it] = letter;
        } else {
            oStringVec[*it] = toupper(letter);
        }
    }

    // Print the modified oString
    for (char c : oStringVec) {
        cout << c;
    }
    cout << endl;

    return 0;
}

