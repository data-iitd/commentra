import java.io.*;
import java.util.Scanner;

public class Main {
    // Method to read the next integer from the scanner.
    private static int getNextInt(Scanner scanner) {
        return scanner.nextInt();
    }

    public static void main(String[] args) {
        // Initialize input and output streams.
        InputStream inputStream = System.in;
        PrintStream outputStream = System.out;

        // Check for command line arguments to open input and output files.
        if (args.length > 0) {
            try {
                inputStream = new FileInputStream(args[0]); // Open input file if provided.
                if (args.length > 1) {
                    outputStream = new PrintStream(new FileOutputStream(args[1])); // Create output file if provided.
                }
            } catch (FileNotFoundException e) {
                e.printStackTrace();
                return;
            }
        }

        // Create a scanner for reading input.
        Scanner scanner = new Scanner(inputStream);

        // Read the number of integers to process.
        int n = getNextInt(scanner);

        // Initialize the answer as "second" and check for odd integers.
        String ans = "second";
        for (int i = 0; i < n; i++) {
            int a = getNextInt(scanner); // Read the next integer.
            if (a % 2 == 1) { // Check if the integer is odd.
                ans = "first"; // If odd, set answer to "first".
                break; // Exit the loop early if an odd integer is found.
            }
        }

        // Write the result to the output.
        outputStream.println(ans);
        scanner.close(); // Close the scanner.
        if (outputStream != System.out) {
            outputStream.close(); // Close the output stream if it's not the standard output.
        }
    }
}
// <END-OF-CODE>
