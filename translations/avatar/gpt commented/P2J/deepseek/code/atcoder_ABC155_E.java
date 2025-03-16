import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int pp = 0; // Initialize the total score
        int na = 0; // Initialize carry-over value

        // Process the string in reverse order
        for (int i = s.length() - 1; i >= 0; i--) {
            int cc = na + Character.getNumericValue(s.charAt(i)); // Calculate the current value with carry-over
            na = 0; // Reset carry-over for the next iteration

            // Determine how to update the total score based on the current value
            if (cc <= 4) {
                pp += cc; // If the value is 4 or less, add it directly to the score
            } else {
                na = 1; // Set carry-over if the value exceeds 4
                if (i == 0) {
                    pp += 1; // If it's the last digit, add 1 to the score
                }
                pp += 10 - cc; // Add the difference to the score
            }
        }

        System.out.println(pp); // Output the final score
    }
}
