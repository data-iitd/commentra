#include <stdio.h>

int main() {
    int n, levels, sum = 0, sum2 = 0, sum3 = 0, count = 0;
    
    scanf("%d", &n);
    scanf("%d", &levels);
    
    int arr[levels];
    for (int i = 0; i < levels; i++) {
        scanf("%d", &arr[i]);
    }
    
    int level2;
    scanf("%d", &level2);
    int level3 = levels + level2;
    
    int arr2[level3];
    for (int i = 0; i < levels; i++) {
        arr2[i] = arr[i];
    }
    for (int i = levels; i < level3; i++) {
        scanf("%d", &arr2[i]);
    }
    
    int arr3[n];
    for (int i = 0; i < n; i++) {
        arr3[i] = i + 1; // ++j is equivalent to i + 1 in this context
    }
    
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < level3; x++) {
            if (arr3[i] == arr2[x]) {
                count++;
                break;
            }
        }
    }
    
    if (count == n) {
        printf("I become the guy.\n");
    } else {
        printf("Oh, my keyboard!\n");
    }
    
    return 0;
}

// <END-OF-CODE>
