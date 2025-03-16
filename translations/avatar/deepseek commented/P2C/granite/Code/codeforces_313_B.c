

#include <stdio.h>

int main() {
    char soz[100001];  // Declare a character array'soz' with a maximum length of 100001
    int a[100001] = {0};  // Declare an integer array 'a' with a length of 100001 and initialize all elements to 0
    int n;  // Declare an integer variable 'n'

    // Read a string from the user and store it in'soz'
    scanf("%s", soz);

    // Iterate over the string from index 1 to len(soz) - 1
    for (int i = 1; i < strlen(soz); i++) {
        a[i] = a[i - 1];  // Set 'a[i]' to the value of 'a[i - 1]'
        if (soz[i - 1] == soz[i]) {  // If the characters at positions 'i - 1' and 'i' are the same
            a[i] += 1;  // Increment 'a[i]' by 1
        }
    }

    // Read an integer from the user and store it in 'n'
    scanf("%d", &n);

    int arr[n];  // Declare an integer array 'arr' with a length of 'n'

    // Iterate 'n' times
    for (int i = 0; i < n; i++) {
        int m, l;  // Declare two integer variables'm' and 'l'

        // Read two integers from the user and store them in'm' and 'l'
        scanf("%d %d", &m, &l);

        arr[i] = a[l - 1] - a[m - 1];  // Calculate the difference 'a[l - 1] - a[m - 1]' and store it in 'arr[i]'
    }

    // Print each element in 'arr'
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
