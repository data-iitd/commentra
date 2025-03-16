import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = Integer.parseInt(scanner.nextLine());
        
        // Read the elements and count their occurrences using HashMap
        Map<Integer, Integer> w = new HashMap<>();
        String[] elements = scanner.nextLine().split(" ");
        for (String element : elements) {
            int num = Integer.parseInt(element);
            w.put(num, w.getOrDefault(num, 0) + 1);
        }
        
        // Initialize a counter for pairs that sum to zero
        int c = 0;
        
        // Iterate through each unique number in the map
        for (int i : w.keySet()) {
            // Check if the number is zero
            if (i == 0) {
                // For zero, count pairs (w[i] choose 2) since both numbers are the same
                if (w.get(i) > 1) {
                    c += w.get(i) * (w.get(i) - 1);
                }
            } else {
                // Check if the negative counterpart exists in the map
                if (w.containsKey(-i)) {
                    // Count pairs formed by the number and its negative counterpart
                    c += w.get(i) * w.get(-i);
                }
            }
        }
        
        // Since each pair is counted twice, divide the total count by 2 before printing
        System.out.println(c / 2);
    }
}
