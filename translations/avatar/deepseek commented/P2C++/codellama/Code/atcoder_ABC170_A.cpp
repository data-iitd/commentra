
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    istringstream iss(input);
    vector<int> a;
    int temp;
    while (iss >> temp) {
        a.push_back(temp);
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 0) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}

