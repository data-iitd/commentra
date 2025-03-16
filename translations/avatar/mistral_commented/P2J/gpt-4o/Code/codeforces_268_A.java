import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Ask user for the number of arrays (n) they want to input
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Create a list called 'q' to store these arrays
        List<List<String>> q = new ArrayList<>();
        
        // Use a for loop to iterate through the range of 'n'
        for (int i = 0; i < n; i++) {
            // Ask user for an array (a)
            String input = scanner.nextLine();
            String[] array = input.split(" ");
            List<String> list = new ArrayList<>();
            for (String element : array) {
                list.add(element);
            }
            // Append array 'a' to our list 'q'
            q.add(list);
        }
        
        // Initialize count variable
        int count = 0;

        // Use another for loop to iterate through each array in our list 'q'
        for (List<String> j : q) {
            // For each array 'j', use another for loop to iterate through every other array in our list 'q'
            for (List<String> k : q) {
                // Exclude the current array 'j' from comparison
                if (k == j) {
                    continue;
                }
                // Check if the last element of the second array 'k' matches the first element of the first array 'j'
                if (j.get(0).equals(k.get(k.size() - 1))) {
                    // If it does, increment our 'count' variable
                    count++;
                }
            }
        }

        // Finally, print out the value of our 'count' variable
        System.out.println(count);
        
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
