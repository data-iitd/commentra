import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Read the number of elements in each list
        int[] a = new int[n];  // Create the first list of integers
        int[] b = new int[n];  // Create the second list of integers
        int[] c = new int[n];  // Create the third list of integers

        // Read the first list of integers
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Read the second list of integers
        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextInt();
        }

        // Read the third list of integers
        for (int i = 0; i < n; i++) {
            c[i] = scanner.nextInt();
        }

        int x = 0;  // Initialize the sum of elements in list a
        int y = 0;  // Initialize the sum of elements in list b
        int z = 0;  // Initialize the sum of elements in list c

        // Calculate the sum of elements in each list
        for (int i : a) {
            x += i;  // Add each element of list a to x
        }
        for (int i : b) {
            y += i;  // Add each element of list b to y
        }
        for (int i : c) {
            z += i;  // Add each element of list c to z
        }

        // Print the absolute differences between the sums of the lists
        System.out.println(Math.abs(x - y));  // Print the absolute difference between the sums of lists a and b
        System.out.println(Math.abs(y - z));  // Print the absolute difference between the sums of lists b and c
    }
}
