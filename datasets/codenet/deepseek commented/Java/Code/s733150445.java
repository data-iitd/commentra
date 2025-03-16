import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        // Create a BufferedReader to read input from the console
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        // Create a StringTokenizer to read the input numbers
        StringTokenizer st = new StringTokenizer(in.readLine());
        
        // Read the first number from the input and convert it to a BigDecimal
        BigDecimal a = new BigDecimal(st.nextToken());
        
        // Read the second number from the input and convert it to a BigDecimal
        BigDecimal b = new BigDecimal(st.nextToken());
        
        // Multiply the two numbers
        BigDecimal mul = a.multiply(b);
        
        // Tokenize the result to separate the integer and decimal parts
        st = new StringTokenizer(mul.toString(), ".");
        
        // Print the integer part of the result
        System.out.println(st.nextElement());
    }
}
