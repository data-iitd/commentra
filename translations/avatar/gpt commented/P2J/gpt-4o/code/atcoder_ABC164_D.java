import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read input string
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int l = 2019;

        // Initialize an array to count occurrences of remainders, and variables for accumulated value and result
        int[] m = new int[l];
        m[0] = 1; // Initialize the count for remainder 0
        long a = 0;
        long r = 0;

        // Iterate over the input string in reverse order
        for (int i = 0; i < s.length(); i++) {
            char e = s.charAt(s.length() - 1 - i);
            // Update the accumulated value 'a' by converting the character to an integer and adjusting its place value
            a += (e - '0') * pow(10, i, l);

            // Update the result 'r' by adding the count of occurrences of the current remainder
            r += m[(int)(a % l)];

            // Increment the count of the current remainder in the array 'm'
            m[(int)(a % l)]++;
        }

        // Print the final result
        System.out.println(r);
    }

    // Function to calculate (base^exp) % mod
    private static long pow(long base, long exp, long mod) {
        long result = 1;
        base = base % mod;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * base) % mod;
            }
            exp >>= 1;
            base = (base * base) % mod;
        }
        return result;
    }
}
// <END-OF-CODE>
