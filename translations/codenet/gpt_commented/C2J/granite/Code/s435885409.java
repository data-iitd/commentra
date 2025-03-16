
import java.util.Scanner;

// Function to calculate the score based on user input
public class s435885409{
    public static int calc_score() {
        int out = 0; // Initialize the number of outs
        String str = ""; // Buffer to store user input
        int score = 0; // Initialize the score
        int base = 0; // Initialize the number of players on base
        
        // Loop until there are 3 outs
        while (out < 3) {
            Scanner scanner = new Scanner(System.in);
            str = scanner.nextLine(); // Read user input into str
            
            // Check if the input is "OUT"
            if (str.equals("OUT")) {
                out++; // Increment the out count
            } 
            // Check if the input is "HIT"
            else if (str.equals("HIT")) {
                // If all bases are occupied, score a point
                if (base == 3) {
                    score++; // Increment the score
                } else {
                    base++; // Move a player to the next base
                }
            } 
            // Check if the input is "HOMERUN"
            else if (str.equals("HOMERUN")) {
                score += (base + 1); // Score based on players on base plus the hitter
                base = 0; // Reset bases after a homerun
            }
        }
        
        // Return the calculated score
        return score;
    }
    
    // s435885409 function to execute the program
    public static void main(String[] args) {
        int n; // Variable to hold the number of innings
        int inning = 0; // Initialize the inning count
        
        // Read the number of innings from user input
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        
        // Loop through the number of innings
        while (inning < n) {
            System.out.println(calc_score()); // Calculate and print the score for each inning
            inning++; // Increment the inning count
        }
    }
}

