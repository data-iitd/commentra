
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    stringstream ss;
    string s;
    getline(cin, s);
    ss << s.replace(s.find(","), 1, " ");
    cout << ss.str() << endl;
    return 0;
}
// 