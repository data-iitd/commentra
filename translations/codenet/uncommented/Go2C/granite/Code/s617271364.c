
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1024];
    fgets(input, 1024, stdin);
    int N, A, B, C;
    sscanf(input, "%d %d %d %d", &N, &A, &B, &C);

    int arr[N];
    for (int i = 0; i < N; i++) {
        fgets(input, 1024, stdin);
        sscanf(input, "%d", &arr[i]);
    }

    int dp[N][4];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            dp[i][j] = 0;
        }
    }

    int ans = 10000;
    int ss = A + B + C;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    int cost = 0;
                    int AA = 0, BB = 0, CC = 0;
                    for (int m = 0; m < N; m++) {
                        if (m == i && j == 1) {
                            AA += arr[m];
                        } else if (m == i && k == 1) {
                            AA += arr[m];
                        } else if (m == i && l == 1) {
                            AA += arr[m];
                        } else if (m == i && j == 2) {
                            BB += arr[m];
                        } else if (m == i && k == 2) {
                            BB += arr[m];
                        } else if (m == i && l == 2) {
                            BB += arr[m];
                        } else if (m == i && j == 3) {
                            CC += arr[m];
                        } else if (m == i && k == 3) {
                            CC += arr[m];
                        } else if (m == i && l == 3) {
                            CC += arr[m];
                        } else {
                            if (j == 1) {
                                cost += arr[m];
                            } else if (k == 1) {
                                cost += arr[m];
                            } else if (l == 1) {
                                cost += arr[m];
                            } else if (j == 2) {
                                cost += arr[m];
                            } else if (k == 2) {
                                cost += arr[m];
                            } else if (l == 2) {
                                cost += arr[m];
                            } else if (j == 3) {
                                cost += arr[m];
                            } else if (k == 3) {
                                cost += arr[m];
                            } else if (l == 3) {
                                cost += arr[m];
                            }
                        }
                    }
                    cost += abs(A - AA) + abs(B - BB) + abs(C - CC);
                    if (cost < ans) {
                        ans = cost;
                    }
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
