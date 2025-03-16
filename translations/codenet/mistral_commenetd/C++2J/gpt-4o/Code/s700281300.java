import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class UniqueSubstrings {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of strings from the standard input
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Iterate through each string
        for (int i = 0; i < n; i++) {
            String s = scanner.nextLine(); // Read the string from the standard input

            // Create an empty set to store unique substrings
            Set<String> st = new HashSet<>();

            // Process each substring of the string
            for (int j = 1; j < s.length(); j++) {
                // Create the first substring
                String res = s.substring(0, j);
                // Create the second substring
                String res2 = s.substring(j);

                // Create two temporary strings by reversing the substrings
                String t = new StringBuilder(res).reverse().toString();
                String t2 = new StringBuilder(res2).reverse().toString();

                // Insert all possible combinations of the substrings and their reversed versions into the set
                st.add(t + t2);
                st.add(t2 + t);
                st.add(t + res2);
                st.add(res2 + t);
                st.add(res + t2);
                st.add(t2 + res);
                st.add(res + res2);
                st.add(res2 + res);
            }

            // Print the size of the set, which represents the number of unique substrings
            System.out.println(st.size());
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
