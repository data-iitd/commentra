import java.util.Scanner; // Import Scanner class for reading input
import java.util.StringTokenizer; // Import StringTokenizer for splitting strings

public class Main {
    public static void main(String[] args) {
        // Initialize a new scanner for reading from standard input
        Scanner scanner = new Scanner(System.in);

        // Read the first two lines from standard input
        scanner.nextLine(); // Skip the first line
        String ds = scanner.nextLine(); // Read the second line

        // Split the string ds into an array of strings dd using StringTokenizer
        StringTokenizer tokenizer = new StringTokenizer(ds);
        int[] dn = new int[tokenizer.countTokens()]; // Create an array of integers

        // Iterate through each token and convert it to an integer
        int index = 0;
        while (tokenizer.hasMoreTokens()) {
            dn[index++] = Integer.parseInt(tokenizer.nextToken());
        }

        // Initialize sum variable to 0
        int sum = 0;

        // Iterate through each index i in the array dn
        for (int i = 0; i < dn.length; i++) {
            // Iterate through each index j greater than i in the array dn
            for (int j = i + 1; j < dn.length; j++) {
                // Add the product of dn[i] and dn[j] to the sum variable
                sum += dn[i] * dn[j];
            }
        }

        // Print the value of sum variable to the standard output
        System.out.println(sum);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
