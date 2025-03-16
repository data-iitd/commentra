
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string s1, s2;
    getline(ss, s1,'');
    getline(ss, s2);
    int h = stoi(s1);
    int a = stoi(s2);
    int num = 0;
    for (int i = 1; h > 0; i++) {
        h = h - a;
        num++;
    }
    cout << num << endl;
    return 0;
}
// END-OF-CODE