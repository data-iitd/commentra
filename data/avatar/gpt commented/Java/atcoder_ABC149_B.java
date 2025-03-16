import java.util.*; 
import java.io.*; 
import java.nio.charset.StandardCharsets; 

public class Main {
    // Declare variables to hold the values of A, B, K, and the results x, y
    long A, B, K; 
    long x, y; 

    public static void main(String[] args) throws IOException {
        // Set up input reading from standard input with UTF-8 encoding
        InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8); 
        BufferedReader in = new BufferedReader(reader); 
        
        // Create an instance of Main class and pass the BufferedReader for input
        Main ins = new Main(in); 
        
        // Perform calculations based on the input values
        ins.calc(); 
        
        // Display the results of the calculations
        ins.showResult(); 
    } 

    // Constructor to read input values A, B, and K from the BufferedReader
    Main(BufferedReader in) throws IOException {
        // Read a line of input, split it into tokens, and parse them as long integers
        String[] tokens = in.readLine().split(" "); 
        A = Long.parseLong(tokens[0]); 
        B = Long.parseLong(tokens[1]); 
        K = Long.parseLong(tokens[2]); 
    } 

    // Method to perform the main calculation based on A, B, and K
    void calc() {
        // Initialize x with the value of A and y with the value of B
        x = A; 
        y = B; 
        
        // Subtract K from A and assign the result to x
        x = A - K; 
        
        // Check if the result x is negative
        if (x < 0) {
            // If x is negative, adjust y by adding the negative value of x to B
            y = B + x; 
            // Set x to 0 since it cannot be negative
            x = 0; 
            
            // Ensure y is not negative
            if (y < 0) {
                y = 0; 
            } 
        } 
    } 

    // Method to display the results of the calculations
    void showResult() {
        // Print the values of x and y
        System.out.println(x + " " + y); 
    } 
}
