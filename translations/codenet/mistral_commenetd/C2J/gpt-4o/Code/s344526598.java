import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int i = 0;
        int[] x = new int[10000];

        // Initialize array x with zeros
        for (i = 0; i < 10000; i++) {
            x[i] = 0;
            // Comment explaining what the loop does
            // This loop initializes all elements of the array x with zero
        }

        Scanner scanner = new Scanner(System.in);
        // Read the first integer input and store it in the array x at index i
        x[i] = scanner.nextInt();
        // Comment explaining what the line does
        // Read the first integer input and store it in the array x

        // Read remaining integers and store them in the array x
        while (x[i] != 0) {
            i++;
            x[i] = scanner.nextInt();
            // Comment explaining what the loop does
            // This loop reads and stores the remaining integers in the array x
        }

        // Print the results
        for (int j = 0; j < i; j++) {
            System.out.printf("Case %d: %d\n", j + 1, x[j]);
            // Comment explaining what the loop does
            // This loop prints the results for each input integer
        }

        // Close the scanner
        scanner.close();

        // Signal successful termination of the program
    }
}
// <END-OF-CODE>
