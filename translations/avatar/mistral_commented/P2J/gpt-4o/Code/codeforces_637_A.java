import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of strings to be processed
        int n = Integer.parseInt(scanner.nextLine());
        
        // Read the strings and split them by space
        String[] s = scanner.nextLine().split(" ");
        
        // Create a HashMap to store the occurrences of each string
        Map<String, Integer> w = new HashMap<>();
        
        // Count occurrences of each string
        for (String str : s) {
            w.put(str, w.getOrDefault(str, 0) + 1);
        }
        
        // Initialize variables for storing the index of the longest string and its value
        int c = -1;
        String a = "";
        
        // Iterate through each string in the HashMap
        for (String key : w.keySet()) {
            // If the current string has the maximum occurrences
            if (w.get(key) == Collections.max(w.values())) {
                // If its index in the original list is greater than the current index of the longest string
                int index = Arrays.asList(s).indexOf(key);
                if (index > c) {
                    // Update the longest string and its index
                    a = key;
                    c = index;
                }
            }
        }
        
        // Print the longest string
        System.out.println(a);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
