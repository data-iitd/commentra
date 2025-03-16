import java.io.BufferedReader; 
import java.io.InputStreamReader; 
import java.io.IOException; 

public class Main { 
    public static void main(String[] args) throws IOException { 
        // Create a BufferedReader to read input from the console
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in)); 
        
        // Read a line of input and split it into an array of strings
        String[] str = in.readLine().split(" "); 
        
        // Parse the first string as an integer representing the initial health
        int h = Integer.parseInt(str[0]); 
        
        // Parse the second string as an integer representing the damage dealt per attack
        int a = Integer.parseInt(str[1]); 
        
        // Initialize a counter to keep track of the number of attacks
        int num = 0; 
        
        // Loop until the health is greater than zero
        for (int i = 1; h > 0; i++) { 
            // Decrease health by the amount of damage dealt
            h = h - a; 
            
            // Increment the attack counter
            num++; 
        } 
        
        // Output the total number of attacks required to reduce health to zero or below
        System.out.println(num); 
    } 
}
