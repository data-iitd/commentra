
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int tap = 0;
    int consent = 1;
    while (consent < b) {
        consent = consent + a - 1;
        tap++;
    }
    cout << tap << endl;
    return 0;
}

