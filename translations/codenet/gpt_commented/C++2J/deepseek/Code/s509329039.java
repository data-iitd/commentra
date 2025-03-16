public class Main {
    public static void main(String[] args) {
        // Read the number of constraints (n) and the number of conditions (m)
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Initialize vectors to store the positions (s) and corresponding values (c)
        int[] s = new int[m];
        int[] c = new int[m];
        
        // Read the constraints into the vectors
        for (int i = 0; i < m; i++) {
            s[i] = scanner.nextInt() - 1; // Adjust for 0-based indexing
            c[i] = scanner.nextInt();
        }

        // Iterate through all possible numbers from 0 to 999
        for (int i = 0; i < 1000; i++) {
            String st = String.valueOf(i); // Convert the number to a string
            
            // Skip numbers that do not have the required length
            if (st.length() != n) {
                continue;
            }

            // Flag to check if the current number satisfies all conditions
            boolean f = true;

            // Check each condition against the current number
            for (int j = 0; j < m; j++) {
                if (st.charAt(s[j]) != (char) (c[j] + '0')) {
                    // Condition is not satisfied, set flag to false
                    f = false;
                }
            }

            // If all conditions are satisfied, print the number and exit
            if (f) {
                System.out.println(i);
                return;
            }
        }

        // If no valid number is found, output -1
        System.out.println(-1);
    }
}
