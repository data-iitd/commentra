#include <stdio.h>

int main() {
    int m, f, r;
    while (scanf("%d %d %d", &m, &f, &r) == 3 && (m != -1 || f != -1 || r != -1)) { // 1. The program reads three integers: m, f, and r from the standard input.
        if (m == -1 || f == -1) printf("F"); // 2. It then checks if any of these integers are -1, in which case it outputs "F".
        else if (m + f >= 80) printf("A"); // 3. If not, it checks if the sum of m and f is 80 or more, in which case it outputs "A".
        else if (m + f >= 65) printf("B"); // 4. If not, it checks if the sum of m and f is 65 or more, in which case it outputs "B".
        else if (m + f >= 50 || r >= 50) printf("C"); // 5. If not, it checks if the sum of m and f is 50 or more, or if r is 50 or more, in which case it outputs "C".
        else if (m + f >= 30) printf("D"); // 6. If not, it checks if the sum of m and f is 30 or more, in which case it outputs "D".
        else printf("F"); // 7. If none of the above conditions are met, it outputs "F".
        printf("\n"); // 8. The program continues to read and process new sets of m, f, and r values until all three are -1.
    }

    return 0;
<<<<<<< HEAD
} // <END-OF-CODE>
=======
}

// <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
