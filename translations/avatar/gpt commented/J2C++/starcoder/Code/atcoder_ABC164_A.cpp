#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Creating a Scanner object to read input from the console
    string line;
    getline(cin, line);
    vector<string> scList;
    scList.push_back(line);

    // Continuously read input lines until an exception occurs (e.g., EOF)
    while (true) {
        try {
            // Adding the input line to the ArrayList
            getline(cin, line);
            scList.push_back(line);
        } catch (exception& e) {
            // Break the loop if an exception occurs (e.g., no more input)
            break;
        }
    }

    // Splitting the first line of input into an array of strings
    string numlist[2];
    numlist = scList.at(0).split(" ");

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

    return 0;
}

