import java.util.Scanner; // Step 1: Import the Scanner class for input.

public class Main { // Step 2: Define the main class.
    public static void main(String[] args) { // Step 3: Define the main method.
        int i, j; // Step 4: Declare integer variables i and j.
        int[] x = new int[10000]; // Step 5: Declare an array x with a size of 10000.

        for (i = 0; i < 10000; i++) { // Step 6: Initialize the array x with zeros.
            x[i] = 0;
        }
        i = 0; // Step 7: Initialize i to 0.
        Scanner scanner = new Scanner(System.in); // Step 8: Create a Scanner object for input.
        x[i] = scanner.nextInt(); // Step 9: Read an integer from the input and store it in x[0].

        while (x[i] != 0) { // Step 10: Use a while loop to read integers into the array x until a zero is entered.
            i++;
            x[i] = scanner.nextInt();
        }

        for (j = 0; j < i; j++) { // Step 11: Use a for loop to print the integers stored in the array x.
            System.out.printf("Case %d: %d\n", j + 1, x[j]);
        }

        scanner.close(); // Step 12: Close the scanner to prevent resource leaks.
    } // End of main method.
} // End of class.
