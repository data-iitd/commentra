#include <stdio.h>
#include <stdlib.h>

void cutRibbon() {
    int arr[4];
    for (int i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }
    
    int length = arr[0];
    // Sort the array arr[1] to arr[3]
    int temp;
    for (int i = 1; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    if (length % arr[1] == 0) {
        printf("%d\n", length / arr[1]);
        return;
    }

    int ans = 0;
    if (arr[1] == arr[2]) {
        int k = 0;
        for (int i = 0; i <= length / arr[3]; i++) {
            int check = length - i * arr[3];
            if (check >= 0 && check % arr[1] == 0) {
                k = check / arr[1];
                ans = (ans > k + i) ? ans : (k + i);
            }
        }
    } else {
        int k = 0;
        for (int i = 0; i <= length / arr[3]; i++) {
            for (int j = 0; j <= length / arr[2]; j++) {
                int check = length - i * arr[3] - j * arr[2];
                if (check >= 0 && check % arr[1] == 0) {
                    k = check / arr[1];
                    ans = (ans > k + i + j) ? ans : (k + i + j);
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    cutRibbon();
    return 0;
}

// <END-OF-CODE>
