import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Variable to store the number of lines to read
        scanner.nextLine(); // Consume the newline character
        String s; // String to store each line of input

        // Loop to process each line of input
        while (n-- > 0) {
            // Read a line of input from stdin
            s = scanner.nextLine();

            // Search for the substring "Hoshino" in the input line
            // Replace the character following "Hoshino" with 'a'
            int index;
            while ((index = s.indexOf("Hoshino")) != -1) {
                s = s.substring(0, index + 6) + 'a' + s.substring(index + 7);
            }

            // Print the modified line
            System.out.println(s);
        }

        scanner.close(); // Close the scanner
    }
}

