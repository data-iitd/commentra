
import java.util.Scanner;

public class s605014348{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        System.out.print(num + ":");
        while (num!= 1) {
            System.out.print(" " + div(num));
            num = num / div(num);
        }
        System.out.println();
    }

    // Function to find the smallest divisor of n
    public static int div(int n) {
        // Check if n is even, return 2 if it is
        if (n % 2 == 0) return 2;

        // Calculate the square root of n for optimization
        int s = (int) Math.sqrt(n);

        // Check for odd divisors from 3 up to the square root of n
        for (int i = 3; i <= s; i += 2) {
            // If i is a divisor of n, return it
            if (n % i == 0) return i;
        }

        // If no divisors found, return n (n is prime)
        return n;
    }
}
