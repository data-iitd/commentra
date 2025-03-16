import java.util.Scanner;

public class VelocityDistance {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read initial velocities v1 and v2 from user input
        String[] velocities = scanner.nextLine().split(" ");
        int v1 = Integer.parseInt(velocities[0]);
        int v2 = Integer.parseInt(velocities[1]);
        
        // Read time t and distance increment d from user input
        String[] timeAndDistance = scanner.nextLine().split(" ");
        int t = Integer.parseInt(timeAndDistance[0]);
        int d = Integer.parseInt(timeAndDistance[1]);
        
        // Initialize acceleration factor and current velocity
        int a = 1;
        int v = v1;
        
        // Initialize total distance traveled
        int distance = 0;
        
        // Loop through each time unit from 0 to t-1
        for (int i = 0; i < t; i++) {
            // Check if the current velocity can exceed the maximum allowed velocity
            if (v - v2 > (t - i - 1) * d) {
                // Reverse acceleration direction if the velocity exceeds the limit
                a *= -1;
                // Adjust current velocity to not exceed the maximum allowed velocity
                v = (t - i - 1) * d + v2;
            }
            
            // Add current velocity to total distance
            distance += v;
            
            // Update current velocity based on acceleration direction
            v += a * d;
        }
        
        // Print the total distance traveled after t time units
        System.out.println(distance);
        
        scanner.close();
    }
}

// <END-OF-CODE>
