

import java.util.Scanner;

public class codeforces_519_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Read the number of elements in each list
        int[] a = new int[n];  // Create an array to store the elements of list a
        int[] b = new int[n];  // Create an array to store the elements of list b
        int[] c = new int[n];  // Create an array to store the elements of list c

        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();  // Read the elements of list a
        }
        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextInt();  // Read the elements of list b
        }
        for (int i = 0; i < n; i++) {
            c[i] = scanner.nextInt();  // Read the elements of list c
        }

        int x = 0;  // Initialize the sum of elements in list a
        int y = 0;  // Initialize the sum of elements in list b
        int z = 0;  // Initialize the sum of elements in list c

        // Calculate the sum of elements in each list
        for (int i = 0; i < n; i++) {
            x += a[i];  // Add each element of list a to x
        }
        for (int i = 0; i < n; i++) {
            y += b[i];  // Add each element of list b to y
        }
        for (int i = 0; i < n; i++) {
            z += c[i];  // Add each element of list c to z
        }

        // Print the absolute differences between the sums of the lists
        System.out.println(Math.abs(x - y));  // Print the absolute difference between the sums of lists a and b
        System.out.println(Math.abs(y - z));  // Print the absolute difference between the sums of lists b and c
    }
}
