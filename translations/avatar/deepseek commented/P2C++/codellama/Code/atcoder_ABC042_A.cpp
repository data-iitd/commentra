
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    istringstream iss(input);
    vector<int> ABC;
    int temp;
    while (iss >> temp) {
        ABC.push_back(temp);
    }
    if (count(ABC.begin(), ABC.end(), 5) == 2) {
        if (accumulate(ABC.begin(), ABC.end(), 0) == 17) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

