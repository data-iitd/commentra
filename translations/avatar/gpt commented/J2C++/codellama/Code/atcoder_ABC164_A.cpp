#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Creating a vector to store the input strings
    vector<string> scList;

    // Continuously read input lines until an exception occurs (e.g., EOF)
    for (int i = 0; i >= 0; i++) {
        try {
            // Adding the input line to the vector
            scList.push_back(cin.getline());
        } catch (exception e) {
            // Break the loop if an exception occurs (e.g., no more input)
            break;
        }
    }

    // Splitting the first line of input into an array of strings
    string numlist[2];
    stringstream ss(scList[0]);
    ss >> numlist[0] >> numlist[1];
    
    // Parsing the first number as the count of sheep
    int Sheep = stoi(numlist[0]);
    
    // Parsing the second number as the count of wolves
    int Wolve = stoi(numlist[1]);

    // Checking if the number of wolves is greater than or equal to the number of sheep
    if (Wolve >= Sheep) {
        // If wolves are greater than or equal to sheep, it's unsafe
        cout << "unsafe" << endl;
    } else {
        // If wolves are fewer than sheep, it's safe
        cout << "safe" << endl;
    }

    // End of code
    cout << "