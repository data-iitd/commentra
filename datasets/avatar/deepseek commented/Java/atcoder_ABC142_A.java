
import java.io.BufferedReader ; import java.io.IOException ; import java.io.InputStreamReader ; import java.math.BigDecimal ; import java.math.RoundingMode ; 

// Import statements to handle input/output operations and mathematical calculations

public class Main { 
    public static void main ( String [ ] args ) throws Exception { 
        
        // Main method is the entry point of the program
        
        try { 
            BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
            
            // Setting up BufferedReader to read input from standard input
            
            double input = Double.parseDouble ( br.readLine ( ) ) ; 
            
            // Reading a double value from the input
            
            double countOdd = Math.round ( input / 2 ) ; 
            
            // Calculating the number of odd numbers up to the given input
            
            BigDecimal result = new BigDecimal ( countOdd / input ) ; 
            result.setScale ( 10 , RoundingMode.HALF_UP ) ; 
            
            // Using BigDecimal to handle precise decimal calculations and setting the scale to 10
            
            System.out.println ( result ) ; 
            
            // Printing the result
            
        } catch ( IOException | NumberFormatException e ) { 
            e.printStackTrace ( ) ; 
            System.exit ( 0 ) ; 
            
            // Handling IOException and NumberFormatException to ensure program termination
            
        } catch ( final Exception e ) { 
            e.printStackTrace ( ) ; 
            System.exit ( 0 ) ; 
            
            // Handling any other potential exceptions to ensure program termination
            
        } 
    } 
}
