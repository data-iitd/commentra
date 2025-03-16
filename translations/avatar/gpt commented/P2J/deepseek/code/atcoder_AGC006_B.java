import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int X = scanner.nextInt();

        // Check specific conditions based on the value of X
        if (X == 1 || X == N * 2 - 1) {
            // If X is at the boundaries, print "No"
            System.out.println("No");
        } else {
            // If X is within the valid range, print "Yes"
            System.out.println("Yes");

            // Handle the case where X is N * 2 - 2
            if (X == N * 2 - 2) {
                // Create a list xs with specific ranges
                int[] xs = new int[N];
                for (int i = 0; i < N - 1; i++) {
                    xs[i] = N - 1 + i;
                }
                for (int i = 1; i < N - 1; i++) {
                    xs[N - 1 + i] = i;
                }
                xs[N - 1] = X + 2;
                xs[N] = X - 1;
                xs[N + 1] = X;
                xs[N + 2] = X + 1;

                // Print each element in the final list xs
                for (int x : xs) {
                    System.out.println(x);
                }
            } else {
                // Create a list ys with specific ranges and then construct xs
                int[] ys = new int[2 * N - 2];
                for (int i = 0; i < X - 1; i++) {
                    ys[i] = i + 1;
                }
                for (int i = X + 2; i < N * 2; i++) {
                    ys[i - 3] = i;
                }
                int[] xs = new int[N];
                for (int i = 0; i < N - 3; i++) {
                    xs[i] = ys[i];
                }
                xs[N - 3] = X + 2;
                xs[N - 2] = X - 1;
                xs[N - 1] = X;
                xs[N] = X + 1;
                for (int i = 0; i < N - 3; i++) {
                    xs[N + 1 + i] = ys[N - 3 + i];
                }

                // Print each element in the final list xs
                for (int x : xs) {
                    System.out.println(x);
                }
            }
        }
    }
}
