import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements from the user
        int n = scanner.nextInt();
        // Read the list of integers from the user input
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextInt());
        }
        
        // Initialize variables to track the current level and the number of turns
        int currentLevel = 0;
        int counter = 0;
        int counterTurns = -1;
        
        // Start a while loop that continues until all elements are processed
        while (counter < a.size()) {
            // Increment the turn counter
            counterTurns++;
            // Iterate over the list 'a' to process each element
            for (int i = 0; i < a.size(); i++) {
                // Check if the element is not -1 and is less than or equal to the current level
                if (a.get(i) != -1 && a.get(i) <= currentLevel) {
                    // Increment the counter and mark the element as processed
                    counter++;
                    a.set(i, -1);
                }
            }
            // Reverse the list 'a' to process elements in a different order in the next iteration
            Collections.reverse(a);
        }
        
        // Print the number of turns taken to process all elements
        System.out.println(counterTurns);
    }
}
