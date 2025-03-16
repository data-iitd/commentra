import java.io.*;
import java.util.Scanner;

public class Main {
    // Main function handles file input/output operations based on command-line arguments.
    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;

        // Check if command-line arguments are provided for file input/output.
        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]);
            if (args.length > 1) {
                outputStream = new FileOutputStream(args[1]);
            }
        }

        Scanner scanner = new Scanner(inputStream);
        PrintWriter writer = new PrintWriter(outputStream);

        // Read the number of integers to process.
        int n = scanner.nextInt();

        // Initialize the answer to "second".
        String ans = "second";
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            if (a % 2 == 1) {
                ans = "first";
                break;
            }
        }
        // Print the result based on the condition.
        writer.println(ans);
        writer.flush();
        scanner.close();
        writer.close();
    }
}

// <END-OF-CODE>
