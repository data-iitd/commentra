#include <stdio.h>
#include <string.h>

int main() {
    char str[4][100]; // Declare and initialize an array of strings
    int i = -1;
    while (i != 3) { // Read input strings into the array
        i++;
        scanf("%s", str[i]);
    }
    int u = -1;
    i = -1;
    int yes = 0;
    while (u != 2) { // Compare characters in the array
        u++;
        i = -1;
        while (i != 2) {
            i++;
            if ((str[u][i] == str[u][i + 1] && (str[u + 1][i] == str[u][i] || str[u + 1][i + 1] == str[u][i])) || (str[u + 1][i] == str[u + 1][i + 1] && (str[u][i] == str[u + 1][i] || str[u][i + 1] == str[u + 1][i]))) {
                yes = 1;
                printf("YES\n");
                break;
            }
        }
        if (yes == 1) {
            break;
        }
    }
    if (yes == 0) {
        printf("NO\n");
    }
