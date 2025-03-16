
import java.util.*;

public class atcoder_AGC006_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int X = scanner.nextInt();
        scanner.close();

        // Define the calc function which processes a list x
        int calc(int[] x) {
            // Define a nested sub function within calc for further processing
            int sub(int[] y, int debug) {
                // Print the current state of y if debug mode is on
                if (debug == 1) {
                    System.out.print("D ");
                    for (int i = 0; i < y.length; i++) {
                        System.out.print(y[i] + " ");
                    }
                    System.out.println();
                }
                // Reduce y by repeatedly taking triplets, sorting them, and keeping the middle element
                while (y.length > 1) {
                    int[] temp = new int[y.length - 2];
                    for (int i = 0; i < temp.length; i++) {
                        temp[i] = y[i + 1];
                    }
                    Arrays.sort(temp);
                    y = new int[]{temp[temp.length / 2]};
                }
                // Return the final single element of y
                return y[0];
            }
            // Process the input list x using sub function
            int[] y = new int[x.length];
            for (int i = 0; i < x.length; i++) {
                y[i] = x[i];
            }
            int result = sub(y, 0);
            // Check if the final element of y is 2
            if (result == 2) {
                // Call sub again with debug mode on and print the result
                sub(y, 1);
                System.out.print("= ");
                for (int i = 0; i < y.length; i++) {
                    System.out.print(y[i] + " ");
                }
                System.out.println();
            }
            // Return the first element of the final y
            return result;
        }

        // Check if X is 1 or N * 2 - 1, print "No" if true
        if (X == 1 || X == N * 2 - 1) {
            System.out.println("No");
        } else {
            // Print "Yes" if X is not 1 or N * 2 - 1
            System.out.println("Yes");
            // Construct the list xs based on the value of X
            int[] xs = new int[N];
            if (X == N * 2 - 2) {
                for (int i = 0; i < N - 1; i++) {
                    xs[i] = N - 1 + i;
                }
                for (int i = 0; i < N - 3; i++) {
                    xs[N - 3 + i] = i + 1;
                }
            } else {
                int[] ys = new int[N];
                for (int i = 0; i < N - 3; i++) {
                    ys[i] = i + 1;
                }
                for (int i = 0; i < N - 3; i++) {
                    ys[N - 3 + i] = X + 3 + i;
                }
                for (int i = 0; i < N - 3; i++) {
                    xs[i] = ys[i];
                }
                xs[N - 3] = X + 2;
                xs[N - 2] = X - 1;
                xs[N - 1] = X;
            }
            // Print each element of xs
            for (int i = 0; i < N; i++) {
                System.out.print(xs[i] + " ");
            }
        }
    }
}
