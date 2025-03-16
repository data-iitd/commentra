import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable N to hold the number of elements
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Initialize an array v of size N to hold counts of occurrences
        int[] v = new int[N];

        // Loop through the range from 1 to N-1 to read N-1 integers
        for (int i = 1; i < N; i++) {
            int a = scanner.nextInt();
            // Increment the count at the index corresponding to the value read (adjusted for 0-based index)
            v[a - 1]++;
        }

        // Loop through the array v to print the counts of occurrences
        for (int e : v) {
            System.out.println(e);
        }

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
