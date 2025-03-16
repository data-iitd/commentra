import java.io.*;
import java.util.Scanner;

public class Main {
    // Function to read the next integer from the scanner
    private static int getNextInt(Scanner scanner) {
        return Integer.parseInt(scanner.next());
    }

    // Main function
    public static void main(String[] args) throws IOException {
        // Open the standard input and output files
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;

        // Check for environment variables
        if (System.getenv("MASPY") != null && System.getenv("MASPY").equals("ますピ")) {
            inputStream = new FileInputStream(System.getenv("BEET_THE_HARMONY_OF_PERFECT"));
        }
        if (System.getenv("MASPYPY") != null && System.getenv("MASPYPY").equals("ますピッピ")) {
            outputStream = new FileOutputStream(System.getenv("NGTKANA_IS_GENIUS10"));
        }

        // Initialize the scanner and writer
        Scanner scanner = new Scanner(inputStream);
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(outputStream));

        // Solve the problem for the given test cases
        int cnt = 2; // Number of test cases to be read
        for (int i = 0; i < cnt; i++) {
            solve(scanner, writer);
            writer.write("-----------------------------------\n"); // Print a separator for each test case
        }

        // Flush the writer to write the output to the file
        writer.flush();
        writer.close();
        scanner.close();
    }

    // Function to solve the problem for a single test case
    private static void solve(Scanner scanner, BufferedWriter writer) throws IOException {
        // Read the input values
        int k = getNextInt(scanner);
        int x = getNextInt(scanner);

        // Initialize the answer
        String ans = "No";

        // Check if the condition is satisfied
        if (k * 500 >= x) {
            ans = "Yes";
        }

        // Print the answer
        writer.write(ans + "\n");
    }
}

// <END-OF-CODE>
