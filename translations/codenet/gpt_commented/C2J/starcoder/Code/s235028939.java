import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables n and m
        int n, m;

        // Read two integers from standard input
        // n represents the number of rows, and m represents the number of columns
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();

        // Calculate the product of (n - 1) and (m - 1)
        // This represents the number of internal edges in a grid of n by m cells
        System.out.println((n - 1) * (m - 1));

        // Flush the output buffer to ensure all output is printed
        System.out.flush();
    }
}
