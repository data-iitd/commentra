import java.util.Scanner;

public class Main {
    // Define constants
    private static final int N_MAX = 100;
    private static final int P_MAX = 100;

    // Function to find the last occurrence of a substring in a string
    private static String strrstr(String string, String pattern) {
        int offset = 0;
        String lastP = null;

        while (true) {
            int index = string.indexOf(pattern, offset);
            if (index == -1) {
                break;
            }
            lastP = string.substring(index);
            offset = index + 1;
        }

        return lastP;
    }

    public static void main(String[] args) {
        // Define pattern base string
        final String patternBase = "keyence";
        String S;

        // Read input string from standard input
        Scanner scanner = new Scanner(System.in);
        S = scanner.nextLine();
        scanner.close();

        // Calculate length of input string
        final int len = S.length();
        boolean found = false;

        // Loop through each character in pattern base string
        for (int offset = 0; offset < patternBase.length(); offset++) {
            // Copy substring up to current character to top variable
            String top = patternBase.substring(0, offset);

            // Copy substring from current character to end of pattern base string to bottom variable
            String bottom = patternBase.substring(offset);

            // Search for top substring in input string
            int topIndex = S.indexOf(top);

            // If top substring is found
            if (topIndex != -1) {
                // Search for bottom substring after top substring in input string
                String bottomSearch = strrstr(S.substring(topIndex + offset), bottom);

                // If bottom substring is found
                if (bottomSearch != null) {
                    // Calculate number of separators between top and bottom substrings
                    int sepCount = 0;

                    // If topIndex is not the first occurrence of top substring in input string
                    if (topIndex != 0) {
                        sepCount++;
                    }

                    // If topIndex is not the same as bottomSearch
                    if (topIndex + offset != S.indexOf(bottom, topIndex + offset)) {
                        sepCount++;
                    }

                    // If bottomSearch is not the last character in input string
                    if (bottomSearch.length() != 0 && bottomSearch.charAt(bottom.length() - 1) != '\0') {
                        sepCount++;
                    }

                    // If number of separators is less than or equal to 1
                    if (sepCount <= 1) {
                        found = true;
                        break;
                    }
                }
            }
        }

        // Print output based on whether pattern is found or not
        System.out.println(found ? "YES" : "NO");
    }
}

// <END-OF-CODE>
