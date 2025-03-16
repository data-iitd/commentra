#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
=======
>>>>>>> 98c87cb78a (data updated)

int main(int argc, char *args[]) {
    int N, D, X;
    int num_of_chocolate;
    int counter;
    int days;
    int A[101];
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    scanf("%d %d %d", &N, &D, &X);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    num_of_chocolate = 0;
    for (int i = 0; i < N; i++) {
        days = 0;
        counter = 0;
        for (int j = 0;; j++) {
            days = j * A[i] + 1;
            if (days <= D) {
                counter++;
            } else {
                break;
            }
        }
        num_of_chocolate += counter;
    }
    num_of_chocolate += X;

    printf("%d\n", num_of_chocolate);
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
