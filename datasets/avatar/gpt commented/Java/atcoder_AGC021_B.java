import java.util.Scanner; 
import java.util.Comparator; 
import java.util.Arrays; 
import java.util.List; 
import java.util.ArrayList; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner scan = new Scanner(System.in); 
        
        // Read the number of points N
        int N = scan.nextInt(); 
        
        // Initialize arrays to store the x and y coordinates of the points
        int[] x = new int[N]; 
        int[] y = new int[N]; 
        
        // Read the coordinates of the points from user input
        for (int i = 0; i < N; ++i) { 
            x[i] = scan.nextInt(); 
            y[i] = scan.nextInt(); 
        } 
        
        // Iterate over each point to calculate the angles with respect to other points
        for (int i = 0; i < N; ++i) { 
            // Create a list to store the angles (thetas) for the current point
            List<Double> thetas = new ArrayList<>(); 
            
            // Calculate the angle between the current point and all other points
            for (int j = 0; j < N; ++j) { 
                // Skip the current point itself
                if (i == j) continue; 
                
                // Calculate the angle using atan2 and add it to the list
                thetas.add(Math.atan2(y[j] - y[i], x[j] - x[i])); 
            } 
            
            // Sort the angles in ascending order
            thetas.sort(Comparator.naturalOrder()); 
            
            // Add the angle that wraps around (2 * PI) to handle circularity
            thetas.add(thetas.get(0) + 2 * Math.PI); 
            
            // Initialize a variable to find the maximum angle difference
            double ans = 0; 
            
            // Calculate the maximum angle difference between consecutive angles
            for (int k = 0; k < N - 1; ++k) 
                ans = Math.max(ans, thetas.get(k + 1) - thetas.get(k) - Math.PI); 
            
            // Output the result as a fraction of the full circle (2 * PI)
            System.out.println(ans / (Math.PI * 2)); 
        } 
    } 
}
