
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<string> numlist;
    for (string s; iss >> s;) {
        numlist.push_back(s);
    }
    int Sheep = stoi(numlist[0]);
    int Wolve = stoi(numlist[1]);
    if (Wolve >= Sheep) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }
    return 0;
}

