import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    // The entry point of the program
    public static void main(String[] args) {
        // Initialize an empty string variable 's' to store the input DNA sequence
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Initialize a counter variable 'count' to keep track of the number of nucleotides (A, C, G, T)
        int count = 0;
        List<Integer> counter = new ArrayList<>();

        // Check if the input DNA sequence is empty or not
        if (s.isEmpty()) {
            // If the input DNA sequence is empty, return without doing anything
            return;
        }

        // Initialize the first element of the 'counter' list with an initial count of 0
        counter.add(0);

        // Split the input DNA sequence into a character array
        char[] li = s.toCharArray();

        // Iterate through each nucleotide in the 'li' array
        for (char nucleotide : li) {
            // Check if the current nucleotide is a valid nucleotide (A, C, G, T)
            if (nucleotide == 'A' || nucleotide == 'C' || nucleotide == 'G' || nucleotide == 'T') {
                // If the current nucleotide is valid, increment the 'count' variable
                count++;
            } else {
                // If the current nucleotide is not valid, append the current count to the 'counter' list and reset the 'count' variable to 0
                counter.add(count);
                count = 0;
            }
        }

        // Append the final count of nucleotides in the last sub-sequence to the 'counter' list
        counter.add(count);

        // Sort the 'counter' list in ascending order
        Collections.sort(counter);

        // Print the last element of the sorted 'counter' list, which represents the maximum count of nucleotides in any sub-sequence
        System.out.println(counter.get(counter.size() - 1));
    }
}
// <END-OF-CODE>
