
#include <iostream>
#include <string>
using namespace std;

char* generateString() {
    string s = "";
    for (int i = 1; i <= 1000; i++) {
        s += i;
    }
    return s.c_str();
}

int main() {
    int n;
    cin >> n;
    cout << generateString()[n - 1];
    return 0;
}

