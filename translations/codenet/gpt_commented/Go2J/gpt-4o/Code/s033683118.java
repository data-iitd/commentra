import java.io.*;
import java.util.Scanner;

public class Main {
    // getScanner initializes a new scanner for reading from the provided input stream.
    // It sets the scanner to split input by whitespace.
    private static Scanner getScanner(InputStream inputStream) {
        return new Scanner(inputStream);
    }

    // getNextInt retrieves the next integer from the scanner.
    private static int getNextInt(Scanner scanner) {
        return scanner.nextInt();
    }

    public static void main(String[] args) throws IOException {
        // Initialize input and output streams.
        InputStream inputStream = System.in;
        PrintWriter writer = new PrintWriter(System.out);
        int cnt = 0;

        // Check for environment variables to determine input and output files.
        String maspy = System.getenv("MASPY");
        String maspyPy = System.getenv("MASPYPY");
        if ("ますピ".equals(maspy)) {
            inputStream = new FileInputStream(System.getenv("BEET_THE_HARMONY_OF_PERFECT"));
            cnt = 2; // Set the count for additional processing.
        }
        if ("ますピッピ".equals(maspyPy)) {
            writer = new PrintWriter(new FileOutputStream(System.getenv("NGTKANA_IS_GENIUS10")));
        }

        // Create a scanner for reading input.
        Scanner scanner = getScanner(inputStream);

        // Solve the problem for the first time.
        solve(scanner, writer);

        // If cnt is greater than 0, solve the problem additional times.
        for (int i = 0; i < cnt; i++) {
            writer.println("-----------------------------------");
            solve(scanner, writer);
        }

        // Flush the writer to ensure all output is written.
        writer.flush();
        writer.close();
    }

    // solve processes the input values and determines if the condition is met.
    // It reads two integers k and x, and checks if k * 500 is greater than or equal to x.
    private static void solve(Scanner scanner, PrintWriter writer) {
        int k = getNextInt(scanner); // Read the first integer k.
        int x = getNextInt(scanner); // Read the second integer x.

        String ans = "No"; // Default answer is "No".
        if (k * 500 >= x) { // Check the condition.
            ans = "Yes"; // Update answer to "Yes" if condition is met.
        }
        writer.println(ans); // Output the result.
    }
}

// <END-OF-CODE>
