import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
        }
        Arrays.sort(a, 1, n + 1);
        List<Integer> q = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (i < n && a[i] == a[i + 1]) {
                q.add(a[i]);
                i++;
            }
        }
        System.out.println(q.get(q.size() - 1) * q.get(q.size() - 2));
    }
}

