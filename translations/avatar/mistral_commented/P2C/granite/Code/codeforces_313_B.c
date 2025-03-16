
#include <stdio.h>
#include <string.h>

int main() {
    // Take input string'soz' from the user
    char soz[100001];
    scanf("%s", soz);

    // Initialize an array 'a' of size'strlen(soz)+1' with zeros
    int a[strlen(soz) + 1] = {0};

    // Iterate through the string'soz' starting from index 1
    for (int i = 1; i < strlen(soz); i++) {
        // Assign the value of the previous index to the current index
        a[i] = a[i - 1];

        // If the current character is same as the previous character, increment the count
        if (soz[i - 1] == soz[i]) {
            a[i] += 1;
        }
    }

    // Take the number of test cases 'n' as input
    int n;
    scanf("%d", &n);

    // Initialize an empty list 'arr' to store the differences
    int arr[n];

    // Iterate through the test cases
    for (int i = 0; i < n; i++) {
        // Take two integers'm' and 'l' as input, separated by a space
        int m, l;
        scanf("%d %d", &m, &l);

        // Calculate the difference between the count at index 'l' and index'm'
        arr[i] = a[l - 1] - a[m - 1];
    }

    // Iterate through the list 'arr' and print each difference
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
