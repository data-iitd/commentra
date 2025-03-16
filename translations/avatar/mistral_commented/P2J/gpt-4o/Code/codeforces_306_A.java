import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read the input from the user
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Calculate the quotient and remainder of n divided by m
        int q = n / m;
        int r = n % m;

        // Initialize the array with q repeated m times
        int[] a = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = q;
        }

        // Increment the corresponding elements in the a array for the remaining elements
        for (int i = 0; i < r; i++) {
            a[i]++;
        }

        // Print each element of the a array separated by a space
        for (int i = 0; i < m; i++) {
            System.out.print(a[i] + " ");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
