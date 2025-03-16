import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of strings to be processed
        int n = scanner.nextInt();
        
        // Initialize a HashMap to count occurrences of each string
        HashMap<String, Integer> s = new HashMap<>();
        
        // Read n strings into a list
        String[] l = new String[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.next();
        }
        
        // Initialize a flag to determine if the conditions are met
        String f = "Yes";
        
        // Initialize an index variable to track the previous string
        int i = -1;
        
        // Iterate through each string in the list
        for (String v : l) {
            // Increment the count for the current string
            s.put(v, s.getOrDefault(v, 0) + 1);
            
            // Check if the current string has appeared more than once
            if (s.get(v) >= 2) {
                f = "No";  // Set flag to 'No' if a duplicate is found
            }
            
            // Check if the previous string's last character does not match the current string's first character
            if (i != -1 && l[i].charAt(l[i].length() - 1) != v.charAt(0)) {
                f = "No";  // Set flag to 'No' if the character condition is violated
            }
            
            // Update the index to the current string's index
            i += 1;
        }
        
        // Print the final result based on the checks
        System.out.println(f);
    }
}
