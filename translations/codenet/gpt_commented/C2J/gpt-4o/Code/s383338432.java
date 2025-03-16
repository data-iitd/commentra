import java.util.Scanner;

public class BoxPrinter {
    public static void main(String[] args) {
        // Declare variables for height and width of the input
        int height, width;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the height and width from user input
        height = scanner.nextInt();
        width = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Print the top border of the box, consisting of '#' characters
        for (int i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();

        // Read each line of input and print it with '#' borders
        for (int i = 0; i < height; i++) {
            // Read a string from user input
            String inputStr = scanner.nextLine();
            // Print the string with '#' on both sides
            System.out.println("#" + inputStr + "#");
        }

        // Print the bottom border of the box, consisting of '#' characters
        for (int i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
