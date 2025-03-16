#include <iostream>
#include <string>
using namespace std;
int main() {
    string c;
    cin >> c;
    string a = "abcdefghijklmnopqrstuvwxyz";
    int i = a.find(c);
    cout << a[i+1];
    return 0;
}
