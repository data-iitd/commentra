import java.math.BigInteger; // Importing BigInteger for handling large integers
import java.util.*; // Importing all classes from java.util package
import java.util.stream.*; // Importing Stream API for functional programming

public class Main {
    static Scanner scanner = new Scanner(System.in); // Initializing a Scanner object to read input

    public static void main(String[] args) {
        int n = scanner.nextInt(); // Reading the first integer
        int m = scanner.nextInt(); // Reading the second integer
        int gcd = BigInteger.valueOf(n).gcd(BigInteger.valueOf(m)).intValue(); // Calculating the GCD of n and m
        String s = scanner.next(); // Reading the first string
        String t = scanner.next(); // Reading the second string

        // Filtering the range of the GCD and checking character mismatches
        System.out.println(
            IntStream.range(0, gcd).filter(k -> s.charAt(k * n / gcd) != t.charAt(k * m / gcd)).mapToLong(k -> -1).findAny().orElse(
                BigInteger.valueOf(n).multiply(BigInteger.valueOf(m)).divide(BigInteger.valueOf(gcd)).longValue() // Calculating and printing the result
            )
        );
    }
}
