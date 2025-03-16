#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    try {
        string line;
        getline(cin, line);
        vector<string> v = split(line, " ");
        int a = stoi(v[0]);
        int b = stoi(v[1]);
        int c = a - b * 2;
        if (c < 0) c = 0;
        cout << c << endl;
    } catch (exception &e) {
        // Handle exceptions (not implemented in this code)
    }
    return 0;
}

