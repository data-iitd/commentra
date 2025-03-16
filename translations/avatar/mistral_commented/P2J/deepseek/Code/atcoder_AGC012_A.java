import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> A = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            A.add(scanner.nextInt());
        }
        Collections.sort(A);
        int ans = 0;
        for (int i = A.size() - 2; i >= A.size() - 2 * n - 1; i -= 2) {
            ans += A.get(i);
        }
        System.out.println(ans);
    }
}

