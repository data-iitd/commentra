import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Function to solve the problem
    public static boolean solve() {
        // Initialize variables to track the longest string and its count
        int maxsize = 0;
        int maxcnt = 0;
        int ans_num = -1; // Index of the longest string
        int ans_num2 = -1; // Index of the most frequent string
        List<String> str_v = new ArrayList<>(); // List to store input strings
        
        // Variable to read input strings
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String in = scanner.next();
            str_v.add(in); // Store the input string in the list
            if (maxsize < in.length()) { // Check if the current string is the longest so far
                maxsize = in.length(); // Update the length of the longest string
                ans_num = str_v.size() - 1; // Store the index of the longest string
            }
        }
        
        // Count occurrences of each string and find the most frequent string
        Map<String, Integer> frequencyMap = new HashMap<>();
        for (String s : str_v) {
            frequencyMap.put(s, frequencyMap.getOrDefault(s, 0) + 1); // Count occurrences
        }
        
        for (int i = 0; i < str_v.size(); i++) {
            String currentString = str_v.get(i);
            int cnt = frequencyMap.get(currentString);
            if (maxcnt < cnt) { // Check if the current string is the most frequent so far
                maxcnt = cnt; // Update the count of the most frequent string
                ans_num2 = i; // Store the index of the most frequent string
            }
        }
        
        // Output the most frequent and the longest string
        System.out.println(str_v.get(ans_num2) + " " + str_v.get(ans_num));
        
        return true; // Return true indicating success
    }

    // Main function to call the solve function
    public static void main(String[] args) {
        solve();
    }
}

// <END-OF-CODE>
