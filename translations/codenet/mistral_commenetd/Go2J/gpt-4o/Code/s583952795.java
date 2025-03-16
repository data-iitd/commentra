import java.util.Scanner;

public class Main {
    static final int INITIAL_BUF_SIZE = 10000;
    static final int MAX_BUF_SIZE = 100000000;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input numbers N and K
        int N = readInt(scanner);
        int K = readInt(scanner);

        // Calculate the base-10 representation of N up to digit count K
        String s = tenToN(N, K);

        // Print the length of the calculated string
        System.out.println(s.length());
    }

    // Function to convert a number to its base-10 string representation with digit count K
    static String tenToN(int number, int n) {
        StringBuilder s = new StringBuilder();
        int tmp = number; // Initialize temporary variable

        // Repeat the following process until the number becomes less than N
        while (true) {
            // Append the remainder of the division by N to the result string
            s.insert(0, i2s(tmp % n));

            // If the number is less than N, break the loop
            if (tmp < n) {
                break;
            }

            // Divide the number by N
            tmp /= n;
        }

        // Return the result string
        return s.toString();
    }

    // Read an integer from the input scanner
    static int readInt(Scanner scanner) {
        return Integer.parseInt(scanner.next());
    }

    // Convert an integer to its string representation
    static String i2s(int i) {
        return Integer.toString(i);
    }
}

// <END-OF-CODE>
