

import java.util.Scanner;

public class codeforces_306_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take two integers n and m as input
        int m = scanner.nextInt();

        int q = n / m;  // Calculate the quotient, which is the number of items each group will have
        int r = n % m;   // Calculate the remainder, which is the number of items that will be left over

        int[] a = new int[m];  // Initialize an array a of length m with each element set to q
        // This represents the initial distribution of items among the groups

        for (int i = 0; i < r; i++) {  // Loop for the number of remaining items r
            a[i] += 1;  // Increment the corresponding element in the array a by 1
            // Ensuring that the remaining items are distributed evenly
        }

        for (int i = 0; i < m; i++) {  // Loop to print the elements of the array a
            System.out.print(a[i] + " ");  // Print each element separated by a space
        }
    }
}

