import java.io.*;
import java.util.*;

public class Main {
    
    // getScanner initializes a new Scanner to read from a file.
    // It sets the delimiter to whitespace to read words.
    public static Scanner getScanner(InputStream inputStream) {
        return new Scanner(inputStream);
    }

    // getNextString reads the next word from the scanner and returns it as a string.
    public static String getNextString(Scanner scanner) {
        return scanner.next();
    }

    // getNextInt reads the next word from the scanner, converts it to an integer,
    // and returns it.
    public static int getNextInt(Scanner scanner) {
        return Integer.parseInt(getNextString(scanner));
    }

    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]);
        }

        Scanner scanner = getScanner(inputStream);
        PrintWriter writer = new PrintWriter(System.out);

        // Read the number of elements.
        int n = getNextInt(scanner);

        // Initialize a list to store the elements and a sum variable.
        int[] aa = new int[n + 2];
        int sum = 0;

        // Read the elements into the array and calculate the sum of absolute differences.
        for (int i = 0; i < n; i++) {
            aa[i + 1] = getNextInt(scanner);
            sum += absint(aa[i + 1] - aa[i]);
        }
        sum += absint(aa[n + 1] - aa[n]);

        // Calculate and print the differences for each element.
        for (int i = 1; i < n + 1; i++) {
            int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
            writer.println(ans);
        }

        // Flush the writer to ensure all output is written to the output stream.
        writer.flush();
    }

    // absint returns the absolute value of an integer.
    public static int absint(int a) {
        return a < 0 ? -a : a;
    }
}

// <END-OF-CODE>
