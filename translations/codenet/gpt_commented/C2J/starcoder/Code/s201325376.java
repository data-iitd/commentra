import java.util.Scanner;

public class Divisors {
    public static void main(String[] args) {
        // Declare variables to hold the range (a, b) and the number (c)
        int a, b, c, i, count;

        // Read three integers from user input: a, b, and c
        Scanner input = new Scanner(System.in);
        a = input.nextInt();
        b = input.nextInt();
        c = input.nextInt();

        // Initialize count to zero to keep track of how many numbers in the range divide c
        count = 0;

        // Loop through each integer i from a to b (inclusive)
        for (i = a; i <= b; i++) {
            // Check if c is divisible by i
            if (c % i == 0)
                // If divisible, increment the count
                count++;
        }

        // Print the total count of numbers that divide c
        System.out.println(count);
    }
}
