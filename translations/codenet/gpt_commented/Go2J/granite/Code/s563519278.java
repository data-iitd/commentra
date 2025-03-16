
import java.util.Scanner;

public class s563519278{
    public static void main(String[] args) {
        // Declare a variable N to hold the number of elements
        int N;
        // Read the integer N from standard input
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();

        // Create a slice v of size N to hold counts of occurrences
        int[] v = new int[N];
        int a;

        // Loop through the range from 1 to N-1 to read N-1 integers
        for (int i = 1; i < N; i++) {
            // Read the next integer from input
            a = scanner.nextInt();
            // Increment the count at the index corresponding to the value read (adjusted for 0-based index)
            v[a-1]++;
        }

        // Loop through the slice v to print the counts of occurrences
        for (int e : v) {
            // Print each count to the output
            System.out.println(e);
        }
    }
}
