public class Main {
    public static void main(String[] args) {
        // Define input variables 's' and 'l'
        String s = System.console().readLine();
        int l = 2019;

        // Initialize list 'm' with initial value 1 for index 0 and zeros for other indices
        int[] m = new int[l];
        m[0] = 1;

        // Initialize variables 'a' and 'r' with zero values
        int a = 0, r = 0;

        // Iterate through the string 's' in reverse order
        for (int i = 0; i < s.length(); i++) {
            // Calculate the current digit's power and add it to 'a'
            int e = Character.getNumericValue(s.charAt(s.length() - 1 - i));
            a += e * pow(10, i, l);

            // Increment the index 'a % l' in list 'm'
            m[a % l]++;

            // Update 'r' with the current sum
            r += m[a % l];
        }

        // Print the final result 'r'
        System.out.println(r);
    }

    // Helper method to calculate power with modulo
    private static int pow(int base, int exp, int mod) {
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
