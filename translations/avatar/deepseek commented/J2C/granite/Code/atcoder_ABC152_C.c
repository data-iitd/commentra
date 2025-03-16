

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] <= arr[0]) {
            sum++;
        }
    }
    printf("%d\n", sum);
    return 0;
}

