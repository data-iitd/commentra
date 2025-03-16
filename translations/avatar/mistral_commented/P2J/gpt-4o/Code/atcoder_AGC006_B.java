import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Define input variables
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int X = scanner.nextInt();
        // Comment: Read input values N and X from the standard input

        if (X == 1 || X == N * 2 - 1) {
            System.out.println("No");
            // If it is, print "No"
        } else {
            // Else, X is neither 1 nor N*2-1
            System.out.println("Yes");
            // Print "Yes"

            List<Integer> xs;
            if (X == N * 2 - 2) {
                xs = new ArrayList<>();
                for (int i = N - 1; i <= X + 1; i++) {
                    xs.add(i);
                }
                for (int i = 1; i < N - 1; i++) {
                    xs.add(i);
                }
            } else {
                List<Integer> ys = new ArrayList<>();
                for (int i = 1; i < X - 1; i++) {
                    ys.add(i);
                }
                for (int i = X + 3; i < N * 2; i++) {
                    ys.add(i);
                }
                xs = new ArrayList<>(ys.subList(0, N - 3));
                xs.add(X + 2);
                xs.add(X - 1);
                xs.add(X);
                xs.add(X + 1);
                xs.addAll(ys.subList(N - 3, ys.size()));
            }
            // Calculate the list xs based on the value of X

            for (int x : xs) {
                System.out.println(x);
            }
            // Print each element of the list xs
        }
    }
}
