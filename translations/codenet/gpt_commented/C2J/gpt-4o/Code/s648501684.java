import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the number of elements (n), the threshold (k), and the number of queries (q)
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        long q = scanner.nextLong();
        
        // Initialize an array to count occurrences of each element, with size n
        int[] arr = new int[(int) n + 1]; // +1 to accommodate 1-based indexing
        
        // Set all elements of the array to 0 (default for int array)
        
        // Process each query to count occurrences of the queried elements
        for (long i = 0; i < q; i++) {
            long temp = scanner.nextLong();
            arr[(int) temp] += 1; // Increment the count for the queried element
        }
        
        // Check each element from 1 to n to see if its count exceeds the threshold (q - k)
        for (long i = 1; i <= n; i++) {
            // If the count of the element is greater than (q - k), print "Yes"
            if (arr[(int) i] > (q - k)) {
                System.out.println("Yes");
            } else {
                // Otherwise, print "No"
                System.out.println("No");
            }
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
