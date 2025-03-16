import java.util.*;

class Main {
    public static void main(String[] args) {
        
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the maximum number of 500, 100, and 50 denomination notes
        int a = sc.nextInt(); // Maximum number of 500 notes
        int b = sc.nextInt(); // Maximum number of 100 notes
        int c = sc.nextInt(); // Maximum number of 50 notes
        
        // Read the target amount to be formed using the notes
        int x = sc.nextInt(); // Target amount
        
        // Initialize a counter to keep track of the number of ways to form the amount
        int res = 0;
        
        // Iterate through all possible counts of 500 notes
        for (int i = 0; i <= a; i++) {
            // Iterate through all possible counts of 100 notes
            for (int j = 0; j <= b; j++) {
                // Iterate through all possible counts of 50 notes
                for (int k = 0; k <= c; k++) {
                    // Calculate the total value formed by the current combination of notes
                    int total = 500 * i + 100 * j + 50 * k;
                    
                    // Check if the total matches the target amount
                    if (total == x) {
                        // Increment the counter if a valid combination is found
                        res++;
                    }
                }
            }
        }
        
        // Output the total number of combinations that can form the target amount
        System.out.println(res);
    }
}
