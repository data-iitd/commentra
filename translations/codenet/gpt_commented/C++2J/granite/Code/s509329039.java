
import java.util.*;
import java.io.*;

public class s509329039{
    public static void main(String[] args) throws Exception {
        // Read the number of constraints (n) and the number of conditions (m)
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        // Initialize arrays to store the positions (s) and corresponding values (c)
        int[] s = new int[m];
        int[] c = new int[m];
        
        // Read the constraints into the arrays
        for (int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            s[i] = Integer.parseInt(input[0]) - 1; // Adjust for 0-based indexing
            c[i] = Integer.parseInt(input[1]);
        }

        // Iterate through all possible numbers from 0 to 999
        for (int i = 0; i < 1000; i++) {
            String st = String.valueOf(i); // Convert the number to a string
            
            // Skip numbers that do not have the required length
            if (st.length()!= n) {
                continue;
            }

            // Flag to check if the current number satisfies all conditions
            boolean f = true;

            // Check each condition against the current number
            for (int j = 0; j < m; j++) {
                if (st.charAt(s[j]) == (c[j] + '0')) {
                    // Condition is satisfied
                } else {
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

