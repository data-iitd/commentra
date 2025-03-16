
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> scList;
    string line;
    int Sheep, Wolve;

    while (getline(cin, line)) {
        scList.push_back(line);
    }

    stringstream ss(scList[0]);
    ss >> Sheep >> Wolve;

    if (Wolve >= Sheep) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }

    return 0;
}

