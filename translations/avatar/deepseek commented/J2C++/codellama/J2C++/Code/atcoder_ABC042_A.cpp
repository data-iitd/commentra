
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string list[3];
    int x, a, y;
    ss >> list[0] >> list[1] >> list[2];
    x = stoi(list[0]);
    a = stoi(list[1]);
    y = stoi(list[2]);
    string h = "NO";
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        if (x + y + a == 17) {
            h = "YES";
        }
    }
    cout << h << endl;
    return 0;
}

