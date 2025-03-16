import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        Map<String, Integer> bought = new HashMap<>();
        Map<String, Integer> made = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String color = sc.next();
            int count = sc.nextInt();
            bought.put(color, count);
        }
        for (int i = 0; i < m; i++) {
            String color = sc.next();
            int count = sc.nextInt();
            made.put(color, count);
        }
        int res = 0;
        for (String color : made.keySet()) {
            if (!bought.containsKey(color)) {
                System.out.println(-1);
                return;
            }
            res += Math.min(bought.get(color), made.get(color));
        }
        System.out.println(res);
    }
}
