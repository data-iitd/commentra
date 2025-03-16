import java.util.Arrays; // Import Arrays for sorting
import java.util.Scanner; // Import Scanner for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n = scanner.nextInt(); // Read the value of n
        int k = scanner.nextInt(); // Read the value of k
        int[] l = new int[n]; // Declare an array of size n

        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt(); // Read the elements of the array l
        }

        Arrays.sort(l); // Sort the array l in ascending order

        int ans = 0; // Initialize ans to 0
        for (int i = 0; i < k; i++) {
            ans += l[n - 1 - i]; // Sum the last k elements of the sorted array
        }
        
        System.out.println(ans); // Print the result
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
