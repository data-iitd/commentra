import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String[] input = scanner.nextLine().split(" ");
        int[] w = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(input[i]);
            sum += w[i];
        }

        List<Integer> d = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if ((sum - w[i]) * 1.0 / (n - 1) == w[i]) {
                d.add(i + 1);
            }
        }

        System.out.println(d.size());
        for (int i = 0; i < d.size(); i++) {
            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(d.get(i));
        }
        System.out.println();
    }
}
