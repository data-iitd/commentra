import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine(); // Take input string `s`
        int l = 2019; // The number `l` (2019 in this case)
        
        int[] m = new int[l + 1]; // Initialize array `m` with a length of `l + 1` (2019), filled with zeros
        m[0] = 1; // Prepend a 1 at the beginning
        int a = 0; // Initialize `a`
        long r = 0; // Initialize `r`
        
        for (int i = 0; i < s.length(); i++) {
            char e = s.charAt(s.length() - 1 - i); // Iterate over the reversed string `s`
            a += (e - '0') * pow(10, i, l); // Calculate the value of the character's position times 10 raised to the power of its position in the reversed string, modulo `l`
            r += m[a % l]; // Increment the running total `r`
            m[a % l]++; // Increment the value in `m` at the position `a % l` by 1
        }
        
        System.out.println(r); // Finally, print the value of `r`
    }

    // Function to calculate (base^exp) % mod
    private static int pow(int base, int exp, int mod) {
        int result = 1;
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
