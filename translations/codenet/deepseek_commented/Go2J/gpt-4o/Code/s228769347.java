import java.io.*;
import java.util.*;

public class Main {
    
    // Method to read the next integer from the input.
    private static int getNextInt(Scanner scanner) {
        return scanner.nextInt();
    }

    // Main method handles file input/output based on command-line arguments.
    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;

        // Check if file paths are provided as command-line arguments.
        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]);
            if (args.length > 1) {
                outputStream = new FileOutputStream(args[1]);
            }
        }

        Scanner scanner = new Scanner(inputStream);
        PrintWriter writer = new PrintWriter(outputStream);

        // Read the number of elements.
        int n = getNextInt(scanner);
        int[] ll = new int[n];

        // Read n integers into the array ll.
        for (int i = 0; i < n; i++) {
            ll[i] = getNextInt(scanner);
        }

        // Sort the array ll.
        Arrays.sort(ll);

        // Initialize the answer variable.
        int ans = 0;

        // Iterate through possible triplets (i, j, m) where i < j < m.
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int l = j + 1;
                int r = n;
                while (l < r) {
                    int m = (l + r) >> 1;
                    if (ll[m] < ll[i] + ll[j]) {
                        l = m + 1;
                    } else {
                        r = m;
                    }
                }

                // Add the number of valid m's to the answer.
                ans += l - (j + 1);
            }
        }

        // Print the final answer to the standard output.
        writer.println(ans);

        // Close the writer to ensure all data is written to the file or standard output.
        writer.close();
        scanner.close();
    }
}

// <END-OF-CODE>
