
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner stdIn = new Scanner(System.in);

        // Read the next long value from the input and store it in variable n
        long n = stdIn.nextLong();

        // Perform the calculation: sum of the first n natural numbers minus n
        System.out.println(n * (n + 1) / 2 - n);
    }
}

