import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);

        // Read three long integers from input: k, a, and b
        long k = sc.nextLong();
        long a = sc.nextLong();
        long b = sc.nextLong();

        // Check if b is less than or equal to a + 2
        // If true, print 1 + k and exit the program
        if (b <= a + 2) {
            System.out.println(1 + k);
            return; // Exit the main method
        }

        // Calculate x as k minus (a - 1)
        long x = k - (a - 1);
        
        // Calculate the answer based on the value of x
        // The formula accounts for the number of complete pairs of (b - a) that can be formed
        long ans = a + (x / 2) * (b - a) + (x % 2);

        // Print the final answer
        System.out.println(ans);
    }
}
