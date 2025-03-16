import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of constraints (n) and the number of conditions (m)
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Initialize arrays to store the positions (s) and corresponding values (c)
        int[] s = new int[m];
        int[] c = new int[m];

        // Read the constraints into the arrays
        for (int i = 0; i < m; i++) {
            s[i] = scanner.nextInt() - 1; // Adjust for 0-based indexing
            c[i] = scanner.nextInt();
        }

        // Iterate through all possible numbers from 0 to 999
        for (int i = 0; i < 1000; i++) {
            String st = Integer.toString(i); // Convert the number to a string

            // Skip numbers that do not have the required length
            if (st.length() != n) {
                continue;
            }

            // Flag to check if the current number satisfies all conditions
            boolean satisfiesAllConditions = true;

            // Check each condition against the current number
            for (int j = 0; j < m; j++) {
                if (st.charAt(s[j]) != (c[j] + '0')) {
                    // Condition is not satisfied, set flag to false
                    satisfiesAllConditions = false;
                    break; // No need to check further
                }
            }

            // If all conditions are satisfied, print the number and exit
            if (satisfiesAllConditions) {
                System.out.println(i);
                return;
            }
        }

        // If no valid number is found, output -1
        System.out.println(-1);
    }
}
// <END-OF-CODE>
