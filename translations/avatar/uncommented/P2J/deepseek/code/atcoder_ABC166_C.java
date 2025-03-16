import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] nm = scanner.nextLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        
        int[] p = new int[n + 1];
        int[] h = new int[n + 1];
        String[] pInput = scanner.nextLine().split(" ");
        for (int i = 1; i <= n; i++) {
            p[i] = Integer.parseInt(pInput[i - 1]);
        }
        
        String[] hInput = scanner.nextLine().split(" ");
        for (int i = 1; i <= n; i++) {
            h[i] = Integer.parseInt(hInput[i - 1]);
        }
        
        List<Integer>[] path = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            path[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < m; i++) {
            String[] ab = scanner.nextLine().split(" ");
            int a = Integer.parseInt(ab[0]);
            int b = Integer.parseInt(ab[1]);
            path[a].add(b);
            path[b].add(a);
        }
        
        int c = 0;
        for (int i = 1; i <= n; i++) {
            boolean f = false;
            for (int j : path[i]) {
                if (h[i] <= h[j]) {
                    f = true;
                    break;
                }
            }
            if (!f) {
                c++;
            }
        }
        
        System.out.println(c);
    }
}
