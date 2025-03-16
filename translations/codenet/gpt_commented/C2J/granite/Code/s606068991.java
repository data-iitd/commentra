
import java.util.Scanner;

public class s606068991{
    // Function to print the array elements
    public static void white(int n, int A[]) {
        for(int i = 0; i < n - 1; i++) {
            System.out.print(A[i] + " "); // Print each element followed by a space
        }
        System.out.println(A[n - 1]); // Print the last element followed by a newline
    }

    // Function to perform insertion sort on the array
    public static void insertionsort(int n, int A[]) {
        int i, j, a;
        for(i = 0; i < n; i++) {
            for(j = 0; j < i; j++) {
                if(A[i] < A[j]) {
                    a = A[i]; 
                    A[i] = A[j]; 
                    A[j] = a; // Swap the elements
                }
            }
            white(n, A); // Print the current state of the array after each insertion
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i, n, A[] = new int[100]; // Declare variables for the number of elements and the array
        // Read the number of elements from user input
        n = scanner.nextInt();
        // Read the elements of the array from user input
        for (i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        // Call the insertion sort function to sort the array
        insertionsort(n, A);
        scanner.close(); // Close the scanner to release system resources
    }
}
