import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String boughtLine = scanner.nextLine();
        Map<Character, Integer> boughtCount = new HashMap<>();
        for (char color : boughtLine.toCharArray()) {
            boughtCount.put(color, boughtCount.getOrDefault(color, 0) + 1);
        }
        String madeLine = scanner.nextLine();
        Map<Character, Integer> madeCount = new HashMap<>();
        for (char color : madeLine.toCharArray()) {
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
