import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Optimize input/output operations
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements and the constant c
        int n = scanner.nextInt();
        int c = scanner.nextInt();

        // Initialize vectors to store positions and velocities
        int[] x = new int[n+1];
        int[] v = new int[n+1];

        // Read the positions and velocities of the elements
        for(int i = 1; i < n+1; i++){
            x[i] = scanner.nextInt();
            v[i] = scanner.nextInt();
        }

        // Initialize vectors to store cumulative velocities from the left
        int[] lefttotal = new int[n+1];
        int[] maxlefttotal = new int[n+1];
        
        // Calculate cumulative velocities from the left
        for(int i = 1; i < n+1; i++){
            lefttotal[i] = lefttotal[i-1] + v[i];
        }

        // Calculate the maximum value of lefttotal adjusted by position
        for(int i = 1; i < n+1; i++){
            maxlefttotal[i] = Math.max(maxlefttotal[i-1], lefttotal[i] - x[i]);
        }

        // Initialize vectors to store cumulative velocities from the right
        int[] righttotal = new int[n+1];
        int[] maxrighttotal = new int[n+1];
        
        // Calculate cumulative velocities from the right
        for(int i = 1; i < n+1; i++){
            righttotal[i] = righttotal[i-1] + v[n-i+1];
        }
        
        // Calculate the maximum value of righttotal adjusted by position
        for(int i = 1; i < n+1; i++){
            maxrighttotal[i] = Math.max(maxrighttotal[i-1], righttotal[i] - (c - x[n+1-i]));
        }

        // Initialize the answer variable to store the maximum result
        int ans = 0;

        // Evaluate the maximum possible value based on different scenarios
        for(int i = 1; i < n+1; i++){
            ans = Math.max(ans, lefttotal[i] - x[i]); // Scenario 1
            ans = Math.max(ans, lefttotal[i] - 2 * x[i] + maxrighttotal[n-i]); // Scenario 2
            ans = Math.max(ans, righttotal[i] - (c - x[n+1-i])); // Scenario 3
            ans = Math.max(ans, righttotal[i] - 2 * (c - x[n+1-i]) + maxlefttotal[n-i]); // Scenario 4
        }

        // Output the final result
        System.out.println(ans);
    }
}

