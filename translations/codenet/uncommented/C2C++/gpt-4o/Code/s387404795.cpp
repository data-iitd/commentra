#include <iostream>
#include <cstring>

int main() {
    char str[201], tmp[101];
    char p[101];
    int slen, plen;
    bool flag = false;

    std::cin >> str >> p;

    strcpy(tmp, str);
    strcat(str, tmp);

    slen = strlen(str);
    plen = strlen(p);

    for (int i = 0; i <= slen - plen; i++) {
        if (strncmp(&str[i], p, plen) == 0) {
            flag = true;
            break; // Exit the loop once a match is found
        }
    }

    if (flag) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;

    return 0;
}

// <END-OF-CODE>
