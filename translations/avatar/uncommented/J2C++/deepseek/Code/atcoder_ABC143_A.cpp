#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string line;
    try {
        getline(cin, line);
        stringstream ss(line);
        vector<string> x;
        string temp;
        while (ss >> temp) {
            x.push_back(temp);
        }
        int a = stoi(x[0]);
        int b = stoi(x[1]);
        int c = a - b * 2;
        if (c < 0) c = 0;
        cout << c << endl;
    } catch (exception &e) {
    }
    return 0;
}
