#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    // Create a Scanner object for input and a PrintWriter for output
    int n;
    scanf("%d", &n);
    int square = n * n;
    int loop = square / n;
    int div = loop / 2;
    int i, j;
    int *odd = malloc(sizeof(int) * square);
    int *even = malloc(sizeof(int) * square);
    for (i = 0; i < square; i++) {
        odd[i] = i + 1;
        even[i] = i + 1;
    }
    for (i = 0; i < square; i++) {
        if (odd[i] % 2 == 0) {
            even[i] = 0;
        } else {
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (even[i] == 0) {
            even[i] = odd[i];
            odd[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {
        if (odd[i] == 0) {
            odd[i] = even[i];
            even[i] = 0;
        }
    }
    for (i = 0; i < square; i++) {