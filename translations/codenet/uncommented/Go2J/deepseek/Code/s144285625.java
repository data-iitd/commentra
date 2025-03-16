import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> ar = new ArrayList<>();
        for (int i = 0; i < 3 * n; i++) {
            ar.add(scanner.nextInt());
        }
        Collections.sort(ar);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ar.get(3 * n - (i + 1) * 2);
        }
        System.out.println(sum);
    }
}
