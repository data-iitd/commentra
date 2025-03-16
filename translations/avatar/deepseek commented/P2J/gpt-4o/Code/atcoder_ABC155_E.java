import java.util.Scanner;

public class Main {
    // Define possible input methods: clipboard, file, key
    private static final String[] inputMethods = {"clipboard", "file", "key"};
    private static int usingMethod = 0; // Indicate which input method to use, starting with 'clipboard'
    private static final long MOD = 1000000007;

    // Main function for base case
    public static void mainB() {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int pp = 0;
        int na = 0;

        // Iterate over the string in reverse order
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            int cc = na + Character.getNumericValue(c);
            na = 0;

            // If the sum is less than or equal to 4, add to pp
            if (cc <= 4) {
                pp += cc;
            } else {
                na = 1;
                // If it's the last digit, add 1 to pp
                if (i == s.length() - 1) {
                    pp += 1;
                }
                pp += 10 - cc;
            }
        }
        // Print the result
        System.out.println(pp);
    }

    // Main function for general case
    public static int main() {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int pmin = 1000;
        int mmin = 0;
        s = '0' + s; // Prepend '0' to the string

        // Iterate over the string in reverse order
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            int v = Character.getNumericValue(c);
            int npmin = Math.min(pmin + 10 - (v + 1), mmin + 10 - v);
            int nmmin = Math.min(pmin + v + 1, mmin + v);
            pmin = npmin;
            mmin = nmmin;
        }
        // Return the minimum of pmin and mmin
        return Math.min(pmin, mmin);
    }

    public static void main(String[] args) {
        // Check if the script is running in test mode
        boolean isTest = false;

        // Main execution block
        if (System.getProperty("os.name").toLowerCase().contains("ios")) {
            // Handle input methods if running on iOS
            if (inputMethods[usingMethod].equals("clipboard")) {
                // Clipboard handling is not implemented in this example
                // You would need to use a library or API to access the clipboard
            } else if (inputMethods[usingMethod].equals("file")) {
                // File handling is not implemented in this example
                // You would need to read from a file
            } else {
                // Handle key input
            }
            isTest = true;
        }

        int ret = main();
        if (ret != 0) {
            System.out.println(ret);
        }
    }
}

// <END-OF-CODE>
