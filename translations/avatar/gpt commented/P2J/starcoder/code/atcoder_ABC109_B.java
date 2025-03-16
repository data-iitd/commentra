import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of strings to be processed
        int n = sc.nextInt();
        
        // Initialize a HashMap to count occurrences of each string
        HashMap<String, Integer> s = new HashMap<String, Integer>();
        
        // Read n strings into a list
        List<String> l = new ArrayList<String>();
        for (int i = 0; i < n; i++) {
            l.add(sc.next());
        }
        
        // Initialize a flag to determine if the conditions are met
        String f = "Yes";
        
        // Initialize an index variable to track the previous string
        int i = -1;
        
        // Iterate through each string in the list
        for (String v : l) {
            // Increment the count for the current string
            if (s.containsKey(v)) {
                s.put(v, s.get(v) + 1);
            } else {
                s.put(v, 1);
            }
            
            // Check if the current string has appeared more than once
            if (s.get(v) >= 2) {
                f = "No";  // Set flag to 'No' if a duplicate is found
            
            // Check if the previous string's last character does not match the current string's first character
            if (i!= -1 && l.get(i).charAt(l.get(i).length() - 1)!= v.charAt(0)) {
                f = "No";  // Set flag to 'No' if the character condition is violated
            
            // Update the index to the current string's index
            i++;
        }
        
        // Print the final result based on the checks
        System.out.println(f);
    }
}

