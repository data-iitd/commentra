
import java.util.*;

class atcoder_ABC125_C {
    static int gcd(int a, int b) {
        // Base case: if b is 0, return a as the GCD
        if (b == 0) {
            return a;
        }
        // Recursive case: call gcd with b and the remainder of a divided by b
        return gcd(b, a % b);
    }

    static int[] ruiseki_lr(int[] array) {
        // Define the operation to find the GCD of two numbers
        IntBinaryOperator op = (a, b) -> gcd(a, b);
        
        // Initialize the identity element for GCD
        int e = 0;
        int n = array.length;
        
        // Create arrays to store cumulative GCD from the left and right
        int[] left = new int[n + 1];
        int[] right = new int[n + 1];
        
        // Calculate cumulative GCD from the left
        for (int i = 0; i < n; i++) {
            left[i + 1] = op.applyAsInt(left[i], array[i]);
        }
        
        // Calculate cumulative GCD from the right
        for (int i = n - 1; i >= 0; i--) {
            right[i] = op.applyAsInt(right[i + 1], array[i]);
        }
        
        // Return both cumulative GCD arrays
        return left;
    }

    public static void main(String[] args) {
        // Read the number of elements in the array
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        
        // Read the array elements from input and convert them to integers
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(sc.next());
        }
        
        // Compute the cumulative GCD from the left and right
        int[] left = ruiseki_lr(a);
        
        // Initialize the answer variable to store the maximum GCD found
        int ans = 0;
        
        // Iterate through the array to find the maximum GCD of left and right parts
        for (int i = 0; i < n; i++) {
            ans = Math.max(gcd(left[i], right[i + 1]), ans);
        }
        
        // Print the maximum GCD found
        System.out.println(ans);
    }
}

Translate the above Java code to C++ and end with comment "