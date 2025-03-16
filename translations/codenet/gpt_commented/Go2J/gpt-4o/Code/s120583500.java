import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable to hold the input string
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Initialize a counter for consecutive valid characters and a list to hold counts
        int count = 0;
        List<Integer> counter = new ArrayList<>();

        // If the input string is empty, exit the function
        if (s.isEmpty()) {
            return;
        }

        // Start the counter with an initial value of 0
        counter.add(0);

        // Iterate over each character in the string
        for (char ch : s.toCharArray()) {
            // Check if the character is one of the valid DNA bases
            if (ch == 'A' || ch == 'C' || ch == 'G' || ch == 'T') {
                // Increment the count for consecutive valid characters
                count++;
            } else {
                // If an invalid character is encountered, store the current count
                counter.add(count);
                // Reset the count for the next sequence
                count = 0;
            }
        }

        // Append the count of the last sequence of valid characters
        counter.add(count);
        // Sort the counts to find the maximum consecutive valid characters
        Collections.sort(counter);
        // Print the maximum count of consecutive valid characters
        System.out.println(counter.get(counter.size() - 1));
    }
}
// <END-OF-CODE>
