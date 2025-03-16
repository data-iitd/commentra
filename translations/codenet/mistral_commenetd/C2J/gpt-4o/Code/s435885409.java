import java.util.Scanner;

public class BaseballScoreCalculator {

    // Function to calculate the score for each inning
    public static int calcScore() {
        int out = 0; // Initialize the number of outs to 0
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        int score = 0; // Initialize the score to 0
        int base = 0; // Initialize the number of bases to 0

        // Loop through the three events in each inning
        while (out < 3) {
            System.out.print("Enter the event for this at bat (HIT, HOMERUN or OUT): "); // Ask for the event
            String event = scanner.next(); // Read the event from the standard input

            // Check if the event is OUT
            if (event.equals("OUT")) {
                out++; // Increment the number of outs
            }
            // Check if the event is HIT
            else if (event.equals("HIT")) {
                // If there are already three bases, increment the score
                if (base == 3) {
                    score++;
                }
                // If not, increment the number of bases
                else {
                    base++;
                }
            }
            // Check if the event is HOMERUN
            else if (event.equals("HOMERUN")) {
                score += (base + 1); // Add the number of bases and 1 to the score
                base = 0; // Reset the number of bases to 0
            }
        }

        // Return the score for this inning
        return score;
    }

    // Main function to read the number of innings and call calcScore() for each inning
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        System.out.print("Enter the number of innings: ");
        int n = scanner.nextInt(); // Read the number of innings from the standard input
        int inning = 0; // Initialize the current inning number to 0

        // Loop through each inning and call calcScore() to calculate the score
        while (inning < n) {
            int score = calcScore(); // Call calcScore() to calculate the score for this inning
            System.out.println(score); // Print the score for this inning
            inning++; // Increment the current inning number
        }
    }
}

// <END-OF-CODE>
