import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Number of elements in the vector
        int N = scanner.nextInt();
        
        // Declaring two arrays X and Y of size N
        int[] X = new int[N];
        int[] Y = new int[N];
        
        // Filling the arrays X and Y with user input
        for (int i = 0; i < N; i++) {
            X[i] = scanner.nextInt(); // Taking input of X[i] from the user
            Y[i] = X[i]; // Assigning X[i] to Y[i]
        }
        
        // Sorting the array Y in ascending order
        Arrays.sort(Y);
        
        // Finding the middle element of sorted array Y
        int y = Y[N / 2];
        
        // Iterating through the array X and printing the middle element of Y based on the condition
        for (int i = 0; i < N; i++) {
            if (X[i] < Y[N / 2]) { // Checking if X[i] is less than the middle element of Y
                System.out.println(Y[N / 2]); // If true, print the middle element of Y
            } else { // If X[i] is greater than or equal to the middle element of Y
                System.out.println(Y[N / 2 - 1]); // Print the middle element of Y - 1
                break; // Exit the loop as we have found the required element
            }
        }
        
        // Closing the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
