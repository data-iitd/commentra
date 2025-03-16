import java.util.Scanner;  // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int height = scanner.nextInt();  // Read the height from user input
        int width = scanner.nextInt();  // Read the width from user input
        scanner.nextLine();  // Consume the newline character after the integers

        // Print the top border of the output
        for (int i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();

        // Read and print each line of input with borders
        for (int i = 0; i < height; i++) {
            String inputStr = scanner.nextLine();  // Read a string from the user
            System.out.println("#" + inputStr + "#");  // Print the string with borders
        }

        // Print the bottom border of the output
        for (int i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();

        scanner.close();  // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
