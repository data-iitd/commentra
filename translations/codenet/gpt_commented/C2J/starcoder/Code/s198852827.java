import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of test cases
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        
        // Loop through each test case
        for(int i = 0; i < N; i++) {
            // Read the time and coordinates for each test case
            int t = sc.nextInt();
            int x = sc.nextInt();
            int y = sc.nextInt();
            
            // Calculate the time left after accounting for the previous time and the distance traveled
            int tmp = t - nt - (Math.abs(x - nx) + Math.abs(y - ny));
            
            // Check if the remaining time is negative or odd
            if(tmp < 0 || tmp % 2) {
                // If so, print "No" and exit the program
                System.out.println("No");
                return;
            }
            
            // Update the current position and time for the next iteration
            nt = t; // Update the previous time
            nx = x; // Update the previous x coordinate
            ny = y; // Update the previous y coordinate
        }
        
        // If all test cases are valid, print "Yes"
        System.out.println("Yes");
    }
}
