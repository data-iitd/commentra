import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<Integer, Integer> w = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            w.put(x, w.getOrDefault(x, 0) + 1);
        }
        int c = 0;
        for (Map.Entry<Integer, Integer> entry : w.entrySet()) {
            int x = entry.getKey();
            int y = entry.getValue();
            if (x == 0) {
                c += y * (y - 1);
            } else {
                if (w.containsKey(-x)) {
                    c += y * w.get(-x);
                }
            }
        }
        System.out.println(c / 2);
    }
}

