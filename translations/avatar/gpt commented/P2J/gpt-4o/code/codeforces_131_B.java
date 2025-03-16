import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt();
        
        // Read the elements and count their occurrences using a HashMap
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }
        
        // Initialize a counter for pairs that sum to zero
        long c = 0;
        
        // Iterate through each unique number in the map
        for (int key : countMap.keySet()) {
            // Check if the number is zero
            if (key == 0) {
                // For zero, count pairs (w[i] choose 2) since both numbers are the same
                int count = countMap.get(key);
                c += (long) count * (count - 1);
            } else {
                // Check if the negative counterpart exists in the map
                if (countMap.containsKey(-key)) {
                    // Count pairs formed by the number and its negative counterpart
                    c += (long) countMap.get(key) * countMap.get(-key);
                }
            }
        }
        
        // Since each pair is counted twice, divide the total count by 2 before printing
        System.out.println(c / 2);
        
        scanner.close();
    }
}

// <END-OF-CODE>
