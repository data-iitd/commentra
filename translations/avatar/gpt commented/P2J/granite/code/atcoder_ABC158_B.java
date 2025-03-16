
import java.util.*;
import java.io.*;

public class atcoder_ABC158_B{
    public static void main(String[] args) throws Exception {
        // Define the modulo constant
        final int MOD = 100000007;
        
        // Create a new input stream
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // Read input values: N (total items), A (items of type A), B (items of type B)
        String[] inputs = br.readLine().split(" ");
        int N = Integer.parseInt(inputs[0]);
        int A = Integer.parseInt(inputs[1]);
        int B = Integer.parseInt(inputs[2]);
        
        // Initialize the answer variable
        long ans = 0;
        
        // Calculate how many complete cycles of (A + B) fit into N
        int rep = N / (A + B);
        
        // Add the total items of type A from the complete cycles to the answer
        ans += (long)rep * A;
        
        // Calculate the remaining items after complete cycles
        int res = N - rep * (A + B);
        
        // Add the minimum of remaining items or A to the answer
        ans += Math.min(res, A);
        
        // Print the final answer
        System.out.println(ans);
    }
}

Translate the above Java code to C++ and end with comment "