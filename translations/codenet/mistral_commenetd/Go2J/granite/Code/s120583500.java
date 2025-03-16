

import java.util.Scanner;
import java.util.Arrays;

public class s120583500{
    public static void main(String[] args) {
        // Initialize an empty string variable's' to store the input DNA sequence
        String s = "";

        // Read the input DNA sequence from the standard input using Scanner class
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLine()) {
            s = scanner.nextLine();
        }

        // Initialize a counter variable 'count' to keep track of the number of nucleotides (A, C, G, T) in the current nucleotide sequence
        // and a list 'counter' to store the count of nucleotides in each sub-sequence between non-nucleotide characters
        int count = 0;
        java.util.List<Integer> counter = new java.util.ArrayList<>();

        // Check if the input DNA sequence is empty or not
        if (s.isEmpty()) {
            // If the input DNA sequence is empty, return without doing anything
            return;
        }

        // Initialize the first element of the 'counter' list with an initial count of 0
        counter.add(0);

        // Split the input DNA sequence into a list 'li' of individual nucleotides using String.split() method
        String[] li = s.split("");

        // Iterate through each nucleotide in the 'li' list using a for loop
        for (String nucleotide : li) {
            // Check if the current nucleotide is a valid nucleotide (A, C, G, T) or not
            if (nucleotide.equals("A") || nucleotide.equals("C") || nucleotide.equals("G") || nucleotide.equals("T")) {
                // If the current nucleotide is a valid nucleotide, increment the 'count' variable
                count++;
            } else {
                // If the current nucleotide is not a valid nucleotide, add the current count to the 'counter' list and reset the 'count' variable to 0
                counter.add(count);
                count = 0;
            }
        }

        // Add the final count of nucleotides in the last sub-sequence to the 'counter' list
        counter.add(count);

        // Sort the 'counter' list in ascending order using Collections.sort() method
        Collections.sort(counter);

        // Print the last element of the sorted 'counter' list, which represents the maximum count of nucleotides in any sub-sequence
        System.out.println(counter.get(counter.size() - 1));
    }
}
