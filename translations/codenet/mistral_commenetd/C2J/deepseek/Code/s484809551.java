import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Define pattern base string
        String patternBase = "keyence";
        String top, bottom;
        String S;

        // Read input string from standard input
        Scanner scanner = new Scanner(System.in);
        S = scanner.nextLine();

        // Calculate length of input string
        int len = S.length();
        boolean found = false;

        // Loop through each character in pattern base string
        for (int offset = 0; offset < patternBase.length(); offset++) {
            // Copy substring up to current character to top variable
            top = patternBase.substring(0, offset);

            // Copy substring from current character to end of pattern base string to bottom variable
            bottom = patternBase.substring(offset);

            // Search for top substring in input string
            int topIndex = S.indexOf(top);

            // If top substring is found
            if (topIndex != -1) {
                // Search for bottom substring after top substring in input string
                int bottomIndex = S.lastIndexOf(bottom, S.length() - 1);

                // If bottom substring is found
                if (bottomIndex != -1) {
                    // Calculate number of separators between top and bottom substrings
                    int sepCount = 0;

                    // If topIndex is not the first occurrence of top substring in input string
                    if (topIndex != 0) {
                        sepCount++;
                    }

                    // If topIndex is not the same as bottomIndex
                    if (topIndex + top.length() != bottomIndex) {
                        sepCount++;
                    }

                    // If bottomIndex is not the last character in input string
                    if (bottomIndex + bottom.length() != len) {
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

