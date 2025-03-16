import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ask the user for an integer input and assign it to the variable x
        int x = scanner.nextInt();

        // Calculate the greatest common divisor (gcd) of 360 and the user input x
        int gcd_value = gcd(360, x);

        // Print the result of the division of 360 by the gcd
        System.out.println(360 / gcd_value);
    }

    // Function to calculate the greatest common divisor (gcd)
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
