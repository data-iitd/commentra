import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Initialize variables for number of students and classes
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Initialize arrays 's' and 'c' for storing student numbers and classes respectively
        int[] s = new int[m];
        int[] c = new int[m];

        // Read student numbers and classes from the standard input stream
        for (int i = 0; i < m; i++) {
            s[i] = scanner.nextInt() - 1;
            c[i] = scanner.nextInt();
        }

        // Check all strings of length 'n' for a valid combination of student numbers and classes
        for (int i = 0; i < 1000; i++) {
            // Convert the current number to a string
            String st = String.valueOf(i);

            // Check if the length of the string is equal to 'n'
            if (st.length() != n) {
                continue;
            }

            // Initialize a flag 'f' to check if the current combination is valid
            boolean f = true;

            // Check each combination of student number and class
            for (int j = 0; j < m; j++) {
                // Check if the current character in the string matches the expected class
                if (st.charAt(s[j]) == (char) (c[j] + '0')) {
                    // If yes, continue to the next check
                } else {
                    // If no, set the flag 'f' to false and break the loop
                    f = false;
                    break;
                }
            }

            // If all checks passed, print the current number and exit the program
            if (f) {
                System.out.println(i);
                return;
            }
        }

        // If no valid combination was found, print -1
        System.out.println(-1);
    }
}
