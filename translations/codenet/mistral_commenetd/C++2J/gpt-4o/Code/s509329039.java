import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variables for number of students and classes
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Initialize arrays for storing student numbers and classes respectively
        int[] s = new int[m];
        int[] c = new int[m];

        // Read student numbers and classes from the input
        for (int i = 0; i < m; i++) {
            s[i] = scanner.nextInt() - 1; // Decrement student numbers by 1 as they are 1-indexed
            c[i] = scanner.nextInt();
        }

        // Check all numbers from 0 to 999 for a valid combination of student numbers and classes
        for (int i = 0; i < 1000; i++) {
            String st = String.format("%03d", i); // Format the number to be 3 digits

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

// <END-OF-CODE>
