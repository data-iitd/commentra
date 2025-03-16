import java.util.Scanner; // Importing Scanner for input
import java.util.StringTokenizer; // Importing StringTokenizer for string manipulation

public class Main {
    public static void main(String[] args) {
        // Create a new scanner to read input from standard input
        Scanner scanner = new Scanner(System.in);

        // Read the first line of input (not used)
        scanner.nextLine();
        // Read the second line of input which contains space-separated integers
        String ds = scanner.nextLine();

        // Split the input string into tokens
        StringTokenizer tokenizer = new StringTokenizer(ds);
        // Create an array to hold the converted values
        int[] dn = new int[tokenizer.countTokens()];
        int index = 0;

        // Convert each token in the tokenizer to an integer
        while (tokenizer.hasMoreTokens()) {
            dn[index++] = Integer.parseInt(tokenizer.nextToken());
        }

        // Initialize a variable to hold the sum of products
        int sum = 0;
        // Calculate the sum of products of all unique pairs of integers
        for (int i = 0; i < dn.length; i++) {
            for (int j = i + 1; j < dn.length; j++) {
                sum += dn[i] * dn[j]; // Multiply the pair and add to sum
            }
        }

        // Output the final sum of products
        System.out.println(sum);
    }
}

// <END-OF-CODE>
