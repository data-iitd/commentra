import java.util.Scanner;

public class CardGame {
    public static void main(String[] args) {
        // Declare a Scanner to read input
        Scanner scanner = new Scanner(System.in);
        
        // Continuously read three integers until EOF is reached
        while (scanner.hasNextInt()) {
            // Declare an array to hold three card values
            int[] c = new int[3];
            c[0] = scanner.nextInt();
            c[1] = scanner.nextInt();
            c[2] = scanner.nextInt();
            
            // Initialize a boolean array to track the presence of cards
            boolean[] card = new boolean[10];
            int count = 0; // Initialize count of valid card positions
            int sum = c[0] + c[1]; // Calculate the sum of the first two card values
            
            // Mark the positions of the cards in the card array
            for (int i = 0; i < 3; i++) {
                card[c[i] - 1] = true; // Set the position corresponding to the card value
            }
            
            // Count how many card positions are available that do not exceed the total of 20
            for (int i = 0; i < 10; i++) {
                // Check if the card position is unoccupied and if adding it to the sum does not exceed 20
                if (!card[i] && sum + (i + 1) <= 20) {
                    count++; // Increment the count for each valid position
                }
            }
            
            // Determine if there are at least 4 valid positions available
            if (count >= 4) {
                System.out.println("YES"); // Output YES if there are enough valid positions
            } else {
                System.out.println("NO"); // Output NO if there are not enough valid positions
            }
        }
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
