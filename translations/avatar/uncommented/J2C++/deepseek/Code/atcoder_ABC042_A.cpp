#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    string list[3];
    int pos = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            list[pos++] = line.substr(i + 1);
        }
    }
    int x = stoi(list[0]);
    int a = stoi(list[1]);
    int y = stoi(list[2]);
    string h = "NO";
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        if (x + y + a == 17) {
            h = "YES";
        }
    }
    cout << h << endl;
    return 0;
}

