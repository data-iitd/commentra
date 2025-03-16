import java.util.Scanner;

public class Main {
    // Define modulus constant
    static final int MOD = 1000000007;

    // Define main function 'main_b'
    public static void main_b() {
        Scanner scanner = new Scanner(System.in);
        // Read input string 's'
        String s = scanner.nextLine();

        // Initialize variables 'pp' and 'na'
        int pp = 0;
        int na = 0;

        // Iterate through each character in the input string 's'
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            // Calculate current character value 'cc'
            int cc = na + Character.getNumericValue(c);
            na = 0;

            // Update 'pp' based on the current character value 'cc'
            if (cc <= 4) {
                pp += cc;
            } else {
                // If current character is the last character, add 1 to 'pp'
                if (i == s.length() - 1) {
                    pp += 1;
                }
                // Otherwise, add 10 - 'cc' to 'pp'
                pp += 10 - cc;
            }
        }

        // Print the result 'pp'
        System.out.println(pp);
    }

    // Define main function 'main'
    public static int mainFunction() {
        Scanner scanner = new Scanner(System.in);
        // Read input string 's'
        String s = scanner.nextLine();

        // Initialize variables 'pmin' and 'mmin' with large initial values
        int pmin = 1000;
        int mmin = 0;

        // Add a leading zero to the input string 's'
        s = '0' + s;

        // Iterate through each character in the input string 's'
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            // Calculate new minimum values 'npmin' and 'nmmin'
            int npmin = Math.min(pmin + 10 - (Character.getNumericValue(c) + 1), mmin + 10 - Character.getNumericValue(c));
            int nmmin = Math.min(pmin + Character.getNumericValue(c) + 1, mmin + Character.getNumericValue(c));

            // Update 'pmin' and 'mmin' with the new minimum values
            pmin = npmin;
            mmin = nmmin;
        }

        // Return the minimum value between 'pmin' and 'mmin'
        return Math.min(pmin, mmin);
    }

    public static void main(String[] args) {
        // Call main function and print result
        int ret = mainFunction();
        System.out.println(ret);
    }
}

// <END-OF-CODE>
