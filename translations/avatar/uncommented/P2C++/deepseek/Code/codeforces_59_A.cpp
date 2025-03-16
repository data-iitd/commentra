#include <iostream>
#include <string>
using namespace std;

int main() {
    string txt;
    int cu = 0, cl = 0;
    getline(cin, txt);
    for (char z : txt) {
        if (islower(z)) {
            cl++;
        } else {
            cu++;
        }
    }
    if (cu > cl) {
        for (char &z : txt) {
            z = toupper(z);
        }
    } else {
        for (char &z : txt) {
            z = tolower(z);
        }
    }
    cout << txt << endl;
    return 0;
}
