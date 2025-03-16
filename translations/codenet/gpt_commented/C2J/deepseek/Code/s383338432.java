public class Main {
    public static void main(String[] args) {
        // Declare variables for height and width of the input, and a loop counter
        int height, width, i;

        // Create a Scanner object to read user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read the height and width from user input
        height = scanner.nextInt();
        width = scanner.nextInt();

        // Declare a character array to hold the input strings, with an extra space for the null terminator
        char[] input_str = new char[width + 1];

        // Print the top border of the box, consisting of '#' characters
        for(i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();

        // Read each line of input and print it with '#' borders
        for(i = 0; i < height; i++) {
            // Read a string from user input
            String line = scanner.next();
            // Print the string with '#' on both sides
            System.out.println("#" + line + "#");
        }

        // Print the bottom border of the box, consisting of '#' characters
        for(i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();

        // Close the scanner object
        scanner.close();
    }
}
