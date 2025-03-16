import java.util.*;

public class Main {
    // Define the calc function which processes a list x
    public static int calc(List<Integer> x) {
        // Define a nested sub function within calc for further processing
        return sub(x);
    }

    private static int sub(List<Integer> y) {
        // Reduce y by repeatedly taking triplets, sorting them, and keeping the middle element
        while (y.size() > 1) {
            List<Integer> newY = new ArrayList<>();
            for (int i = 0; i < y.size() - 2; i++) {
                List<Integer> triplet = Arrays.asList(y.get(i), y.get(i + 1), y.get(i + 2));
                Collections.sort(triplet);
                newY.add(triplet.get(1));
            }
            y = newY;
        }
        // Return the final single element of y
        return y.get(0);
    }

    public static void main(String[] args) {
        // Read N and X from input
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int X = scanner.nextInt();

        // Check if X is 1 or N * 2 - 1, print "No" if true
        if (X == 1 || X == N * 2 - 1) {
            System.out.println("No");
        } else {
            // Print "Yes" if X is not 1 or N * 2 - 1
            System.out.println("Yes");
            List<Integer> xs = new ArrayList<>();

            // Construct the list xs based on the value of X
            if (X == N * 2 - 2) {
                for (int i = N - 1; i <= X + 1; i++) {
                    xs.add(i);
                }
                for (int i = 1; i < N - 1; i++) {
                    xs.add(i);
                }
            } else {
                for (int i = 1; i < X - 1; i++) {
                    xs.add(i);
                }
                for (int i = X + 3; i < N * 2; i++) {
                    xs.add(i);
                }
                xs.add(xs.size() - 3, X + 2);
                xs.add(xs.size() - 2, X - 1);
                xs.add(xs.size() - 1, X);
                xs.add(X + 1);
            }
            // Print each element of xs
            for (int x : xs) {
                System.out.println(x);
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
