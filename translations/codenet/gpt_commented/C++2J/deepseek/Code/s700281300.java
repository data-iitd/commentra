public class Main {
    public static void main(String[] args) {
        // Read the number of test cases
        int n;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        // Process each test case
        for (int i = 0; i < n; i++) {
            String s;
            // Read the string for the current test case
            s = scanner.next();

            // Initialize a set to store unique combinations of strings
            java.util.Set<String> st = new java.util.HashSet<>();
            // Insert the original string into the set
            st.add(s);

            // Generate combinations by splitting the string at different positions
            for (int j = 1; j < s.length(); j++) {
                StringBuilder ss = new StringBuilder();
                // Create the first part of the split string
                for (int k = 0; k < j; k++) {
                    ss.append(s.charAt(k));
                }
                String res = ss.toString(); // First part of the string

                StringBuilder ss2 = new StringBuilder();
                // Create the second part of the split string
                for (int k = j; k < s.length(); k++) {
                    ss2.append(s.charAt(k));
                }
                String res2 = ss2.toString(); // Second part of the string

                // Create reversed versions of both parts
                String t = res;
                t = new StringBuilder(t).reverse().toString(); // Reverse the first part
                String t2 = res2;
                t2 = new StringBuilder(t2).reverse().toString(); // Reverse the second part

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
