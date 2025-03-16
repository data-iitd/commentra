
#include <iostream>
#include <string>

using namespace std;

int main() {
    string txt;
    int cu = 0, cl = 0;

    getline(cin, txt);  // Taking input from the user and storing it in the variable `txt`.

    for (int i = 0; i < txt.length(); i++) {
        if (txt[i] >= 'a' && txt[i] <= 'z') {
            cl++;  // Incrementing the counter for lowercase letters if `txt[i]` is lowercase.
        } else {
            cu++;  // Incrementing the counter for uppercase letters.
        }
    }

    string out;

    if (cu > cl) {
        out = txt;
        for (int i = 0; i < txt.length(); i++) {
            out[i] = toupper(out[i]);  // Convert each character in `txt` to uppercase and store it in `out`.
        }
    } else {
        out = txt;
        for (int i = 0; i < txt.length(); i++) {
            out[i] = tolower(out[i]);  // Convert each character in `txt` to lowercase and store it in `out`.
        }
    }

    cout << out << endl;  // Printing the result stored in `out`.

    return 0;
}
