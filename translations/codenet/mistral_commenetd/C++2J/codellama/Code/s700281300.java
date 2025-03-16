
import java.util.*;
import java.io.*;

// Main function starts here
public class Main {
    public static void main(String[] args) throws Exception {
        // Read the number of strings from the standard input
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Iterate through each string
        for(int i=0;i<n;i++) {
            // Read the string from the standard input
            String s = sc.next();

            // Create an empty set to store unique substrings
            Set<String> st = new HashSet<>();

            // Process each substring of the string
            for(int j=1;j<=s.length();j++) {
                // Create a stringstream to store the substring
                StringBuffer sb = new StringBuffer();

                // Iterate through the first j characters of the string
                for(int k=0;k<j;k++) {
                    // Add the character to the stringstream
                    sb.append(s.charAt(k));
                }

                // Get the substring as a string from the stringstream
                String res = sb.toString();

                // Create another stringstream to process the remaining characters of the string
                StringBuffer sb2 = new StringBuffer();

                // Iterate through the remaining characters of the string
                for(int k=j;k<s.length();k++) {
                    // Add the character to the stringstream
                    sb2.append(s.charAt(k));
                }

                // Get the substring as a string from the stringstream
                String res2 = sb2.toString();

                // Create two temporary strings by reversing the substrings
                String t = res;
                String t2 = res2;
                StringBuffer sb3 = new StringBuffer(res);
                sb3.reverse();
                res = sb3.toString();
                StringBuffer sb4 = new StringBuffer(res2);
                sb4.reverse();
                res2 = sb4.toString();

                // Insert all possible combinations of the substrings and their reversed versions into the set
                st.add(t+t2);
                st.add(t2+t);
                st.add(t+res2);
                st.add(res2+t);
                st.add(res+t2);
                st.add(t2+res);
                st.add(res+res2);
                st.add(res2+res);
            }

            // Print the size of the set, which represents the number of unique substrings
            System.out.println(st.size());
        }

        // Main function ends here
    }
}

