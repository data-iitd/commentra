import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        
        // Read the number of elements
        int n = Integer.parseInt(input.readLine());
        
        // Read the input string, remove the last character (newline), and split it into a list
        String[] s = input.readLine().split(" ");
        
        // Count the occurrences of each element in the list
        Map<String, Integer> w = new HashMap<>();
        for (String word : s) {
            w.put(word, w.getOrDefault(word, 0) + 1);
        }
        
        // Initialize variables to track the index of the most frequent element and its value
        String a = "";
        int c = -1;
        
        // Iterate through each unique element in the count dictionary
        for (String i : w.keySet()) {
            // Check if the current element's count is equal to the maximum count
            if (w.get(i) == Collections.max(w.values())) {
                // If the index of the current element in the original list is greater than the current index
                if (findIndex(s, i) > c) {
                    // Update the most frequent element and its index
                    a = i;
                    c = findIndex(s, i);
                }
            }
        }
        
        // Print the most frequent element that appears last in the original order
        System.out.println(a);
    }
    
    // Helper method to find the index of an element in an array
    public static int findIndex(String[] array, String target) {
        for (int i = 0; i < array.length; i++) {
            if (array[i].equals(target)) {
                return i;
            }
        }
        return -1;
    }
}
