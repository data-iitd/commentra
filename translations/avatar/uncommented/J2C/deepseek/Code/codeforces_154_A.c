#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char arr[100001];
    int N, K, res = 0;
    char input[3];
    int a, b;

    scanf("%s", arr);
    N = strlen(arr);
    scanf("%d", &K);

    for (int k = 0; k < K; k++) {
        scanf("%s", input);
        a = b = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] == input[0]) {
                a++;
            } else if (arr[i] == input[1]) {
                b++;
            } else {
                res += (a < b) ? a : b;
                a = b = 0;
            }
        }
        res += (a < b) ? a : b;
    }

    printf("%d\n", res);
    return 0;
}
