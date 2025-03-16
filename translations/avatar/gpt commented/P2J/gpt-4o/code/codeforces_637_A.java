import java.util.*;
import java.io.*;

public class MostFrequentElement {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        
        // Read the number of elements
        int n = Integer.parseInt(input.readLine().trim());
        
        // Read the input string and split it into a list
        String[] s = input.readLine().trim().split(" ");
        
        // Count the occurrences of each element using a HashMap
        Map<String, Integer> countMap = new HashMap<>();
        for (String str : s) {
            countMap.put(str, countMap.getOrDefault(str, 0) + 1);
        }
        
        // Reverse the array to process elements in reverse order
        Collections.reverse(Arrays.asList(s));
        
        // Initialize variables to track the index of the most frequent element and its value
        int c = -1;
        String a = "";
        
        // Find the maximum count
        int maxCount = Collections.max(countMap.values());
        
        // Iterate through each unique element in the count map
        for (String key : countMap.keySet()) {
            // Check if the current element's count is equal to the maximum count
            if (countMap.get(key) == maxCount) {
                // If the index of the current element in the reversed list is greater than the current index
                int index = Arrays.asList(s).indexOf(key);
                if (index > c) {
                    // Update the most frequent element and its index
                    a = key;
                    c = index;
                }
            }
        }
        
        // Print the most frequent element that appears last in the original order
        System.out.println(a);
    }
}
// <END-OF-CODE>
