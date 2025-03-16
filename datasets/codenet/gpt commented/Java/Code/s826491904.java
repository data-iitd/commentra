import java.util.*;

public class Main {
    //-------------------------------------------------------------//
    // Entry point of the program
    public static final void main(String[] args) {
        // Create an instance of Main and call the solve method
        new Main().solve();
    }
    //-------------------------------------------------------------//
    
    // Scanner object to read input from the console
    private final Scanner sc = new Scanner(System.in);

    // Method to solve the problem
    void solve() {
        // Read the number of integers to process
        int N = sc.nextInt();
        
        // Initialize max and min with the first input value
        int max, min; 
        max = min = sc.nextInt();
        
        // Loop through the remaining N-1 integers to find max and min
        for (int i = 1; i < N; i++) {
            // Read the next integer
            int in = sc.nextInt();
            
            // Update max if the current integer is greater
            max = Math.max(max, in);
            // Update min if the current integer is smaller
            min = Math.min(min, in);
        }
        
        // Output the difference between max and min
        System.out.println(max - min);
    }
}
