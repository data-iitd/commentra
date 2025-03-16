import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    // Arrays to store frequency counts for two different calculations
    static int[] f1 = new int[100];
    static int[] f2 = new int[100];

    // Function to calculate frequency counts based on the input number
    static void calc(int n) {
        int k = n % 10; // Extract the last digit of n
        // Reduce n to its first digit by continuously dividing by 10
        while (n >= 10) n /= 10;
        // Update frequency counts for combinations of first and last digits
        f1[10 * k + n]++;
        f2[n * 10 + k]++;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()); // Read the total number of inputs
        // Process each number from N down to 1
        while (N > 0) calc(N--);

        int ans = 0; // Initialize answer to 0
        // Calculate the final answer by summing the products of corresponding frequencies
        for (int i = 0; i < 100; i++) ans += f1[i] * f2[i];
        // Output the final answer
        System.out.println(ans);
    }
}
// <END-OF-CODE>
