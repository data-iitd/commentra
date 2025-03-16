import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read a line of space-separated integers and split it into an array of strings
        String[] input = scanner.nextLine().split(" ");
        
        // Iterate over the array of strings, converting each to an integer
        for (int index = 0; index < input.length; index++) {
            int value = Integer.parseInt(input[index]);
            // Check if the current value is equal to zero
            if (value == 0) {
                // Print the index of the first zero (1-based index)
                System.out.println(index + 1);
                // Terminate the loop using the break statement
                break;
            }
        }
        
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
