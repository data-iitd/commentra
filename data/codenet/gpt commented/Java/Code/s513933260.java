import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input (keyboard)
        Scanner stdIn = new Scanner(System.in);

        // Read a long integer value from the user
        long n = stdIn.nextLong();

        // Calculate the sum of the first n natural numbers and subtract n from it
        // The formula used is: (n * (n + 1) / 2) - n
        // This effectively gives the sum of the first (n - 1) natural numbers
        System.out.println(n * (n + 1) / 2 - n);
    }
}
