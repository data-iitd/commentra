import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variables
        Scanner scanner = new Scanner(System.in);
        
        int N; // Number of elements in the array
        N = scanner.nextInt(); // Read the number of elements from the standard input

        int[] A = new int[N]; // Declare and initialize an array of size N
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt(); // Read each element of the array from the standard input
        }

        int minElement = A[0]; // Initialize minimum element variable with first element
        int maxElement = A[0]; // Initialize maximum element variable with first element

        // Find minimum and maximum elements in the array
        for (int i = 0; i < N; i++) {
            if (A[i] < minElement) { // If current element is smaller than the current minimum
                minElement = A[i]; // Update minimum element
            }
            if (A[i] > maxElement) { // If current element is larger than the current maximum
                maxElement = A[i]; // Update maximum element
            }
        }

        // Print the difference between maximum and minimum elements
        System.out.println("Difference between maximum and minimum elements: " + (maxElement - minElement));

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
