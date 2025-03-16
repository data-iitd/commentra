import java.util.Scanner;

public class Main {
    // Define constants
    static final long INF = (long) 1e20;
    static final int MOD = (int) 1e9 + 7;

    // Function to read an integer list from standard input
    public static int[] readIntArray(Scanner scanner) {
        String[] input = scanner.nextLine().split(" ");
        int[] result = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            result[i] = Integer.parseInt(input[i]);
        }
        return result;
    }

    public static void main(String[] args) {
        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Read input values
        int[] values = readIntArray(scanner);
        int a = values[0];
        int b = values[1];
        int c = values[2];
        int d = values[3];

        // Calculate the maximum product of pairs of numbers
        long result = Math.max(Math.max(a * c, b * d), Math.max(a * d, b * c));

        // Print the result
        System.out.println(result);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
