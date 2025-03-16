import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int l = 2019;

        // Initialize a list to count occurrences of remainders, and variables for accumulated value and result
        long[] m = new long[l];
        m[0] = 1; // m[0] is initialized to 1 because the remainder 0 can be achieved by the empty string
        int a = 0;
        long r = 0;

        // Iterate over the input string in reverse order
        for (int i = 0; i < s.length(); i++) {
            // Update the accumulated value 'a' by converting the character to an integer and adjusting its place value
            int e = s.charAt(s.length() - 1 - i) - '0';
            a += e * pow(10, i, l);
            a %= l;

            // Update the result 'r' by adding the count of occurrences of the current remainder
            r += m[a];

            // Increment the count of the current remainder in the list 'm'
            m[a]++;
        }

        // Print the final result
        System.out.println(r);
    }

    // Custom pow function to calculate (base^exp) % mod
    public static int pow(int base, int exp, int mod) {
        int result = 1;
        base = base % mod;
        while (exp > 0) {
            if ((exp & 1) == 1) { // If exp is odd, multiply base with result
                result = (result * base) % mod;
            }
            exp = exp >> 1; // Divide exp by 2
            base = (base * base) % mod; // Square the base
        }
        return result;
    }
}
