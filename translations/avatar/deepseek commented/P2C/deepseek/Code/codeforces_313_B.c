#include <stdio.h>
#include <string.h>

int main() {
    char soz[10000];
    int a[10001];
    int n, m, l;

    // Take a string input from the user
    scanf("%s", soz);

    // Initialize the list 'a' with zeros, with a length of strlen(soz) + 1
    int len = strlen(soz);
    for (int i = 0; i <= len; i++) {
        a[i] = 0;
    }

    // Iterate over the string from index 1 to len(soz) - 1
    for (int i = 1; i < len; i++) {
        a[i] = a[i - 1];
        if (soz[i - 1] == soz[i]) {
            a[i] += 1;
        }
    }

    // Take an integer input from the user
    scanf("%d", &n);

    // Initialize an empty list 'arr'
    int arr[n];

    // Iterate 'n' times
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m, &l);
        arr[i] = a[l - 1] - a[m - 1];
    }

    // Print each element in 'arr'
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
