import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // The solve function reads an integer n and an array of integers as.
    // It then creates a new array xs where each element is calculated as a - i + 1.
    // The array xs is sorted.
    // The median of the sorted xs is chosen as b.
    // The function calculates the sum of absolute differences between each element in xs and b.
    // The result is printed.
    private static void solve(Scanner sc) {
        int n = sc.nextInt();
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }

        int[] xs = new int[n];
        for (int i = 0; i < n; i++) {
            xs[i] = as[i] - i + 1;
        }
        Arrays.sort(xs); // Sort the array xs

        int b = xs[n / 2]; // Choose the median as b
        long ans = 0;
        for (int x : xs) {
            ans += Math.abs(x - b);
        }
        System.out.println(ans);
    }

    // The main function initializes the scanner and calls the solve function to execute the program logic.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        solve(sc);
        sc.close();
    }
}
// <END-OF-CODE>
