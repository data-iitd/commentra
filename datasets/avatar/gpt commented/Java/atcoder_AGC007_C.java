import java.math.BigDecimal; 
import java.text.DecimalFormat; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner scan = new Scanner(System.in); 
        
        // Read three double values from the user: N, d, and x
        double N = scan.nextDouble(); 
        double d = scan.nextDouble(); 
        double x = scan.nextDouble(); 
        
        // Initialize a BigDecimal variable to store the accumulated answer
        BigDecimal ans = new BigDecimal("0.0"); 
        
        // Loop until N is greater than 0.5
        while (N > 0.5) { 
            // Calculate the current term to be added to the answer
            BigDecimal adnum = BigDecimal.valueOf(d + x * (N - 0.5)); 
            // Add the current term to the accumulated answer
            ans = ans.add(adnum); 
            
            // Update d using the formula provided
            d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N); 
            // Update x using the formula provided
            x = (1.0 + (2.0 / N)) * x; 
            
            // Decrement N for the next iteration
            --N; 
        } 
        
        // Create a DecimalFormat object to format the output
        DecimalFormat format = new DecimalFormat("#.#"); 
        // Set the minimum number of fraction digits to 20
        format.setMinimumFractionDigits(20); 
        
        // Print the formatted result
        System.out.println(format.format(ans)); 
    } 
}
