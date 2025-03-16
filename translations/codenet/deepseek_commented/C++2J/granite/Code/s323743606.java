
import java.util.*;

public class s323743606{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i * 200 < 5001; i++) {
            for (int j = 0; j * 300 < 5001; j++) {
                for (int k = 0; k * 500 < 5001; k++) {
                    int w = i * 200 + j * 300 + k * 500;
                    int p = i / 5 * 5 * 380 * 0.8 + i % 5 * 380
                            + j / 4 * 4 * 550 * 0.85 + j % 4 * 550
                            + k / 3 * 3 * 850 * 0.88 + k % 3 * 850;
                    if (map.containsKey(w)) {
                        map.put(w, Math.min(map.get(w), p));
                    } else {
                        map.put(w, p);
                    }
                }
            }
        }
        while (true) {
            int n = sc.nextInt();
            if (n == 0) {
                break;
            }
            System.out.println(map.get(n));
        }
    }
}
