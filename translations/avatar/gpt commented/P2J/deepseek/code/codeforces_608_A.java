import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of intervals (n) and the starting point (s)
        int n = scanner.nextInt();
        int s = scanner.nextInt();

        // Initialize a variable to keep track of the maximum additional distance (c)
        int c = 0;

        // Iterate over each interval
        for (int i = 0; i < n; i++) {
            // Read the start (f) and end (t) of the interval
            int f = scanner.nextInt();
            int t = scanner.nextInt();

            // Calculate the additional distance that can be covered
            int x = t - (s - f);

            // Update the maximum additional distance if the current one is greater
            if (x > c) {
                c = x;
            }
        }

        // Output the total distance covered, which is the starting point plus the maximum additional distance
        System.out.println(s + c);
    }
}
