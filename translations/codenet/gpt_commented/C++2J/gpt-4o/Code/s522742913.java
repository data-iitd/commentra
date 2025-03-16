import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a string variable to hold the input
        String source = "";
        // Read input from the user
        Scanner scanner = new Scanner(System.in);
        source = scanner.next();

        // Check if the input length is valid (between 1 and 10 characters)
        if (source.length() > 10 || source.length() < 1) {
            // Return -1 if the input length is invalid
            System.exit(-1);
        }

        // Calculate the maximum number of combinations of '+' placements
        int max_i = (int) Math.pow(2, source.length() - 1);

        // Initialize a variable to hold the cumulative sum of the evaluated expressions
        double sum = 0;

        // Iterate through all possible combinations of '+' placements
        for (int i = 0; i < max_i; ++i) {
            // Create a bitset to represent the current combination of '+' placements
            StringBuilder plus = new StringBuilder(Integer.toBinaryString(i));
            while (plus.length() < source.length() - 1) {
                plus.insert(0, '0'); // Pad with leading zeros
            }

            // Initialize a variable to hold the current number being evaluated
            double number = 0;

            // Create a working copy of the source string to manipulate
            String working = source;
            int lastIndex = 0;

            // While there are still '+' placements to evaluate
            for (int j = 0; j < plus.length(); j++) {
                if (plus.charAt(j) == '1') {
                    // Convert the substring up to the current position to a double and add to sum
                    sum += Double.parseDouble(working.substring(0, j + 1));
                    // Update the working string to remove the processed segment
                    working = working.substring(j + 1);
                    lastIndex = j + 1;
                }
            }
            // Add the remaining part of the working string to the sum
            if (lastIndex < working.length()) {
                sum += Double.parseDouble(working);
            }
        }

        // Set the precision for output and print the final sum
        System.out.printf("%.0f%n", sum);

        scanner.close();
    }
}
// <END-OF-CODE>
