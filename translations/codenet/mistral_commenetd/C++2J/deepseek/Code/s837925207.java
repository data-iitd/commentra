import java.util.Scanner;

public class Main {
    // Initialize arrays h and w of size 6
    static int[] h = new int[6];
    static int[] w = new int[6];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x, ans = 0; // Initialize x and ans to zero

        // Read input value of x from the user
        x = scanner.nextInt();

        // Calculate the answer using the given formula
        ans = x + x*x + x*x*x;

        // Output the answer to the user
        System.out.println(ans);
    }
}
