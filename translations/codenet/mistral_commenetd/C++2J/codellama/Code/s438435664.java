
// Import the Scanner class to read input from the command line
import java.util.Scanner;

// Custom helper functions
class Solution {
    // Function to find the greatest common divisor (GCD) of two numbers
    public static long gcd(long x, long y) {
        // Base case: if x is smaller than y, swap x and y
        if (x < y){
            long temp = x;
            x = y;
            y = temp;
        }

        // Recursive case: find the remainder of x divided by y and repeat
        while (y > 0) {
            long r = x % y;
            x = y;
            y = r;
        }

        // Return the GCD (the last non-zero value of x)
        return x;
    }

    // Function to find the least common multiple (LCM) of two numbers
    public static long lcm(long x, long y){
        // Return the product of x and y divided by their GCD
        return x/gcd(x,y)*y;
    }

    // Function to calculate the factorial (kaijo) of a number
    public static long kaijo(long k){
        long sum = 1;
        // Calculate the factorial by multiplying the number with all the numbers less than it
        for (long i = 1; i <= k; ++i)
        {
            sum *= i;
            // Modulo the result by 1000000000+7 to keep the result within a certain range
            sum%=1000000000+7;
        }
        // Return the result
        return sum;
    }

    // Function to find the larger of two numbers
    public static long lmax(long s, long t){
        // Return the larger of the two numbers
        if(s>t){
            return s;
        }
        else{
            return t;
        }
    }

    // Function to find the smaller of two numbers
    public static long lmin(long s, long t){
        // Return the smaller of the two numbers
        if(s<t){
            return s;
        }
        else{
            return t;
        }
    }

    // Main function
    public static void main(String[] args) {
        // Read the input values for n and k from the standard input
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        // Initialize a variable to store the sum of the results
        long sum = 0;

        // Iterate through all possible block sizes from 1 to n
        for (int b = 1; b <= n+1; b++){
            // Calculate the number of blocks of size b that can fit into n+1
            int cnt = (n+1)/b;

            // Calculate the remainder of n+1 when divided by b
            int md = (n+1)%b;

            // Add the number of blocks of size b that cover k or more numbers to the sum
            sum+=cnt*Math.max((b-k),0)+Math.max((md-k),0);

            // If k is 0, subtract 1 from the sum (since an empty block doesn't contribute to the sum)
            if(k==0) sum--;
        }

        // Print the result to the standard output
        System.out.println(sum);

        // Return 0 to indicate successful execution
        return;
    }
}

