import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of test cases
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        // Process each test case
        for (int i = 0; i < n; i++) {
            String s = in.next();

            // Initialize a set to store unique combinations of strings
            Set<String> st = new HashSet<String>();
            // Insert the original string into the set
            st.add(s);

            // Generate combinations by splitting the string at different positions
            for (int j = 1; j < s.length(); j++) {
                // Create the first part of the split string
                StringBuilder sb = new StringBuilder();
                for (int k = 0; k < j; k++) {
                    sb.append(s.charAt(k));
                }
                String res = sb.toString(); // First part of the string

                // Create the second part of the split string
                StringBuilder sb2 = new StringBuilder();
                for (int k = j; k < s.length(); k++) {
                    sb2.append(s.charAt(k));
                }
                String res2 = sb2.toString(); // Second part of the string

                // Create reversed versions of both parts
                String t = res;
                StringBuilder sb3 = new StringBuilder();
                for (int k = t.length() - 1; k >= 0; k--) {
                    sb3.append(t.charAt(k));
                }
                String t2 = sb3.toString(); // Reverse of the first part

                String t3 = res2;
                StringBuilder sb4 = new StringBuilder();
                for (int k = t3.length() - 1; k >= 0; k--) {
                    sb4.append(t3.charAt(k));
                }
                String t4 = sb4.toString(); // Reverse of the second part

                // Insert various combinations of the parts and their reverses into the set
                st.add(t + t2); // Original order
                st.add(t2 + t); // Reversed order

                st.add(t + res2); // First part + second part
                st.add(res2 + t); // Second part + first part

                st.add(res + t2); // First part + reversed second part
                st.add(t2 + res); // Reversed second part + first part

                st.add(res + res2); // First part + second part (both original)
                st.add(res2 + res); // Second part + first part (both original)
            }

            // Output the number of unique combinations generated
            System.out.println(st.size());
        }
    }
}

