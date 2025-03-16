public class Main {
    public static void main(String[] args) {
        // Set output format to fixed-point notation with 10 decimal places
        System.out.printf("%.10f\n", 0.0);
        solve(); // Call the solve function to process input and output results
    }

    public static void solve() {
        // Initialize variables to track the maximum size of strings and their counts
        int maxsize = 0; // To store the length of the longest string
        int maxcnt = 0;  // To store the count of the most frequent string
        int ans_num = 0;     // Index of the longest string
        int ans_num2 = 0;    // Index of the most frequent string
        java.util.List<String> str_v = new java.util.ArrayList<>(); // List to store input strings
        
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String in; // Variable to hold each input string
        // Read strings from standard input until EOF
        while (scanner.hasNext()) {
            in = scanner.next(); // Read the next string
            str_v.add(in); // Add the string to the list
            // Check if the current string is longer than the previously recorded maximum
            if (maxsize < in.length()) {
                maxsize = in.length(); // Update the maximum size
                ans_num = str_v.size() - 1; // Update index of the longest string
            }
        }
        
        // Loop through the list to find the most frequent string
        for (int i = 0; i < str_v.size(); i++) {
            int cnt = 0; // Counter for occurrences of the current string
            // Count how many times the current string appears in the list
            for (int j = 0; j < str_v.size(); j++) {
                if (str_v.get(i).equals(str_v.get(j))) cnt++; // Increment count if a match is found
            }
            // Check if the current count is greater than the previously recorded maximum count
            if (maxcnt < cnt) {
                maxcnt = cnt; // Update the maximum count
                ans_num2 = i; // Update index of the most frequent string
            }
        }
        
        // Output the most frequent string and the longest string
        System.out.println(str_v.get(ans_num2) + " " + str_v.get(ans_num));
    }
}
