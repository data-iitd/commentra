

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    vector<string> scList;
    string line;
    while (getline(cin, line)) {
        scList.push_back(line);
    }

    stringstream ss(scList[0]);
    int sheep, wolves;
    ss >> sheep >> wolves;

    if (wolves >= sheep) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }

    return 0;
}
