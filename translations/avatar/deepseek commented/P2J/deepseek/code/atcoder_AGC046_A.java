import java.util.Scanner; // Importing the Scanner class
import java.lang.Math; // Importing the Math class

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object

        // Take an integer input x
        int x = scanner.nextInt();

        // Calculate the number of distinct cyclic permutations of a string of length x
        System.out.println(360 / gcd(360, x));
    }

    // Function to calculate the greatest common divisor (gcd)
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
