
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    long a;
    string b;
    cin >> a >> b;
    string bStr = "";
    for (int i = 0; i < b.length(); i++) {
        if (b[i]!= '.') {
            bStr += b[i];
        }
    }
    int bInt = atoi(bStr.c_str());
    long result = (a * bInt) / 100;
    cout << result << endl;
    return 0;
}
// END-OF-CODE