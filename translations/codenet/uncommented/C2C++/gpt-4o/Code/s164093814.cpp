#include <iostream>
#include <cstring>

#define M 1046527 /* your task */
#define L 14

char H[M][L]; /* Hash Table */

int getChar(char ch) {
    if (ch == 'A') return 1;
    else if (ch == 'C') return 2;
    else if (ch == 'G') return 3;
    else if (ch == 'T') return 4;
    return 0;
}

/* convert a string into an integer value */
long long getKey(const char str[]) {
    long long sum = 0, p = 1;
    for (int i = 0; i < strlen(str); i++) {
        sum += p * (getChar(str[i]));
        p *= 5;
    }
    return sum;
}

int h1(int key) { return key % M; }
int h2(int key) { return 1 + (key % (M - 1)); }

int find(const char str[]) {
    int i, hash, key;
    key = getKey(str);
    i = 0;
    while (true) {
        hash = (h1(key) + i * h2(key)) % M;
        if (strcmp(H[hash], str) == 0) return 1;
        else if (strlen(H[hash]) == 0) return 0;
        i++;
    }
    return 0;
}

int insert(const char str[]) {
    int i, hash, key;
    key = getKey(str);
    i = 0;
    while (true) {
        hash = (h1(key) + i * h2(key)) % M;
        if (strcmp(H[hash], str) == 0) return 1;
        else if (strlen(H[hash]) == 0) {
            strcpy(H[hash], str);
            return 0;
        }
        i++;
    }
    return 0;
}

int main() {
    int n;
    char str[L], com[9];
    for (int i = 0; i < M; i++) H[i][0] = '\0';

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> com >> str;

        if (com[0] == 'i') {
            insert(str);
        } else {
            if (find(str)) {
                std::cout << "yes\n";
            } else {
                std::cout << "no\n";
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
