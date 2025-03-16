import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array
        int N = scanner.nextInt();

        // Declare and initialize an array of size N
        int[] A = new int[N];

        // Read each element of the array from the standard input
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Initialize minimum and maximum elements
        int minElement = A[0];
        int maxElement = A[0];

        // Find minimum and maximum elements in the array
        for (int i = 0; i < N; i++) {
            if (A[i] < minElement) {
                minElement = A[i]; // Update minimum element
            }
            if (A[i] > maxElement) {
                maxElement = A[i]; // Update maximum element
            }
        }

        // Print the difference between maximum and minimum elements
        System.out.println("Difference between maximum and minimum elements: " + (maxElement - minElement));
    }
}
