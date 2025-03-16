

#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    // Input the number of elements (n) and the position index (k)

    char v[1000];
    scanf("%s", v);
    // Input the string v

    char d[2][10] = { "LEFT", "RIGHT" };
    // Define a 2D array d containing the directions "LEFT" and "RIGHT"

    int f = k - 1 < n - k;
    // Determine the boolean value of f based on the comparison between k-1 and n-k

    int m = f? k - 1 : n - k;
    // Assign m as the minimum of k-1 and n-k based on the value of f

    char a[2000][10];
    int index = 0;
    // Initialize an empty array a to store the sequence of actions and an index variable

    for (int i = 0; i < m; i++) {
        strcpy(a[index], d[!f]);
        // Append the opposite direction to a based on the value of f

        index++;
    }

    for (int i = strlen(v) - 1; i >= 0; i -= 2 * f - 1) {
        strcpy(a[index], "PRINT ");
        // Append "PRINT" to a

        strcat(a[index], &v[i]);
        // Append the current character to a

        index++;

        strcpy(a[index], d[f]);
        // Append the direction f to a

        index++;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%s\n", a[i]);
        // Print all elements in a except the last one, separated by newlines
    }

    return 0;
}
