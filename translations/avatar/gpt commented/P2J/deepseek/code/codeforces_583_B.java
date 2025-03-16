import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of elements
        int n = scanner.nextInt();
        
        // Read a line of input, split it by spaces, and convert it to a list of integers
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextInt());
        }
        
        // Initialize the current level and counters
        int currentLevel = 0;
        int counter = 0;
        int counterTurns = -1; // Start with -1 to account for the first turn increment
        
        // Loop until all elements have been processed
        while (counter < a.size()) {
            counterTurns += 1; // Increment the turn counter
            
            // Iterate through the list to find elements that can be processed
            for (int i = 0; i < a.size(); i++) {
                // Check if the current element is not marked (-1) and is less than or equal to the current counter
                if (a.get(i) != -1 && a.get(i) <= counter) {
                    counter += 1; // Increment the counter as we can process this element
                    a.set(i, -1); // Mark the element as processed by setting it to -1
                }
            }
            
            // Reverse the list to prepare for the next round of processing
            for (int i = 0; i < a.size() / 2; i++) {
                int temp = a.get(i);
                a.set(i, a.get(a.size() - 1 - i));
                a.set(a.size() - 1 - i, temp);
            }
        }
        
        // Print the total number of turns taken to process all elements
        System.out.println(counterTurns);
    }
}
