
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare variables
        long n, a, b = 0, i, j;

        // Read an unsigned long long integer from user input
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();

        // Calculate the number of ways to choose 2 items from n items
        // This is done using the formula: b = n * (n - 1) / 2
        b = (n * (n - 1)) / 2;

        // Print the result
        System.out.println(b);
    }
}

