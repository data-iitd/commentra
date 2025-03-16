import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of events (n) and the starting time (s)
        int n = scanner.nextInt();
        int s = scanner.nextInt();
        
        // Initialize the maximum additional time to 0
        int c = 0;
        
        // Loop through each event
        for (int i = 0; i < n; i++) {
            // Read the finish time (f) and the time taken (t) for the current event
            int f = scanner.nextInt();
            int t = scanner.nextInt();
            
            // Calculate the additional time required if the event starts at time s
            int x = t - (s - f);
            
            // Update the maximum additional time if the current event requires more time
            if (x > c) {
                c = x;
            }
        }
        
        // Print the total time including the maximum additional time
        System.out.println(s + c);
    }
}
