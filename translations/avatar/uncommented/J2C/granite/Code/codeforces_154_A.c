
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char arr[100001];
    fgets(arr, 100001, stdin);
    int N = strlen(arr);
    char input[3];
    int K = 0;
    fscanf(stdin, "%d", &K);
    int res = 0;
    for (int k = 0; k < K; k++) {
        fgets(input, 3, stdin);
        int a = 0;
        int b = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] == input[0]) {
                a++;
            } else if (arr[i] == input[1]) {
                b++;
            } else {
                res += fmin(a, b);
                a = b = 0;
            }
        }
        res += fmin(a, b);
    }
    printf("%d\n", res);
    return 0;
}
//END-OF-CODE