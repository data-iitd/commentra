#include <stdio.h>
#include <math.h>

int div(int n);

int main() {
    int num;
    scanf("%d", &num);
    printf("%d:", num);

<<<<<<< HEAD
    while (num != 1) {
=======
    while(num != 1) {
>>>>>>> 98c87cb78a (data updated)
        printf(" %d", div(num));
        num = num / div(num);
    }
    printf("\n");
    return 0;
}

int div(int n) {
<<<<<<< HEAD
    if (n % 2 == 0) return 2;
    int s = (int)sqrt(n);
    for (int i = 3; i <= s; i += 2) {
        if (n % i == 0) return i;
=======
    if(n % 2 == 0) return 2;
    int s = (int)sqrt(n);
    for(int i = 3; i <= s; i += 2) {
        if(n % i == 0) return i;
>>>>>>> 98c87cb78a (data updated)
    }

    return n;
}

// <END-OF-CODE>
