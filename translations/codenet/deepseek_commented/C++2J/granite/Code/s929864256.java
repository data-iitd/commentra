
import java.util.*; // Import necessary classes and packages

public class s929864256{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from standard input
        long a = sc.nextLong(); // Read two long integers from standard input
        long b = sc.nextLong();

        // Compute the maximum value among a+b, a-b, and a*b
        long max = Math.max(a+b, Math.max(a-b, a*b)); // Use the Math.max function to find the maximum value

        System.out.println(max); // Print the maximum value

        sc.close(); // Close the Scanner object to release system resources
    }
}
