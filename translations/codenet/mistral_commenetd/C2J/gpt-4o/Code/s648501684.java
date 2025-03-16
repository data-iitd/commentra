import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long n = scanner.nextLong(); // Read the value of n
        long k = scanner.nextLong(); // Read the value of k
        long q = scanner.nextLong(); // Read the value of q

        int[] arr = new int[(int) n + 1]; // Declare an integer array arr of size n + 1

        // Initialize the array arr with zeros
        for (long i = 0; i <= n; i++) {
            arr[(int) i] = 0;
        }

        // Read q query values and increment the corresponding index in the array arr
        for (long i = 0; i < q; i++) {
            long temp = scanner.nextLong();
            arr[(int) temp] += 1;
        }

        // Check each index i in the array arr and print "Yes" or "No"
        for (long i = 1; i <= n; i++) {
            if (arr[(int) i] > (q - k)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
