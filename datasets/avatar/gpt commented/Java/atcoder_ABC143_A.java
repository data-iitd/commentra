import java.io.BufferedReader; 
import java.io.InputStreamReader; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        try { 
            // Create a BufferedReader to read input from the console
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in)); 
            
            // Read a line of input, trim whitespace, and split it into an array of strings
            String[] x = bf.readLine().trim().split(" "); 
            
            // Parse the first and second elements of the array as integers
            int a = Integer.parseInt(x[0]); 
            int b = Integer.parseInt(x[1]); 
            
            // Calculate the value of c based on the formula: c = a - b * 2
            int c = a - b * 2; 
            
            // If c is negative, set it to 0
            if (c < 0) c = 0; 
            
            // Output the final value of c
            System.out.println(c); 
        } catch (Exception e) { 
            // Handle any exceptions that may occur during input or processing
        } 
    } 
}
