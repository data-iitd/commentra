import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Step 1: Reading Input

        for (int i = 0; i < n; i++) { // Step 2: Processing Each Test Case
            String s = scanner.next(); // For each test case, the program reads a string s.

            HashSet<String> st = new HashSet<>(); // Step 3: Generating Substrings and Checking for Palindromes
            st.add(s); // The first substring is inserted into the set.

            for (int j = 1; j < s.length(); j++) { // The inner loop iterates over possible split points in the string s.
                StringBuilder res = new StringBuilder(); // A StringBuilder is used to construct substrings.
                for (int k = 0; k < j; k++) { // The first part of the string is extracted and reversed.
                    res.append(s.charAt(k));
                }
                String firstPartReversed = res.reverse().toString(); // The first part is reversed.

                StringBuilder res2 = new StringBuilder(); // Another StringBuilder is used to extract the second part of the string.
                for (int k = j; k < s.length(); k++) { // The second part of the string is extracted and reversed.
                    res2.append(s.charAt(k));
                }
                String secondPartReversed = res2.reverse().toString(); // The second part is reversed.

                // The first part is concatenated with the reversed second part in both orders and added to the set.
                st.add(firstPartReversed + secondPartReversed);
                st.add(secondPartReversed + firstPartReversed);

                st.add(firstPartReversed + res2.toString()); // The first part is concatenated with the reversed first part and added to the set.
                st.add(secondPartReversed + firstPartReversed);

                st.add(res.toString() + secondPartReversed); // The reversed first part is concatenated with the second part and added to the set.
                st.add(secondPartReversed + res.toString());

                st.add(res.toString() + res2.toString()); // The reversed first and second parts are concatenated in both orders and added to the set.
                st.add(res2.toString() + res.toString());
            }

            System.out.println(st.size()); // Step 4: Outputting the Result
        }

        scanner.close(); // Closing the scanner
    }
} // Step 5: End of Program
// <END-OF-CODE>
