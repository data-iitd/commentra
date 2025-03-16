
import java.io.*;
import java.util.*;

public class atcoder_AGC007_C{
    public static void main(String[] args) throws Exception {
        // Set up input reading methods for efficient reading from standard input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.ordinaryChar('-');
        st.ordinaryChar('.');
        st.ordinaryChar('e');
        
        // Read the input values for N, d, and x, and convert them to doubles
        st.nextToken();
        int N = (int) st.nval;
        st.nextToken();
        double d = st.nval;
        st.nextToken();
        double x = st.nval;
        
        // Initialize the result variable to accumulate the final value
        double ret = 0;
        
        // Loop until N becomes zero
        while (N > 0) {
            // Update the result by adding the current d and a calculated value based on N and x
            ret += d + (N - 0.5) * x;
            
            // Update d based on its current value, N, and x
            d = d + (d / N) + (5 * x) / (2 * N);
            
            // Update x based on its current value and N
            x += 2 * x / N;
            
            // Decrement N to move to the next iteration
            N--;
        }
        
        // Print the accumulated result
        System.out.println(ret);
    }
}

Translate the above Java code to C++ and end with comment "