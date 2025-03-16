import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<Integer, Integer> w = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            if (w.containsKey(x)) {
                w.put(x, w.get(x) + 1);
            } else {
                w.put(x, 1);
            }
        }
        int c = 0;
        for (int i : w.keySet()) {
            if (i == 0) {
                c += w.get(i) * (w.get(i) - 1);
            } else {
                if (-i in w) {
                    c += w.get(i) * w.get(-i);
                }
            }
        }
        System.out.println(c / 2);
    }
}
