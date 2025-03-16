import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of test cases
        int n = scanner.nextInt();
        
        // Initialize a HashMap to store the occurrences of numbers
        Map<Integer, Integer> w = new HashMap<>();
        
        // Read the numbers and count their occurrences
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            w.put(num, w.getOrDefault(num, 0) + 1);
        }
        
        // Initialize a counter 'c' to store the result
        int c = 0;
        
        // Iterate through each number 'i' in the HashMap 'w'
        for (int i : w.keySet()) {
            // If the number 'i' is zero, then add its occurrences multiplied by (its occurrences - 1) to the counter 'c'
            if (i == 0) {
                c += w.get(i) * (w.get(i) - 1);
            }
            // If the number '-i' is present in the HashMap 'w', then add its occurrences multiplied by the occurrences of 'i' to the counter 'c'
            else if (w.containsKey(-i)) {
                c += w.get(i) * w.get(-i);
            }
        }
        
        // Print the result divided by 2
        System.out.println(c / 2);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
