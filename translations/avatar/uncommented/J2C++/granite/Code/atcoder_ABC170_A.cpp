
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    stringstream ss;
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    int count = 0;
    while (ss >> word) {
        count++;
        if (word == "0") {
            break;
        }
    }
    cout << count << endl;
    return 0;
}
// END-OF-CODE