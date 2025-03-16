
import java.util.*;

public class codeforces_131_B{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<Integer, Integer> w = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            w.put(a, w.getOrDefault(a, 0) + 1);
        }
        long c = 0;
        for (Map.Entry<Integer, Integer> entry : w.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();
            if (key == 0) {
                c += (long) value * (value - 1);
            } else if (w.containsKey(-key)) {
                c += (long) value * w.get(-key);
            }
        }
        System.out.println(c / 2);
    }
}
