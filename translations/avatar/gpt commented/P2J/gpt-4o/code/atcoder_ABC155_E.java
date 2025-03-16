import java.util.Scanner;

public class Main {
    static boolean isTest = false; // Flag to indicate if the program is in test mode

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputMethod = "key"; // Default input method
        String s = scanner.nextLine(); // Read input string

        if (inputMethod.equals("clipboard")) {
            // Clipboard input handling can be added here if needed
        } else if (inputMethod.equals("file")) {
            // File input handling can be added here if needed
        }

        int result = mainFunction(s); // Call the main function
        if (result != Integer.MAX_VALUE) {
            System.out.println(result); // Print the result if it's not the maximum integer value
        }
    }

    public static int mainFunction(String s) {
        int pmin = 1000; // Initialize minimum score for positive values
        int mmin = 0; // Initialize minimum score for negative values
        s = '0' + s; // Prepend '0' to the input string for easier processing

        // Process the string in reverse order
        for (int i = s.length() - 1; i >= 0; i--) {
            int v = Character.getNumericValue(s.charAt(i)); // Convert character to integer
            // Calculate new minimum scores based on current digit
            int npmin = Math.min(pmin + 10 - (v + 1), mmin + 10 - v);
            int nmmin = Math.min(pmin + v + 1, mmin + v);
            pmin = npmin; // Update positive minimum score
            mmin = nmmin; // Update negative minimum score
        }

        return Math.min(pmin, mmin); // Return the minimum score between positive and negative
    }

    public static void pa(int v) {
        // Print value if in test mode
        if (isTest) {
            System.out.println(v);
        }
    }
}
<END-OF-CODE>
