
#include <stdio.h>
#include <math.h>

int main() {
    // Taking input of n and number of distinct numbers
    int n, num;
    scanf("%d %d", &n, &num);

    // Creating a set of distinct numbers
    int num_set[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &num_set[i]);
    }

    // Finding the powers of 2 that appear exactly twice in the binary representation of each number in num_set
    int two_times_set[num];
    int count = 0;
    for (int i = 0; i < num; i++) {
        int power_of_two = 0;
        int temp = num_set[i];
        while (temp % 2 == 0) {
            power_of_two++;
            temp /= 2;
        }
        if (power_of_two > 1) {
            printf("0\n");
            return 0;
        }
        two_times_set[count++] = power_of_two;
    }

    // If the size of two_times_set is not exactly 1, then the answer is 0
    if (count!= 1) {
        printf("0\n");
        return 0;
    }

    // Finding the least common multiple of all numbers in num_set
    int lcm = num_set[0];
    for (int i = 1; i < num; i++) {
        int temp = num_set[i];
        while (temp % lcm!= 0) {
            temp += lcm;
        }
        lcm = temp;
    }

    // Printing the answer
    printf("%d\n", (n - lcm / 2) / lcm + 1);

    return 0;
}
