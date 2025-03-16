#include <stdio.h>

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int a[] = new int[1000];
        int n, i, j, d = 0;

        // Read the number of elements in the array
        scanf("%d", &n);

        // Read the elements of the array
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        // Bubble sort algorithm to sort the array in ascending order
        for (i = 0; i < n; i++) {
            for (j = n - 1; j >= i + 1; j--) {
                if (a[j] < a[j - 1]) {
                    // Swap the elements if they are in the wrong order
                    int temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                    // Increment the swap counter
                    d++;
                }
            }
        }

        // Print the sorted array
        System.out.print(a[0]);
        for (i = 1; i < n; i++) {
            System.out.print(" " + a[i]);
        }
        System.out.println();

        // Print the number of swaps made during the sorting process
        System.out.println(d);
    }
}

