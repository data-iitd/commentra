
import java.util.Scanner;

public class codeforces_387_B{
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements in round_complexity and george_complexity
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Read the complexities of the rounds
        int[] round_complexity = new int[n];
        for (int i = 0; i < n; i++) {
            round_complexity[i] = scanner.nextInt();
        }
        
        // Read the complexities of George's challenges
        int[] george_complexity = new int[m];
        for (int i = 0; i < m; i++) {
            george_complexity[i] = scanner.nextInt();
        }
        
        // Initialize counters for both lists
        int i = 0, j = 0;
        
        // Loop through both lists to compare complexities
        while (i < n && j < m) {
            // Increment i if the current round complexity is less than or equal to George's complexity
            i += (round_complexity[i] <= george_complexity[j])? 1 : 0;
            
            // Increment j to move to the next element in george_complexity
            j += 1;
        }
        
        // Print the number of rounds George can solve
        System.out.println(n - i);
    }
}

// Check if the script is run as the main program
if (args.length == 0) {
    codeforces_387_B.main(null);
}

