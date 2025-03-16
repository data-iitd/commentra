#include <stdio.h>
#include <string.h>

int main() {
    char soz[100001];  // Assuming the maximum length of the input string is 100000
    scanf("%s", soz);  // Take a string input from the user

    int len = strlen(soz);
    int a[len + 1];  // Initialize an array 'a' with zeros, with a length of len(soz) + 1
    memset(a, 0, sizeof(a));  // Set all elements of 'a' to 0

    // Iterate over the string from index 1 to len(soz) - 1
    for (int i = 1; i < len; i++) {
        a[i] = a[i - 1];  // Set 'a[i]' to the value of 'a[i - 1]'
        if (soz[i - 1] == soz[i]) {  // If the characters at positions 'i - 1' and 'i' are the same
            a[i] += 1;  // Increment 'a[i]' by 1
        }
    }

    int n;  // Declare an integer 'n'
    scanf("%d", &n);  // Take an integer input from the user
    int arr[n];  // Initialize an array 'arr' to store results

    // Iterate 'n' times
    for (int i = 0; i < n; i++) {
        int m, l;  // Declare two integers 'm' and 'l'
        scanf("%d %d", &m, &l);  // Take two inputs 'm' and 'l'
        arr[i] = a[l - 1] - a[m - 1];  // Calculate the difference and store it in 'arr'
    }

    // Print each element in 'arr'
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;  // Return 0 to indicate successful completion
}

// <END-OF-CODE>
