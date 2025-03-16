#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    // Input the number of elements (n) and the position index (k)

    char v[100]; // Assuming the maximum length of v is 100
    scanf("%s", v);
    // Input the string v

    const char *d[] = {"LEFT", "RIGHT"};
    // Define an array containing the directions "LEFT" and "RIGHT"

    int f = (k - 1 < n - k);
    // Determine the boolean value of f based on the comparison between k-1 and n-k

    int m = (k - 1 < n - k) ? (k - 1) : (n - k);
    // Assign m as the minimum of k-1 and n-k

    char a[200][20]; // Assuming a maximum of 200 actions, each up to 20 characters
    int index = 0; // Initialize an index for the actions array

    for (int i = 0; i < m; i++) {
        strcpy(a[index++], d[!f]);
        // Append the opposite direction to a based on the value of f
    }

    for (int i = (f ? 0 : strlen(v) - 1); (f ? i < strlen(v) : i >= 0); i += (f ? 1 : -1)) {
        sprintf(a[index++], "PRINT %c", v[i]);
        // Append "PRINT" and the current character
        strcpy(a[index++], d[f]);
        // Append the direction f
    }

    for (int i = 0; i < index - 1; i++) {
        printf("%s\n", a[i]);
        // Print all elements in a except the last one, separated by newlines
    }

    return 0;
}
// <END-OF-CODE>
