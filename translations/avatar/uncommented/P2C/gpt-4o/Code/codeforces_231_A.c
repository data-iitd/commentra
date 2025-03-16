#include <stdio.h>

int main() {
    int n, c = 0;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int l1[100]; // Assuming a maximum of 100 integers in each line
        int sum = 0, num, count = 0;

        // Read integers until a newline is encountered
        while (scanf("%d", &num) == 1) {
            l1[count++] = num;
            if (getchar() == '\n') break; // Break on newline
        }

        // Calculate the sum of the integers
        for (int j = 0; j < count; j++) {
            sum += l1[j];
        }

        if (sum > 1) {
            c++;
        }
    }

    printf("%d\n", c);
    return 0;
}

// <END-OF-CODE>
