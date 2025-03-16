import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Function to solve the problem
    public static boolean solve() {
        // Initialize variables
        int maxsize = 0;
        int maxcnt = 0;
        int ans_num = -1;
        int ans_num2 = -1;
        List<String> str_v = new ArrayList<>(); // List to store strings read from input

        // Read strings from input
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String in = scanner.next();
            // Add the string to the list
            str_v.add(in);
            // Update maxsize if the current string is larger
            if (maxsize < in.length()) {
                maxsize = in.length();
                ans_num = str_v.size() - 1;
            }
        }
        scanner.close();

        // Find the string with maximum occurrences in the list
        Map<String, Integer> countMap = new HashMap<>();
        for (String s : str_v) {
            countMap.put(s, countMap.getOrDefault(s, 0) + 1);
        }

        for (int i = 0; i < str_v.size(); i++) {
            String currentString = str_v.get(i);
            int cnt = countMap.get(currentString);
            // Update maxcnt and ans_num2 if the current string has more occurrences
            if (maxcnt < cnt) {
                maxcnt = cnt;
                ans_num2 = i;
            }
        }

        // Print the answer
        System.out.println(str_v.get(ans_num2) + " " + str_v.get(ans_num));

        // Return true to indicate successful execution
        return true;
    }

    // Main function
    public static void main(String[] args) {
        // Call the solve function
        solve();
    }
}

// <END-OF-CODE>
