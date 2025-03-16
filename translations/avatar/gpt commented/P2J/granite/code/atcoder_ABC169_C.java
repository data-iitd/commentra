
import java.io.*;
import java.util.*;

public class atcoder_ABC169_C{
    public static void main(String[] args) throws IOException {
        // Define a debug print function that only prints if running in a terminal environment
        boolean isTermProgram = System.getenv("TERM_PROGRAM")!= null;
        var dbg = isTermProgram? System.out::println : (Object... o) -> {};

        // Define a function to read a single integer from input
        var ii = () -> Integer.parseInt(br.readLine());

        // Define a function to read a list of integers from input
        var lmiis = () -> Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        // Constants for calculations
        var P = 100000007;  // A large prime number for modulo operations
        var INF = 100000000;  // A large number representing infinity

        // Read two values from input: one as an integer and the other as a float in string format
        var sa = br.readLine().split(" ");
        
        // Convert the first value to an integer
        var a = Integer.parseInt(sa[0]);
        
        // Convert the second value to an integer representing cents (by multiplying by 100)
        var b = (int) (Double.parseDouble(sa[1]) * 100 + 0.1);

        // Calculate and print the product of a and b, divided by 100 to get the final result
        System.out.println(a * b / 100);
    }
}

// End of code