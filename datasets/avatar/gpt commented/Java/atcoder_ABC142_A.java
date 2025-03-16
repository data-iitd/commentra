import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.math.BigDecimal; 
import java.math.RoundingMode; 

public class Main { 
    public static void main(String[] args) throws Exception { 
        try { 
            // Create a BufferedReader to read input from the console
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
            
            // Read a line of input and parse it as a double
            double input = Double.parseDouble(br.readLine()); 
            
            // Calculate the count of odd numbers based on the input
            double countOdd = Math.round(input / 2); 
            
            // Create a BigDecimal to hold the result of the division
            BigDecimal result = new BigDecimal(countOdd / input); 
            
            // Set the scale of the result to 10 decimal places, rounding half up
            result = result.setScale(10, RoundingMode.HALF_UP); 
            
            // Print the result to the console
            System.out.println(result); 
        } catch (IOException | NumberFormatException e) { 
            // Handle input/output exceptions and number format exceptions
            e.printStackTrace(); 
            System.exit(0); 
        } catch (final Exception e) { 
            // Handle any other exceptions that may occur
            e.printStackTrace(); 
            System.exit(0); 
        } 
    } 
}
