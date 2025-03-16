import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 

public class Main { 
    public static void main(String[] args) throws IOException { 
        // Create a BufferedReader to read input from the console
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        
        // Read a line of input and split it into an array of strings
        String line = br.readLine(); 
        String[] list = line.split(" "); 
        
        // Parse the first three elements of the input into integers
        int x = Integer.parseInt(list[0]); 
        int a = Integer.parseInt(list[1]); 
        int y = Integer.parseInt(list[2]); 
        
        // Initialize a variable to hold the result, defaulting to "NO"
        String h = "NO"; 
        
        // Check if any of the numbers x, a, or y are either 5 or 7
        if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) { 
            // If the sum of x, a, and y equals 17, set the result to "YES"
            if (x + y + a == 17) { 
                h = "YES"; 
            } 
        } 
        
        // Output the result
        System.out.println(h); 
    } 
}
