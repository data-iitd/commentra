import java.util.Scanner;  // Import the Scanner class for input operations.

public class Main {  // Define the main class.
    public static void main(String[] args) {  // Define the main method which is the entry point of the program.
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input.
        int n = scanner.nextInt();  // Input the number of elements for the array.
        int[] a = new int[101];  // Declare an array 'a' of size 101.
        
        for (int i = 0; i < n; i++)  // Loop to take 'n' integer inputs and store them in the array 'a'.
            a[i] = scanner.nextInt();
        
        System.out.print(a[n - 1]);  // Output the last element of the array 'a'.
        
        for (int i = 1; i < n; i++)  // Loop to output the remaining elements of the array 'a' in reverse order.
            System.out.print(" " + a[n - i - 1]);
        
        System.out.println();  // End the line after outputting all the elements.
        scanner.close();  // Close the scanner to prevent resource leaks.
    }  // End of the main method.
}  // End of the main class.
