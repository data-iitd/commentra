
import java.util.*;
import java.io.*;

class s098326932 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        long N = f(1);
        for (int i = 0; i < K; i++) {
            System.out.println(N);
            N = f(N+1);
        }
    }

    // Function to find the number with minimum ratio of digits to total number
    static long f(long N) {
        // Initialize a vector to store digits of the number
        Vector<Long> a = new Vector<Long>();
        int d = 0; // Index to store the current digit position

        // Extract digits from N and store them in the vector 'a'
        while (N > 0) {
            a.add(N % 10); // Store the current digit
            N /= 10; // Move to the next digit
            d++; // Increment the index
        }

        // Initialize minimum ratio and the result
        double m = 1e18;
        long res = N;

        // Iterate through each digit position from 0 to the last digit position
        for (int i = 0; i <= d; i++) {
            // Initialize sum of digits before the current digit position
            long bunsi = 0;
            // Initialize the sum of digits after the current digit position
            long bunbo = 9 * i;

            // Calculate the sum of digits before the current digit position
            for (int j = d-1; j >= 0; j--) {
                // Update the sum of digits before the current digit position
                bunsi *= 10;
                if (j < i) bunsi += 9; // Add 9 for each digit before the current digit position
                else bunsi += a.get(j); // Add the current digit

                // Update the sum of digits after the current digit position
                if (j >= i) bunbo += a.get(j);
            }

            // Calculate the ratio of digits before the current digit position to the sum of digits before and after the current digit position
            double frac = (double) bunsi / (double) bunbo;

            // Update the minimum ratio and the result if the current ratio is smaller than the previous minimum ratio
            if (frac < m) {
                m = frac;
                res = bunsi;
            }
        }

        // Return the number with the minimum ratio of digits to total number
        return res;
    }
}

// End of code