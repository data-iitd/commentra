

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int inp;
    cin >> inp;  // Taking an integer input from the user
    vector<int> lista;
    string s;
    getline(cin, s);  // Reading the input string
    stringstream ss(s);
    string item;
    while (getline(ss, item,'')) {
        lista.push_back(stoi(item));  // Converting the input string into a vector of integers
    }

    // Iterating through the vector of integers
    for (int i = 0; i < lista.size(); i++) {
        // For the first element in the vector
        if (i == 0) {
            cout << lista[i + 1] - lista[i] << " " << lista[lista.size() - 1] - lista[i] << endl;  // Printing the differences
            continue;
        }
        // For the last element in the vector
        else if (i == lista.size() - 1) {
            cout << lista[lista.size() - 1] - lista[lista.size() - 2] << " " << lista[lista.size() - 1] - lista[0] << endl;  // Printing the differences
            continue;
        }
        // For other elements in the vector
        else if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
            cout << lista[i + 1] - lista[i] << " ";  // Printing the difference between the next and current integer
        }
        else {
            cout << lista[i] - lista[i - 1] << " ";  // Printing the difference between the current and previous integer
        }
        // Printing the difference between the last and current integer or the first and current integer
        if (lista[lista.size() - 1] - lista[i] > lista[i] - lista[0]) {
            cout << lista[lista.size() - 1] - lista[i] << endl;  // Printing the difference between the last and current integer
        }
        else {
            cout << lista[i] - lista[0] << endl;  // Printing the difference between the first and current integer
        }
    }

    return 0;
}

