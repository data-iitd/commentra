#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read an integer input (not used later in the code)
    int inp;
    cin >> inp;

    // Initialize an empty list to store integers
    vector<int> lista;

    // Read a line of input, split it into strings, convert each string to an integer, and store it in lista
    string line;
    cin >> line;
    for (string::iterator it = line.begin(); it!= line.end(); it++) {
        lista.push_back(stoi(*it));
    }

    // Iterate through the indices of the lista
    for (int i = 0; i < lista.size(); i++) {
        // Handle the first element in the list
        if (i == 0) {
            // Calculate and print the difference between the second and first elements,
            // and the difference between the last and first elements
            cout << lista[i+1] - lista[i] << " " << lista[lista.size()-1] - lista[i] << endl;
            continue;  // Skip to the next iteration
        }

        // Handle the last element in the list
        if (i == lista.size() - 1) {
            // Calculate and print the difference between the last and second-to-last elements,
            // and the difference between the last and the first elements
            cout << lista[lista.size()-1] - lista[lista.size()-2] << " " << lista[lista.size()-1] - lista[0] << endl;
            continue;  // Skip to the next iteration
        }

        // For elements in the middle of the list
        if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
            // If the difference to the next element is smaller, print that difference
            cout << lista[i + 1] - lista[i] << " ";
        } else {
            // Otherwise, print the difference to the previous element
            cout << lista[i] - lista[i - 1] << " ";

        // Compare the difference to the last element with the difference to the first element
        if (lista[lista.size() - 1] - lista[i] > lista[i] - lista[0]) {
            // If the difference to the last element is larger, print that difference
            cout << lista[lista.size() - 1] - lista[i] << endl;
        } else {
            // Otherwise, print the difference to the first element
            cout << lista[i] - lista[0] << endl;
        }
    }

    return 0;
}

