import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of strings to be processed
        int n = Integer.parseInt(scanner.nextLine());
        
        // Read the strings and split the last string by space
        String[] s = scanner.nextLine().split(" ");
        
        // Create a HashMap to store the occurrences of each string
        Map<String, Integer> w = new HashMap<>();
        
        // Populate the HashMap with the occurrences of each string
        for (String str : s) {
            w.put(str, w.getOrDefault(str, 0) + 1);
        }
        
        // Initialize variables for storing the index of the longest string and its value
        int c = -1, a = 0;
        
        // Iterate through each string in the HashMap
        for (String i : w.keySet()) {
            // If the current string has the maximum occurrences
            if (w.get(i) == Collections.max(w.values())) {
                // If its index in the original array is greater than the current index of the longest string
                if (java.util.Arrays.asList(s).indexOf(i) > c) {
                    // Update the longest string and its index
                    a = java.util.Arrays.asList(s).indexOf(i);
                    c = a;
                }
            }
        }
        
        // Print the longest string
        System.out.println(s[a]);
    }
}
