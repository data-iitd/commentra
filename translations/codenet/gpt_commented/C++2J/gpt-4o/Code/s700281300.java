import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class UniqueStringCombinations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of test cases
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Process each test case
        for (int i = 0; i < n; i++) {
            String s = scanner.nextLine();

            // Initialize a set to store unique combinations of strings
            Set<String> st = new HashSet<>();
            // Insert the original string into the set
            st.add(s);

            // Generate combinations by splitting the string at different positions
            for (int j = 1; j < s.length(); j++) {
                String res = s.substring(0, j); // First part of the string
                String res2 = s.substring(j); // Second part of the string

                // Create reversed versions of both parts
                String t = new StringBuilder(res).reverse().toString(); // Reverse the first part
                String t2 = new StringBuilder(res2).reverse().toString(); // Reverse the second part

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

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
