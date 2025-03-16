import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = scanner.nextInt();
        }
        Map<Integer, Integer> counter = new HashMap<>();
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            if (h[a - 1] < h[b - 1]) {
                counter.put(a, counter.getOrDefault(a, 0) + 1);
            } else if (h[a - 1] > h[b - 1]) {
                counter.put(b, counter.getOrDefault(b, 0) + 1);
            } else {
                counter.put(a, counter.getOrDefault(a, 0) + 1);
                counter.put(b, counter.getOrDefault(b, 0) + 1);
            }
        }
        System.out.println(n - counter.size());
