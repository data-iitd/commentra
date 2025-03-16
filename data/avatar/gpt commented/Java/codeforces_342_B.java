import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.ArrayList; 
import java.util.HashMap; 

public class Main { 
    public static void main(String[] args) throws IOException { 
        // Initialize BufferedReader to read input from the console
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)); 
        
        // Read the first line of input and split it into an array
        String input[] = reader.readLine().split(" "); 
        
        // Parse the number of movements (m), start position (s), and final position (f)
        int m = Integer.parseInt(input[1]); 
        int s = Integer.parseInt(input[2]); 
        int f = Integer.parseInt(input[3]); 
        
        // Initialize maxT to keep track of the maximum time step
        int maxT = -1; 
        
        // Create a HashMap to store the movements at each time step
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>(); 
        
        // Read the movements for each time step
        while (m > 0) { 
            // Read the movement data for the current time step
            String mth[] = reader.readLine().split(" "); 
            int k = Integer.parseInt(mth[0]); 
            
            // Initialize the list for the current time step and add the movement range
            map.put(k, new ArrayList<>()); 
            map.get(k).add(Integer.parseInt(mth[1])); 
            map.get(k).add(Integer.parseInt(mth[2])); 
            
            // Update maxT to the highest time step encountered
            maxT = Math.max(maxT, k); 
            m--; 
        } 
        
        // Prepare a StringBuilder to store the actions taken
        StringBuilder actions = new StringBuilder(); 
        
        // Determine the direction of movement based on start and final positions
        final char M = (s < f) ? 'R' : 'L'; 
        int d = (s < f) ? +1 : -1; 
        
        // Initialize current position to start position
        int cur = s; 
        int a = -1; 
        int b = -1; 
        
        // Iterate through each time step from 1 to maxT
        for (int t = 1; t <= maxT; t++) { 
            // Check if there are movements defined for the current time step
            if (map.containsKey(t)) { 
                a = map.get(t).get(0).intValue(); // Get the start of the movement range
                b = map.get(t).get(1).intValue(); // Get the end of the movement range
            } 
            
            // Check if the current position or the next position is within the movement range
            if (map.containsKey(t) && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) { 
                actions.append('X'); // Append 'X' if within the range
            } else { 
                actions.append(M); // Append the movement direction
                cur += d; // Update the current position
            } 
            
            // Break the loop if the current position reaches the final position
            if (cur == f) break; 
        } 
        
        // Continue moving until the current position reaches the final position
        while (cur != f) { 
            actions.append(M); // Append the movement direction
            cur += d; // Update the current position
        } 
        
        // Output the sequence of actions taken
        System.out.println(actions); 
    } 
}
