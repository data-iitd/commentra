#include <stdio.h>

int main() {
    int li[1000]; // Assuming a maximum size of 1000 for the array
    int ind = 0;

    for (int i = 1; i < 371; i++) {
        int p = i, q = i;
        int count = 0;

        // Count the number of digits in i
        while (p != 0) {
            p /= 10;
            count++;
        }

        if (count == 1) {
            li[ind++] = i;
        }
        if (count == 2) {
            int temp[2]; // Temporary array for two digits
            int temp_index = 0;

            while (q != 0) {
                int x = q % 10;
                q /= 10;
                temp[temp_index++] = x;
            }
            // Append the digits in reverse order
            for (int j = temp_index - 1; j >= 0; j--) {
                li[ind++] = temp[j];
            }
        }
        if (count == 3) {
            int temp[3]; // Temporary array for three digits
            int temp_index = 0;

            while (q != 0) {
                int x = q % 10;
                q /= 10;
                temp[temp_index++] = x;
            }
            // Append the digits in reverse order
            for (int j = temp_index - 1; j >= 0; j--) {
                li[ind++] = temp[j];
            }
        }
    }

    // Remove the last two elements
    ind -= 2;

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d\n", li[n - 1]);

    return 0;
}
