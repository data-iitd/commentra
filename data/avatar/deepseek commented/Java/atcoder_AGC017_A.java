
import java.util.* ; 
import java.math.* ; 

public class Main { 
    // Function to calculate combination (n choose m) using BigInteger for large numbers
    static BigInteger C(int n, int m) { 
        BigInteger res = new BigInteger("1"); // Initialize result to 1
        // Calculate product from m-n+1 to m
        for (int i = m - n + 1; i <= m; i++) 
            res = res.multiply(BigInteger.valueOf(i)); 
        // Divide by product from 1 to n
        for (int i = 1; i <= n; i++) 
            res = res.divide(BigInteger.valueOf(i)); 
        return res; 
    } 

    public static void main(String args[]) { 
        Scanner sc = new Scanner(System.in); 
        int n, p; 
        int k0 = 0; // Count of even numbers
        int k1 = 0; // Count of odd numbers

        // Read number of items (n) and the value of p
        n = sc.nextInt(); 
        p = sc.nextInt(); 

        // Count even and odd numbers in the input
        for (int i = 0; i < n; i++) { 
            int x = sc.nextInt(); 
            if (x % 2 == 1) 
                k1++; 
            else 
                k0++; 
        } 

        // Initialize result for number of ways to arrange items
        BigInteger ans = new BigInteger("1"); 

        // Calculate number of ways based on the value of p
        for (int i = 0; i < k0; i++) 
            ans = ans.multiply(BigInteger.valueOf(2)); // Multiply by 2 for each even number

        if (p == 0) { 
            BigInteger add = new BigInteger("0"); 
            // Sum combinations of odd numbers, taking 0, 2, 4, ... odd numbers
            for (int i = 0; i <= k1; i += 2) 
                add = add.add(C(i, k1)); 
            ans = ans.multiply(add); // Multiply result by the sum
            System.out.println(ans); // Print final result
        } else { 
            BigInteger add = new BigInteger("0"); 
            // Sum combinations of odd numbers, taking 1, 3, 5, ... odd numbers
            for (int i = 1; i <= k1; i += 2) 
                add = add.add(C(i, k1)); 
            ans = ans.multiply(add); // Multiply result by the sum
            System.out.println(ans); // Print final result
        } 
    } 
}

