import java.util.Scanner;  // Step 1: Import the Scanner class for input.

public class Main {  // Step 2: Define a public class named 'Main'.
    
    // Step 3: Define a method named 'swap' that takes two integer arrays as arguments.
    public static void swap(int[] a, int[] b) {
        int tmp;  // Step 4: Inside the 'swap' method, declare a temporary variable 'tmp'.
        tmp = a[0];  // Step 5: Assign the value at index 0 of 'a' to 'tmp'.
        a[0] = b[0];  // Step 6: Assign the value at index 0 of 'b' to the index 0 of 'a'.
        b[0] = tmp;  // Step 7: Assign the value stored in 'tmp' to the index 0 of 'b'.
    }

    public static void main(String[] args) {  // Step 8: In the 'main' method, declare the main entry point.
        Scanner scanner = new Scanner(System.in);  // Step 9: Create a Scanner object for input.
        
        while (true) {  // Step 10: Create an infinite loop using 'while(true)'.
            int[] a = new int[1];  // Step 11: Declare an array 'a' to hold one integer.
            int[] b = new int[1];  // Step 12: Declare an array 'b' to hold one integer.
            a[0] = scanner.nextInt();  // Step 13: Read an integer from the user and store it in 'a'.
            b[0] = scanner.nextInt();  // Step 14: Read an integer from the user and store it in 'b'.
            
            if (a[0] == 0 && b[0] == 0) break;  // Step 15: Check if both 'a' and 'b' are zero. If true, break the loop.
            if (b[0] < a[0]) swap(a, b);  // Step 16: Check if 'b' is less than 'a'. If true, call the 'swap' method to swap the values of 'a' and 'b'.
            System.out.println(a[0] + " " + b[0]);  // Step 17: Print the values of 'a' and 'b'.
        }
        
        scanner.close();  // Step 18: Close the scanner to prevent resource leaks.
    }
}

// <END-OF-CODE>
