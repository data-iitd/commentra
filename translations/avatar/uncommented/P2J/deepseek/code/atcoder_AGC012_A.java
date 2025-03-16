import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> A = new ArrayList<>();
        for (int i = 0; i < 3 * n; i++) {
            A.add(scanner.nextInt());
        }
        Collections.sort(A);
        long ans = 0;
        for (int i = 3 * n - 2; i >= n; i -= 2) {
            ans += A.get(i);
        }
        System.out.println(ans);
    }
}
