#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    string result = "Yes" if (s.find("A")!= string::npos && s.find("B")!= string::npos) else "No";
    cout << result << endl;
    return 0;
}

