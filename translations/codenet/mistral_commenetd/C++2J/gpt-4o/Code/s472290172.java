import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        String str = scanner.next(); // Read the input string from the standard input

        int max = 0, cnt = 0; // Initialize two integer variables 'max' and 'cnt' with zero values

        // Iterate through each character in the input string
        for (char sc : str.toCharArray()) {
            // Check if the current character is a valid nucleotide (A, C, G or T)
            if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') {
                cnt++; // Increment the count if the character is a valid nucleotide
            } else { // Otherwise, reset the count to zero
                cnt = 0;
            }

            // Update the maximum count if the current count is greater than the previous maximum
            max = Math.max(max, cnt);
        }

        // Print the maximum count of valid nucleotides found in the input string
        System.out.println(max);
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
