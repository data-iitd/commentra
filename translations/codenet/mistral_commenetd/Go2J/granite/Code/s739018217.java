

import java.util.Scanner;

public class s739018217{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Declare and initialize two integer variables n and m using scanner.nextInt
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Calculate the value of x using the given formula
        int x = m * 1900 + (n - m) * 100;

        // Print the result using System.out.println
        System.out.println(x * (int) Math.pow(2.0, m));
    }
}

