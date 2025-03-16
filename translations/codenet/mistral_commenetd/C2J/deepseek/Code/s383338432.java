public class RectanglePrinter {
    public static void main(String[] args) {
        // Declare variables for height and width of the rectangle to be printed
        int height, width;
        // Declare a character array to store the input string
        char[] input_str = new char[width + 1];
        // Initialize a counter variable 'i'
        int i;

        // Read the height and width of the rectangle from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        height = scanner.nextInt();
        width = scanner.nextInt();

        // Print the top border of the rectangle
        for(i = 0; i < width + 2; i++) {
            // Print '#' character for each iteration
            System.out.print("#");
        }
        System.out.println(); // Print newline character after the top border

        // Print the body of the rectangle
        for(i = 0; i < height; i++) {
            // Read a string from the user
            String input = scanner.next();
            // Print the top and bottom border of each row with '#' character
            System.out.println("#" + input + "#");
        }

        // Print the bottom border of the rectangle
        for(i = 0; i < width + 2; i++) {
            // Print '#' character for each iteration
            System.out.print("#");
        }
        System.out.println(); // Print newline character after the bottom border

        // Return 0 to indicate successful execution of the program
    }
}
