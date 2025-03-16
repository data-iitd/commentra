
import java.util.*; // For efficient I/O operations

public class s144285625{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a scanner for input
        int n = sc.nextInt(); // Read the number of elements
        int[] ar = new int[3*n]; // Create an array of size 3*n
        for (int i = 0; i < 3*n; i++) {
            ar[i] = sc.nextInt(); // Populate the array with integers from input
        }
        Arrays.sort(ar); // Sort the array
        int sum = 0; // Initialize sum to 0
        for (int i = 0; i < n; i++) {
            sum += ar[3*n-(i+1)*2]; // Calculate the sum of the last n elements, skipping every second element
        }
        System.out.println(sum); // Print the sum
        sc.close(); // Close the scanner
    }
}

