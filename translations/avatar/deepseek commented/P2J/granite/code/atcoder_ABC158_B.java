
import java.util.*;

// atcoder_ABC158_B class
public class atcoder_ABC158_B{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Reading N, A, and B
        int N = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        
        // Modulo value
        int mod = 100000007;
        
        // Initializing the result variable
        long ans = 0;
        
        // Calculating the number of complete cycles of A + B within N
        int rep = N / (A + B);
        
        // Updating the result with the number of complete cycles multiplied by A
        ans += (long)rep * A;
        
        // Calculating the remaining days after the complete cycles
        int res = N - rep * (A + B);
        
        // Updating the result with the minimum of the remaining days and A
        ans += Math.min(res, A);
        
        // Printing the final result
        System.out.println(ans);
    }
}

Translate the above Java code to C++ and end with comment "