

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Step 3: Create a Scanner object to read input from the user
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    // Step 4: Read the values of n, a, and b

    // Step 5: Create two ArrayList objects to store the lists of integers
    int *list1 = (int*)malloc(a * sizeof(int));
    int *list2 = (int*)malloc(b * sizeof(int));

    // Step 6: Read the elements of list1 and list2 from the user
    for (int i = 0; i < a; i++) {
        scanf("%d", &list1[i]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%d", &list2[i]);
    }

    // Step 7: Iterate through the range from 1 to n and print the appropriate list number
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < a; j++) {
            if (list1[j] == i + 1) {
                printf("1 ");
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("2 ");
        }
    }

    // Step 8: Free the memory allocated for the arrays
    free(list1);
    free(list2);

    return 0;
}
