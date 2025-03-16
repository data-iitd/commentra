public class BaseballScoreCalculator {
    // Method to calculate the score based on user input
    public static int calcScore() {
        int out = 0; // Initialize the number of outs
        String[] str = new String[100]; // Buffer to store user input
        int score = 0; // Initialize the score
        int base = 0; // Initialize the number of players on base

        // Loop until there are 3 outs
        while (out < 3) {
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            str[out] = scanner.nextLine(); // Read user input into str

            // Check if the input is "OUT"
            if (str[out].equals("OUT")) {
                out++; // Increment the out count
            }
            // Check if the input is "HIT"
            else if (str[out].equals("HIT")) {
                // If all bases are occupied, score a point
                if (base == 3) {
                    score++; // Increment the score
                } else {
                    base++; // Move a player to the next base
                }
            }
            // Check if the input is "HOMERUN"
            else if (str[out].equals("HOMERUN")) {
                score += (base + 1); // Score based on players on base plus the hitter
                base = 0; // Reset bases after a homerun
            }
        }

        // Return the calculated score
        return score;
    }

    // Main method to execute the program
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of innings from user input
        int inning = 0; // Initialize the inning count

        // Loop through the number of innings
        while (inning < n) {
            System.out.println(calcScore()); // Calculate and print the score for each inning
            inning++; // Increment the inning count
        }
    }
}
