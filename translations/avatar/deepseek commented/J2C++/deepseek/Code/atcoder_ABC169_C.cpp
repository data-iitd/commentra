#include <iostream>
#include <string>
using namespace std;

int main() {
    long long a;
    string b;
    cin >> a >> b;

    string bStr = "";
    for (char c : b) {
        if (c != '.') {
            bStr += c;
        }
    }

    int bInt = stoi(bStr);
    long long result = (a * bInt) / 100;
    cout << result << endl;

    return 0;
}
