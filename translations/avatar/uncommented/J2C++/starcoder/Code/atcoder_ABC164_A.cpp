#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<string> scList;
    while (getline(iss, line)) {
        scList.push_back(line);
    }
    stringstream ss(scList[0]);
    int Sheep, Wolve;
    ss >> Sheep >> Wolve;
    if (Wolve >= Sheep) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }
    return 0;
}

