#include <stdbool.h>
#include <stdio.h>

// Declare arrays and typedef for long long
int a[200000], tmpa[200000], light[200010] = {0};
typedef long long ll;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements (n) and the number of iterations (k)
        int n, k;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();

        // Input the initial values into the array 'a'
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        // Calculate the influence range for each element in 'a'
        for (int i = 0; i < n; i++) {
            int r, l;
            r = i - a[i]; // Calculate the left boundary
            l = i + a[i]; // Calculate the right boundary
            light[(r < 0 ? 0 : r)]++; // Increment the start of the influence range
            light[(l + 1 > n ? n + 1 : l + 1)]--; // Decrement the end of the influence range
        }

        // Perform k iterations to update the array 'a'
        for (int i = 0; i < k; i++) {
            int sum = 0;

            // Update 'a' based on the current influence ranges
            for (int j = 0; j < n; j++) {
                tmpa[j] = a[j]; // Store the current state of 'a' in 'tmpa'
                sum += light[j]; // Accumulate the influence
                a[j] = sum; // Update 'a' with the accumulated influence
            }

            // Update the influence ranges based on the new values in 'a'
            for (int j = 0; j < n; j++) {
                int r = j - tmpa[j]; // Calculate the left boundary for the previous state
                int l = j + tmpa[j]; // Calculate the right boundary for the previous state
                light[(r < 0 ? 0 : r)]--; // Decrement the start of the previous influence range
                light[(l + 1 > n ? n + 1 : l + 1)]++; // Increment the end of the previous influence range

                r = j - a[j]; // Calculate the new left boundary
                l = j + a[j]; // Calculate the new right boundary
                light[(r < 0 ? 0 : r)]++; // Increment the start of the new influence range
                light[(l + 1 > n ? n + 1 : l + 1)]--; // Decrement the end of the new influence range
            }

            // Check if all elements in 'a' are the same and equal to n
            boolean isSame = true;
            for (int j = 0; j < n - 1; j++) {
                if (a[j] != a[j + 1]) {
                    isSame = false; // Set flag to false if any elements differ
                    break;
                }
            }
            // If all elements are the same and equal to n, exit the loop
            if (isSame && a[0] == n) {
                break;
            }
        }

        // Output the final state of the array 'a'
        for (int j = 0; j < n; j++) {
            System.out.print(a[j]); // Print each element of 'a'
            System.out.print(j == n - 1 ? "\n" : " "); // Print a newline after the last element
        }
    }
}

