import java.util.Scanner;

public class GameWinner {
    // Function to determine the winner of the game
    public static void run() {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements and the target value from input
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        int[] a = new int[100]; // Array to store the elements
        
        // Read the elements into the array
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Allocate memory for the dynamic programming array
        int[] dp = new int[k + 1];

        // Iterate over each possible value from 1 to k
        for (int i = 1; i <= k; i++) {
            int win = 0; // Variable to determine if the current player can win

            // Check each element to see if it can lead to a winning position
            for (int j = 0; j < n && a[j] <= i; j++) {
                // If there exists a move that leads to a losing position for the opponent
                if (dp[i - a[j]] == 0) {
                    win = 1; // Current player can win
                }
            }
            
            // Store the result in the dp array: 1 if the current player can win, 0 otherwise
            dp[i] = win;
        }

        // Output the result: "First" if the first player can win, otherwise "Second"
        System.out.println(dp[k] == 1 ? "First" : "Second");
    }

    // Main function to execute the program
    public static void main(String[] args) {
        run(); // Call the run function to execute the game logic
    }
}

// <END-OF-CODE>
