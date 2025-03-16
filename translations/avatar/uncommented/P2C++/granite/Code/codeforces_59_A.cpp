
#include <iostream>
#include <string>
using namespace std;

int main() {
    string txt;
    getline(cin, txt);
    int cu = 0, cl = 0;
    for (char z : txt) {
        if (z >= 'a' && z <= 'z') {
            cl++;
        } else {
            cu++;
        }
    }
    string out;
    if (cu > cl) {
        out = txt;
        for (char &z : out) {
            if (z >= 'a' && z <= 'z') {
                z = z - 32;
            }
        }
    } else {
        out = txt;
        for (char &z : out) {
            if (z >= 'A' && z <= 'Z') {
                z = z + 32;
            }
        }
    }
    cout << out << endl;
    return 0;
}
