import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        // Create a BufferedReader to read input from the console
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        // Read a line of input and tokenize it to extract two numbers
        StringTokenizer st = new StringTokenizer(in.readLine());
        
        // Parse the first token as a BigDecimal
        BigDecimal a = new BigDecimal(st.nextToken());
        
        // Parse the second token as a BigDecimal
        BigDecimal b = new BigDecimal(st.nextToken());
        
        // Multiply the two BigDecimal numbers
        BigDecimal mul = a.multiply(b);
        
        // Tokenize the result to separate the integer part from the decimal part
        st = new StringTokenizer(mul.toString(), ".");
        
        // Print the integer part of the multiplication result
        System.out.println(st.nextElement());
    }
}
