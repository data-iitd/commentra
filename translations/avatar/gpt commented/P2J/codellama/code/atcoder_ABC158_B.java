
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        // Define the modulo constant
        int mod = 1000000007;
        
        // Read input values: N (total items), A (items of type A), B (items of type B)
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        
        // Initialize the answer variable
        int ans = 0;
        
        // Calculate how many complete cycles of (A + B) fit into N
        int rep = N / (A + B);
        
        // Add the total items of type A from the complete cycles to the answer
        ans += rep * A;
        
        // Calculate the remaining items after complete cycles
        int res = N - rep * (A + B);
        
        // Add the minimum of remaining items or A to the answer
        ans += Math.min(res, A);
        
        // Print the final answer
        System.out.println(ans);
    }
}

