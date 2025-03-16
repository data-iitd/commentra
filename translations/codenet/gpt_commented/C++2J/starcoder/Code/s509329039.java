import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of constraints (n) and the number of conditions (m)
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();

        // Initialize vectors to store the positions (s) and corresponding values (c)
        int[] s = new int[m];
        int[] c = new int[m];
        
        // Read the constraints into the vectors
        for (int i = 0; i < m; i++) {
            s[i] = in.nextInt();
            c[i] = in.nextInt();
            s[i]--; // Adjust for 0-based indexing
        }

        // Iterate through all possible numbers from 0 to 999
        for (int i = 0; i < 1000; i++) {
            String st = Integer.toString(i); // Convert the number to a string
            
            // Skip numbers that do not have the required length
            if (st.length()!= n) {
                continue;
            }

            // Flag to check if the current number satisfies all conditions
            int f = 1;

            // Check each condition against the current number
            for (int j = 0; j < m; j++) {
                if (st.charAt(s[j]) == (c[j] + '0')) {
                    // Condition is satisfied
                } else {
                    // Condition is not satisfied, set flag to 0
                    f = 0;
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

