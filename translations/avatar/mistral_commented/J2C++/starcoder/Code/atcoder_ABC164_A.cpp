#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int Sheep, Wolves;
    vector <string> scList;

    while (1) {
        try {
            string line;
            getline(cin, line);
            scList.push_back(line);
        } catch (exception e) {
            break;
        }
    }

    string numlist[2];
    numlist = scList[0].split(" ");
    Sheep = stoi(numlist[0]);
    Wolves = stoi(numlist[1]);

    if (Wolves >= Sheep) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }

    return 0;
}

