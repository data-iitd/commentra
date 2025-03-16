
#include <iostream> // Importing the necessary classes from the std namespace
#include <vector> // Importing the necessary classes from the std namespace
#include <string> // Importing the necessary classes from the std namespace

using namespace std;

int main() {
    // Creating a vector to store the input strings
    vector<string> scList;

    // Continuously read input lines until an exception occurs (e.g., EOF)
    for (int i = 0; i >= 0; i++) {
        try {
            // Reading a line of input and adding it to the vector
            string line;
            getline(cin, line);
            scList.push_back(line);
        } catch (exception e) {
            // Break the loop if an exception occurs (e.g., no more input)
            break;
        }
    }

    // Splitting the first line of input into a vector of strings
    vector<string> numlist;
    stringstream ss(scList[0]);
    string word;
    while (getline(ss, word,'')) {
        numlist.push_back(word);
    }

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
