
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int S[n], R[n], H[n], C[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &S[i], &R[i], &H[i], &C[i]);
    }

    int outdated[n][4];
    int outdated_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (S[i] < S[j] && R[i] < R[j] && H[i] < H[j]) {
                outdated[outdated_count][0] = S[i];
                outdated[outdated_count][1] = R[i];
                outdated[outdated_count][2] = H[i];
                outdated[outdated_count][3] = C[i];
                outdated_count++;
            }
        }
    }

    int minimum_cost = 100000;
    int input_number = 0;
    for (int i = 0; i < n; i++) {
        int cost = C[i];
        int is_outdated = 0;
        for (int j = 0; j < outdated_count; j++) {
            if (S[i] == outdated[j][0] && R[i] == outdated[j][1] && H[i] == outdated[j][2]) {
                is_outdated = 1;
                break;
            }
        }
        if (!is_outdated && cost < minimum_cost) {
            minimum_cost = cost;
            input_number = i + 1;
        }
    }

    printf("%d\n", input_number);

    return 0;
}
