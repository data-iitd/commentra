
import java.util.Scanner;
import java.util.Arrays;

public class s120583500{
    public static void main(String[] args) {
        // Declare a variable to hold the input string
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Initialize a counter for consecutive valid characters and a slice to hold counts
        int count = 0;
        int[] counter = new int[1];

        // If the input string is empty, exit the function
        if (s.equals("")) {
            return;
        }

        // Start the counter with an initial value of 0
        counter[0] = 0;
        // Split the input string into a slice of individual characters
        String[] li = s.split("");

        // Iterate over each character in the slice
        for (String c : li) {
            // Check if the character is one of the valid DNA bases
            if (c.equals("A") || c.equals("C") || c.equals("G") || c.equals("T")) {
                // Increment the count for consecutive valid characters
                count++;
            } else {
                // If an invalid character is encountered, store the current count
                counter = Arrays.copyOf(counter, counter.length + 1);
                counter[counter.length - 1] = count;
                // Reset the count for the next sequence
                count = 0;
            }
        }

        // Append the count of the last sequence of valid characters
        counter = Arrays.copyOf(counter, counter.length + 1);
        counter[counter.length - 1] = count;
        // Sort the counts to find the maximum consecutive valid characters
        Arrays.sort(counter);
        // Print the maximum count of consecutive valid characters
        System.out.println(counter[counter.length - 1]);
    }
}
