public class Main {
    public static void main(String[] args) {
        // Call the solve function
        solve();
    }

    public static void solve() {
        // Initialize variables to track the longest string and its count
        int maxsize = 0;
        int maxcnt = 0;
        int ans_num = -1; // Index of the longest string
        int ans_num2 = -1; // Index of the most frequent string
        java.util.List<String> str_v = new java.util.ArrayList<>(); // List to store input strings

        // Variable to read input strings
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNext()) {
            String in = scanner.next();
            str_v.add(in); // Store the input string in the list
            if (maxsize < in.length()) { // Check if the current string is the longest so far
                maxsize = in.length(); // Update the length of the longest string
                ans_num = str_v.size() - 1; // Store the index of the longest string
            }
        }

        // Count occurrences of each string and find the most frequent string
        for (int i = 0; i < str_v.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < str_v.size(); j++) {
                if (str_v.get(i).equals(str_v.get(j))) cnt++; // Count occurrences of the current string
            }
            if (maxcnt < cnt) { // Check if the current string is the most frequent so far
                maxcnt = cnt; // Update the count of the most frequent string
                ans_num2 = i; // Store the index of the most frequent string
            }
        }

        // Output the most frequent and the longest string
        System.out.println(str_v.get(ans_num2) + " " + str_v.get(ans_num));
    }
}
