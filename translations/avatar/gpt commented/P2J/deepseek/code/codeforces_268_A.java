import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of lists to be processed
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Initialize an empty list to store the input lists
        List<List<String>> q = new ArrayList<>();
        
        // Initialize a counter to keep track of the matching conditions
        int count = 0;
        
        // Loop to read 'n' lines of input and store them in the list 'q'
        for (int i = 0; i < n; i++) {
            // Read a line of input, split it into a list of strings, and add it to 'q'
            String[] a = scanner.nextLine().split(" ");
            List<String> list = new ArrayList<>();
            for (String s : a) {
                list.add(s);
            }
            q.add(list);
        }
        
        // Nested loop to compare each list in 'q' with every other list
        for (int j = 0; j < q.size(); j++) {
            for (int k = 0; k < q.size(); k++) {
                // Skip comparison if both lists are the same
                if (j == k) {
                    continue;
                }
                // Check if the first element of list 'j' matches the last element of list 'k'
                if (q.get(j).get(0).equals(q.get(k).get(q.get(k).size() - 1))) {
                    // Increment the count if the condition is met
                    count++;
                }
            }
        }
        
        // Print the final count of matching conditions
        System.out.println(count);
    }
}
