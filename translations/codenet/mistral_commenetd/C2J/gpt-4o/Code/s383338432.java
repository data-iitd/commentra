import java.util.Scanner;

public class RectanglePrinter {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Declare variables for height and width of the rectangle to be printed
        int height, width;
        
        // Read the height and width of the rectangle from the user
        height = scanner.nextInt();
        width = scanner.nextInt();
        
        // Print the top border of the rectangle
        for (int i = 0; i < width + 2; i++) {
            // Print '#' character for each iteration
            System.out.print("#");
        }
        System.out.println(); // Print newline character after the top border

        // Print the body of the rectangle
        for (int i = 0; i < height; i++) {
            // Read a string from the user
            String inputStr = scanner.next();
            // Print the top and bottom border of each row with '#' character
            System.out.printf("#%s#\n", inputStr);
        }

        // Print the bottom border of the rectangle
        for (int i = 0; i < width + 2; i++) {
            // Print '#' character for each iteration
            System.out.print("#");
        }
        System.out.println(); // Print newline character after the bottom border

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
