import java.util.Scanner;

public class GCD {
    
    // Define gcd function: This function computes the greatest common divisor
    // of two integers using the Euclidean algorithm.
    public static int gcd(int a, int b) {
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        int r;
        while ((r = a % b) > 0) {
            a = b;
            b = r;
        }
        return b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of integers.
        int n = scanner.nextInt();
        
        // Read the first integer and initialize the answer.
        int ans = scanner.nextInt();
        
        // Read the remaining integers, compute their GCD with the current answer,
        // and update the answer accordingly.
        for (int i = 1; i < n; ++i) {
            int a = scanner.nextInt();
            ans = gcd(ans, a);
        }
        
        // Print the final result, which is the GCD of all the input integers.
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
