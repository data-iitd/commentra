import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of test cases
        int n = Integer.parseInt(scanner.nextLine());
        
        // Initialize a HashMap to store the occurrences of numbers
        Map<Integer, Integer> w = new HashMap<>();
        
        // Read the numbers and count their occurrences
        String[] numbers = scanner.nextLine().split(" ");
        for (String numStr : numbers) {
            int num = Integer.parseInt(numStr);
            w.put(num, w.getOrDefault(num, 0) + 1);
        }
        
        // Initialize a counter to store the result
        int c = 0;
        
        // Iterate through each number in the HashMap
        for (int i : w.keySet()) {
            // If the number is zero, then add its occurrences multiplied by (its occurrences - 1) to the counter 'c'
            if (i == 0) {
                c += w.get(i) * (w.get(i) - 1);
            }
            // If the number '-i' is present in the HashMap, then add its occurrences multiplied by the occurrences of 'i' to the counter 'c'
            else if (w.containsKey(-i)) {
                c += w.get(i) * w.get(-i);
            }
        }
        
        // Print the result divided by 2
        System.out.println(c / 2);
    }
}
