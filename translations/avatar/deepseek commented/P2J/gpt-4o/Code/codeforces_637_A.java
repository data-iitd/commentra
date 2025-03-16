import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        
        // Read the integer n
        int n = Integer.parseInt(st.nextToken());
        
        // Read the list of strings s
        String[] s = input.readLine().trim().split(" ");
        
        // Create a Counter-like map to count occurrences of each string
        Map<String, Integer> w = new HashMap<>();
        for (String str : s) {
            w.put(str, w.getOrDefault(str, 0) + 1);
        }
        
        // Reverse the list s
        String[] reversedS = new String[n];
        for (int i = 0; i < n; i++) {
            reversedS[i] = s[n - 1 - i];
        }
        
        // Initialize two variables c and a to -1 and 0 respectively
        int c = -1;
        String a = "";
        
        // Iterate over the items in the map w
        for (String key : w.keySet()) {
            // Check if the count of the item is equal to the maximum count in the map w
            if (w.get(key).equals(Collections.max(w.values()))) {
                // Check if the index of the item in the reversed list reversedS is greater than the current value of c
                int index = Arrays.asList(reversedS).indexOf(key);
                if (index > c) {
                    // Update the value of a to the current item and update the value of c to the index of the current item in the reversed list reversedS
                    a = key;
                    c = index;
                }
            }
        }
        
        // Print the value of a
        System.out.println(a);
    }
}
