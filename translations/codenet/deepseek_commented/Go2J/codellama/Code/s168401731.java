
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);

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
    }
}

