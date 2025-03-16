
import java.io.BufferedReader; // Import BufferedReader for reading input from standard input
import java.io.IOException; // Import IOException for handling I/O errors
import java.io.InputStreamReader; // Import InputStreamReader for reading input from standard input stream
import java.math.BigDecimal; // Import BigDecimal for decimal arithmetic
import java.math.RoundingMode; // Import RoundingMode for specifying rounding mode

public class Main {

    public static void main(String[] args) throws Exception {
        try { // Begin try block for handling normal input and calculation
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Read input from standard input
            double input = Double.parseDouble(br.readLine()); // Parse input as a double

            // Calculate the number of odd numbers in the input
            double countOdd = Math.round(input / 2);

            // Create a BigDecimal object for the result
            BigDecimal result = new BigDecimal(countOdd / input);

            // Set the scale and rounding mode for the result
            result.setScale(10, RoundingMode.HALF_UP);

            // Print the result
            System.out.println(result);
        } catch (IOException e) { // Begin catch block for handling I/O errors
            e.printStackTrace(); // Print the stack trace of the error
            System.exit(0); // Exit the program with a zero status code
        } catch (NumberFormatException e) { // Begin catch block for handling number format errors
            e.printStackTrace(); // Print the stack trace of the error
            System.exit(0); // Exit the program with a zero status code
        } catch (Exception e) { // Begin catch block for handling other exceptions
            e.printStackTrace(); // Print the stack trace of the error
            System.exit(0); // Exit the program with a zero status code
        }
    }
}

