import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int X = scanner.nextInt();

        if (X == 1 || X == N * 2 - 1) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
            List<Integer> xs = new ArrayList<>();
            if (X == N * 2 - 2) {
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
                for (int i = X + 3; i <= N * 2; i++) {
                    ys.add(i);
                }
                ys.add(X + 2);
                ys.add(X - 1);
                ys.add(X);
                ys.add(X + 1);
                xs.addAll(ys.subList(0, N - 3));
                xs.add(X + 2);
                xs.add(X - 1);
                xs.add(X);
                xs.add(X + 1);
                xs.addAll(ys.subList(N - 3, ys.size()));
            }
            for (int x : xs) {
                System.out.println(x);
            }
        }
    }
}
