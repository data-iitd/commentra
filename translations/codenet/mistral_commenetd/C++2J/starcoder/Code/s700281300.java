
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n; // number of strings to be processed

        // Read the number of strings from the standard input
        n = in.nextInt();

        // Iterate through each string
        for(int i=0;i<n;i++) {
            String s; // string to be processed

            // Read the string from the standard input
            s = in.next();

            // Create an empty set to store unique substrings
            Set<String> st = new HashSet<String>();

            // Process each substring of the string
            for(int j=1;j<s.length();j++) {
                // Create a stringstream to store the substring
                StringBuilder ss = new StringBuilder();

                // Iterate through the first j characters of the string
                for(int k=0;k<j;k++) {
                    // Add the character to the stringstream
                    ss.append(s.charAt(k));
                }

                // Get the substring as a string from the stringstream
                String res = ss.toString();

                // Create another stringstream to process the remaining characters of the string
                StringBuilder ss2 = new StringBuilder();

                // Iterate through the remaining characters of the string
                for(int k=j;k<s.length();k++) {
                    // Add the character to the stringstream
                    ss2.append(s.charAt(k));
                }

                // Get the substring as a string from the stringstream
                String res2 = ss2.toString();

                // Create two temporary strings by reversing the substrings
                String t = res;
                StringBuilder t2 = new StringBuilder(res2);
                t2.reverse();

                // Insert all possible combinations of the substrings and their reversed versions into the set
                st.add(t+t2.toString());
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
    }
}

