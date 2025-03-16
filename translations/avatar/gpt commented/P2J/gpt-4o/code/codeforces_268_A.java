import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of lists to be processed
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Initialize a list to store the input lists
        List<List<String>> q = new ArrayList<>();
        
        // Initialize a counter to keep track of the matching conditions
        int count = 0;
        
        // Loop to read 'n' lines of input and store them in the list 'q'
        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();
            String[] elements = line.split(" ");
            List<String> list = new ArrayList<>();
            for (String element : elements) {
                list.add(element);
            }
            q.add(list);
        }
        
        // Nested loop to compare each list in 'q' with every other list
        for (List<String> j : q) {
            for (List<String> k : q) {
                // Skip comparison if both lists are the same
                if (k.equals(j)) {
                    continue;
                }
                // Check if the first element of list 'j' matches the last element of list 'k'
                if (j.get(0).equals(k.get(k.size() - 1))) {
                    // Increment the count if the condition is met
                    count++;
                }
            }
        }
        
        // Print the final count of matching conditions
        System.out.println(count);
        
        scanner.close();
    }
}

// <END-OF-CODE>
