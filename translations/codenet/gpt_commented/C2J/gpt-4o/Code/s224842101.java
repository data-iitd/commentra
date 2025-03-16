import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for loop index, input values, and a product variable
        int a, b, s;
        // Array to count occurrences of each number (1 to 4)
        int[] count = new int[4];

        // Initialize the count array to zero
        for (int i = 0; i < 4; i++) 
            count[i] = 0;

        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Read pairs of integers and update their counts
        for (int i = 0; i < 3; i++) {
            // Read two integers from input
            a = scanner.nextInt();
            b = scanner.nextInt();
            // Increment the count for each integer read
            count[a - 1]++;
            count[b - 1]++;
        }

        // Initialize the product variable
        s = 1;
        // Calculate the product of counts
        for (int i = 0; i < 4; i++) 
            s *= count[i];

        // Check if the product equals 4, indicating each number appears at least once
        if (s == 4) 
            System.out.println("YES"); // Output YES if all numbers are present
        else 
            System.out.println("NO");  // Output NO if any number is missing

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
