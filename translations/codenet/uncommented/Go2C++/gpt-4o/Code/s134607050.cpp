#include <iostream>
#include <string>

using namespace std;

// S....M....E
// R...RL...LR
tuple<int, int, int> searchRange(string &text, int start, int limit) {
    int middle = -1;

    for (int i = start; i < limit; i++) {
        if (text[i] != 'R') {
            middle = i;
            break;
        }
    }

    int end = limit;

    for (int i = middle; i < limit; i++) {
        if (text[i] != 'L') {
            end = i;
            break;
        }
    }

    return make_tuple(start, middle, end);
}

void answer() {
    string text;
    cin >> text;
    int limit = text.length();

    int start = 0;
    int middle = 0;
    int end = 0;
    bool firstPrinted = false;

    while (end < limit) {
        tie(start, middle, end) = searchRange(text, start, limit);
        int len1 = middle - start;
        int len2 = end - middle;

        for (int i = start; i < middle - 1; i++) {
            if (firstPrinted) {
                cout << " ";
            }
            cout << "0";
            firstPrinted = true;
        }

        int count1 = (len1 + 1) / 2 + len2 / 2;
        int count2 = len1 / 2 + (len2 + 1) / 2;

        if (firstPrinted) {
            cout << " ";
        }
        cout << count1 << " " << count2;
        firstPrinted = true;

        for (int i = middle + 1; i < end; i++) {
            if (firstPrinted) {
                cout << " ";
            }
            cout << "0";
            firstPrinted = true;
        }
        start = end;
        firstPrinted = true;
    }
    cout << endl;
}

int main() {
    answer();
    return 0;
}

// <END-OF-CODE>
