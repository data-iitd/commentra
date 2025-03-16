import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Initialize Scanner to read input from the user
        Scanner sc = new Scanner(System.in);

        // Read three long integers: k, a, and b
        long k = sc.nextLong();
        long a = sc.nextLong();
        long b = sc.nextLong();

        // Check if b is less than or equal to a + 2
        if (b <= a + 2) {
            // If true, print 1 + k and return
            System.out.println(1 + k);
            return;
        }

        // Adjust k by subtracting (a - 1) to handle initial a cookies
        long x = k - (a - 1);

        // Calculate the total number of cookies using the formula
        long ans = a + (x / 2) * (b - a) + (x % 2);

        // Print the calculated result
        System.out.println(ans);
    }
}
