import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an array to hold three card values
        int[] c = new int[3];
        
        // Continuously read three integers until EOF is reached
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            // Initialize a character array to track the presence of cards
            char[] card = new char[10];
            int i;
            int count = 0; // Initialize count of valid card positions
            int sum = c[0] + c[1]; // Calculate the sum of the first two card values
            
            // Mark the positions of the cards in the card array
            for (i = 0; i < 3; i++) {
                card[c[i] - 1] = 1; // Set the position corresponding to the card value
            }
            
            // Count how many card positions are available that do not exceed the total of 20
            for (i = 0; i < 10; i++) {
                // Check if the card position is unoccupied and if adding it to the sum does not exceed 20
                if (card[i] == 0 && sum + i + 1 <= 20) {
                    count++; // Increment the count for each valid position
                }
            }
            
            // Determine if there are at least 4 valid positions available
            if (count >= 4) {
                System.out.println("YES"); // Output YES if there are enough valid positions
            }
            else {
                System.out.println("NO"); // Output NO if there are not enough valid positions
            }
        }
    }
}
