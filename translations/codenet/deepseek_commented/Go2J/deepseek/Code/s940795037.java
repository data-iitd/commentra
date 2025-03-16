import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); // Read an integer n from the standard input
        double ans = 0.0; // Initialize a variable ans to 0.0
        for (int i = 0; i < n; i++) { // Enter a loop that runs n times
            int tmp = sc.nextInt(); // Read an integer
            ans += 1.0 / tmp; // Add this result to ans
        }
        System.out.printf("%.10f\n", 1 / ans); // Calculate the reciprocal of ans and print it
    }
}
