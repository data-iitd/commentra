#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define IO_BUFFER_SIZE 1 * 1024 * 1024

int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int main() {
    // Read the initial height `h` and the number of attacks `n`
    int h = nextInt();
    int n = nextInt();

    // Initialize a variable to keep track of the total damage dealt
    int a = 0;

    // Read each attack's damage and accumulate the total damage
    for (int i = 0; i < n; i++) {
        a += nextInt();
    }

    // Check if the total damage is greater than or equal to the initial height
    if (h > a) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}
