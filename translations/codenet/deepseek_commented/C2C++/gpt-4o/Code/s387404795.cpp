#include <iostream>
#include <cstring>

int main() {
    char str[201], tmp[101];
    char p[101];
    int slen, plen;
    int flag = 0;

    // Read two strings from the user
    std::cin >> str >> p;

    // Duplicate and concatenate the string
    strcpy(tmp, str);
    strcat(str, tmp);

    // Calculate the lengths of the strings
    slen = strlen(str);
    plen = strlen(p);

    // Check if the pattern exists in the concatenated string
    for (int i = 0; i <= slen - plen; i++) {
        if (strncmp(&str[i], p, plen) == 0) {
            flag = 1;
            break; // Exit the loop if found
        }
    }

    // Output the result
    if (flag) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;

    return 0;
}

// <END-OF-CODE>
