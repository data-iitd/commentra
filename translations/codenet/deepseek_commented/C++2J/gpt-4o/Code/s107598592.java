import java.util.Scanner; // Import the Scanner class for input operations
import java.util.Arrays;  // Import the Arrays class for sorting

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int N = scanner.nextInt(); // Read the number of elements N from the standard input
        int[] X = new int[N]; // Declare an array X of size N to store the elements
        int[] Y = new int[N]; // Declare an array Y of size N to store the elements
        
        // Read N elements into array X and simultaneously copy them to array Y
        for (int i = 0; i < N; i++) {
            X[i] = scanner.nextInt();
            Y[i] = X[i];
        }
        
        // Sort the array Y in ascending order
        Arrays.sort(Y);
        
        // Calculate the median of the sorted array Y
        int y = Y[N / 2]; // The median is the middle element for odd N
        
        // Iterate through each element in array X and output the appropriate median value based on the comparison with y
        for (int i = 0; i < N; i++) {
            if (X[i] < y) {
                System.out.println(y); // If the element in X is less than the median, output the median
            } else {
                System.out.println(y - 1); // Otherwise, output the median minus one
            }
        }
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
