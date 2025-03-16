import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // number of strings to be processed

        // Iterate through each string
        for (int i = 0; i < n; i++) {
            String s = scanner.next(); // string to be processed

            // Create an empty set to store unique substrings
            Set<String> st = new HashSet<>();

            // Process each substring of the string
            for (int j = 1; j < s.length(); j++) {
                // Create a StringBuilder to store the substring
                StringBuilder ss = new StringBuilder();

                // Iterate through the first j characters of the string
                for (int k = 0; k < j; k++) {
                    // Add the character to the StringBuilder
                    ss.append(s.charAt(k));
                }

                // Get the substring as a string from the StringBuilder
                String res = ss.toString();

                // Create another StringBuilder to process the remaining characters of the string
                StringBuilder ss2 = new StringBuilder();

                // Iterate through the remaining characters of the string
                for (int k = j; k < s.length(); k++) {
                    // Add the character to the StringBuilder
                    ss2.append(s.charAt(k));
                }

                // Get the substring as a string from the StringBuilder
                String res2 = ss2.toString();

                // Create two temporary strings by reversing the substrings
                String t = res;
                String reversedRes = ss.reverse().toString();
                String t2 = res2;
                String reversedRes2 = ss2.reverse().toString();

                // Insert all possible combinations of the substrings and their reversed versions into the set
                st.add(t + t2);
                st.add(t2 + t);
                st.add(t + reversedRes2);
                st.add(reversedRes2 + t);
                st.add(reversedRes + t2);
                st.add(t2 + reversedRes);
                st.add(reversedRes + reversedRes2);
                st.add(reversedRes2 + reversedRes);
            }

            // Print the size of the set, which represents the number of unique substrings
            System.out.println(st.size());
        }
    }
}
