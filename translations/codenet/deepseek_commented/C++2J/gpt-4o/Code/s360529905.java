import java.util.Arrays; // Import the Arrays class for sorting and other array utilities
import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int N = scanner.nextInt(); // Read the number of elements from the user
        int[] a = new int[N]; // Declare array a
        int[] b = new int[N]; // Declare array b

        for (int i = 0; i < N; i++) { // Loop to read elements into array a and copy them to array b
            a[i] = scanner.nextInt(); // Read an element into array a
            b[i] = a[i]; // Copy the element from array a to array b
        }

        Arrays.sort(b); // Sort array b

        int frontHalf = b[N / 2 - 1]; // Calculate the first half's middle value
        int backHalf = b[N / 2]; // Calculate the second half's middle value

        for (int i = 0; i < N; i++) { // Loop to compare each element of array a
            if (a[i] < backHalf) // Check if the element is less than the second middle value
                System.out.println(backHalf); // Print the second middle value
            else
                System.out.println(frontHalf); // Print the first middle value
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
