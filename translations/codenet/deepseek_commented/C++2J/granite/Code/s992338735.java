
import java.util.Scanner; // Import necessary classes and packages

public class s992338735{ // Start the main class
   public static void main(String[] args) { // Start the main function
      Scanner sc = new Scanner(System.in); // Create a scanner object
      while (sc.hasNextInt()) { // Read the number of elements (N)
         int N = sc.nextInt();
         if (N <= 0) break; // Exit the loop if N is not a positive integer
         int M = -1, m = 1001, addup = 0; // Initialize variables for maximum, minimum, sum, and index
         for (int i = 0; i < N; i++) { // Loop through each element and update the maximum, minimum, and sum
            int S = sc.nextInt();
            addup += S;
            if (S > M) M = S;
            if (S < m) m = S;
         }
         System.out.println((addup - M - m) / (N - 2)); // Calculate the average of the remaining numbers
      }
   } // End the loop and main function
} // End the main class
