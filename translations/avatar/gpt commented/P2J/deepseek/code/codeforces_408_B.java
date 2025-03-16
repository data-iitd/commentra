import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        Map<Character, Integer> boughtCount = new HashMap<>();
        for (char color : line.toCharArray()) {
            boughtCount.put(color, boughtCount.getOrDefault(color, 0) + 1);
        }

        line = scanner.nextLine();
        Map<Character, Integer> madeCount = new HashMap<>();
        for (char color : line.toCharArray()) {
            madeCount.put(color, madeCount.getOrDefault(color, 0) + 1);
        }

        int res = 0;
        for (char color : madeCount.keySet()) {
            if (!boughtCount.containsKey(color)) {
                System.out.println(-1);
                return;
            }
            res += Math.min(boughtCount.get(color), madeCount.get(color));
        }

        System.out.println(res);
    }
}
