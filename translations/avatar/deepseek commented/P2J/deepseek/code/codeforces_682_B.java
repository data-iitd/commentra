import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt();
        
        // Read the list of elements
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        
        // Initialize variables
        boolean[] used = new boolean[100001];  // Array to keep track of used elements
        int uniqueCount = 0;  // Counter for unique elements
        
        // Sort the list
        Arrays.sort(l);
        
        // Iterate through the list to find the maximum number of unique elements
        for (int i = 0; i < n; i++) {
            if (!used[l[i]]) {
                used[l[i]] = true;  // Mark the element as used
                uniqueCount++;  // Increment the counter for unique elements
            }
        }
        
        // Print the result
        System.out.println(uniqueCount);  // Print the maximum number of unique elements
    }
}
