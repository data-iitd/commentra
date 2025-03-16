
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int arr[2];
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d %d", &arr[0], &arr[1]);
    int tap = 0;
    int consent = 1;
    while (consent < arr[1]) {
        consent = consent + arr[0] - 1;
        tap++;
    }
    printf("%d\n", tap);
    return 0;
}
