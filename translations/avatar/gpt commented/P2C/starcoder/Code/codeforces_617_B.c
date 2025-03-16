#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[100000];
    scanf("%s", a);
    int count = 0;
    int i = 0;
    while (a[i]!= '\0') {
        if (a[i] == '1') {
            count++;
        }
        i++;
    }
    if (count == 0) {
        printf("0\n");
    } else {
        int count0 = 0;
        int j = 0;
        while (a[j]!= '\0') {
            if (a[j] == '0') {
                count0++;
            }
            j++;
        }
        printf("%d\n", count0 + 1);
    }
    return 0;
}

