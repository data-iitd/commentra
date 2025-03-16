
import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt();
        }
        HashMap<Integer, Integer> counter = new HashMap<>();
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (h[a-1] < h[b-1]) {
                counter.put(a, 1);
            } else if (h[a-1] > h[b-1]) {
                counter.put(b, 1);
            } else if (h[a-1] == h[b-1]) {
                counter.put(a, 1);
                counter.put(b, 1);
            }
        }
        System.out.println(n - counter.size());
    }
}

