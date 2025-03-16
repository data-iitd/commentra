
#include <stdio.h>
#include <stdbool.h>
#define MAX 100008

int main() {
    int X;
    scanf("%d", &X);
    bool prime[MAX] = {false};
    for (int i = 0; i < MAX; i++) {
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;
    for (int i = 4; i < MAX; i += 2) {
        prime[i] = false;
    }
    for (int i = 3; i * i <= MAX; i += 2) {
        if (prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = X; i < MAX; i++) {
        if (prime[i]) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
//END-OF-CODE