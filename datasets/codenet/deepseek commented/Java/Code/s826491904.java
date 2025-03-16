
import java.util.*;

public class Main {
    //-------------------------------------------------------------//
    // The main method is the entry point of the program.
    // It is public, static, and final to follow Java conventions.
    public static final void main(String[] args) {
        new Main().solve();
    }
    //-------------------------------------------------------------//
    // A private Scanner instance to read input from the console.
    private final Scanner sc = new Scanner(System.in);

    // The solve method contains the logic of the program.
    void solve() {
        // Read the number of elements in the sequence.
        int N = sc.nextInt();
        
        // Initialize max and min with the first element of the sequence.
        int max, min; 
        max = min = sc.nextInt();
        
        // Loop through the remaining elements of the sequence.
        for (int i = 1; i < N; i++) {
            int in = sc.nextInt();
            // Update max and min accordingly.
            max = Math.max(max, in);
            min = Math.min(min, in);
        }
        
        // Print the difference between max and min.
        System.out.println(max - min);
    }
}

