import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Define input variables 's' and 'l'
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int l = 2019;

        // Initialize array 'm' with initial value 1 for index 0 and zeros for other indices
        long[] m = new long[l];
        m[0] = 1;

        // Initialize variables 'a' and 'r' with zero values
        long a = 0, r = 0;

        // Iterate through the string 's' in reverse order
        for (int i = 0; i < s.length(); i++) {
            char e = s.charAt(s.length() - 1 - i);
            // Calculate the current digit's power and add it to 'a'
            a += (e - '0') * pow(10, i, l);

            // Increment the index 'a % l' in array 'm'
            m[(int)(a % l)]++;

            // Update 'r' with the current sum
            r += m[(int)(a % l)];
        }

        // Print the final result 'r'
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
