
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
    string a;
    cin >> a;
    a.erase(remove(a.begin(), a.end(), ','), a.end());
    cout << a << endl;
    return 0;
}

