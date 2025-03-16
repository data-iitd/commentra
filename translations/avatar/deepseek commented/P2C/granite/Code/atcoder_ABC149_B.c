

#include <stdio.h>

int main() {
    int cookies[3];
    scanf("%d %d %d", &cookies[0], &cookies[1], &cookies[2]);  // Taking input from the user and storing it in an array of integers
    int leftOver = cookies[0] - cookies[2];  // Calculating the difference between the first and third elements of the array
    int takahashi = leftOver > 0? leftOver : 0;  // Calculating the number of cookies Takahashi gets, ensuring it's not negative
    printf("%d %d\n", takahashi, leftOver > 0? cookies[1] : cookies[1] - abs(leftOver));  // Printing the result, including the number of cookies Takahashi gets and the number of cookies left for Aoki
    return 0;
}