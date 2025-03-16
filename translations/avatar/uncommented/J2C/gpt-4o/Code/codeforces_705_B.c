#include <stdio.h>

void solve() {
    int t;
    scanf("%d", &t);
    int arr[t];
    for (int i = 0; i < t; i++) {
        scanf("%d", &arr[i]);
    }
    
    int prevWinner = 0;
    for (int i = 0; i < t; i++) {
        if (arr[i] == 1) {
            if (prevWinner == 0) {
                prevWinner = 2;
            }
        }
        if (prevWinner == 2 || prevWinner == 0) {
            if ((arr[i] - 1) % 2 == 0) {
                printf("2\n");
                prevWinner = 2;
            } else {
                printf("1\n");
                prevWinner = 1;
            }
        } else {
            if ((arr[i] - 1) % 2 == 0) {
                printf("1\n");
                prevWinner = 1;
            } else {
                printf("2\n");
                prevWinner = 2;
            }
        }
    }
}

int main() {
    int t = 1; // Assuming we want to run the solve function once
    while (t-- > 0) {
        solve();
    }
    return 0;
}

// <END-OF-CODE>
