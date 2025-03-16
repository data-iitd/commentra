#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[100], str2[100], temp[100];
    int i, j = 0, t;

    cin.getline(str1, 100);
    cin.getline(str2, 100);

    i = strlen(str1);
    t = i - 1;

    if (strlen(str1) != strlen(str2)) {
        cout << "NO" << endl;
    } else {
        while (str1[j] != '\0') {
            temp[j] = str1[t];
            j++;
            t--;
        }
        temp[j] = '\0'; // Null-terminate the reversed string

        t = 0;
        i = 0;
        while (temp[i] != '\0') {
            if (temp[i] == str2[i]) {
                t++;
            }
            i++;
        }

        if (strlen(str2) == t) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

// <END-OF-CODE>
