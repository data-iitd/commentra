

import java.util.Scanner;

public class s502485201{
    public static void main(String[] args) {
        // Initialize variables r, d, and x with given values
        Scanner scanner = new Scanner(System.in);
        int r = scanner.nextInt();
        int d = scanner.nextInt();
        int x = scanner.nextInt();

        // Loop through 10 iterations
        for (int i = 0; i < 10; i++) {
            // Calculate new value of x using given formula
            x = r * x - d;

            // Print the current value of x
            System.out.println(x);
        }
    }
}
