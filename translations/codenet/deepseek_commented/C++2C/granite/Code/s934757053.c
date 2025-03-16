
#include <stdio.h>

int main(){
    int A, B;
    int ans=0;
    int out = 1; // Initialize out to 1

    scanf("%d %d", &A, &B); // Read two integers A and B from the standard input

    while(out<B){ // Continue the loop as long as out is less than B
        out--; // Decrement out by 1
        out += A; // Increment out by A
        ans++; // Increment ans by 1
    }
    printf("%d\n", ans); // Print the value of ans to the standard output
    return 0;
}
