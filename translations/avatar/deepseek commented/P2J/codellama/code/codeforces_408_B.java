
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.Iterator;
import java.util.TreeSet;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            String bought = sc.next();
            String made = sc.next();
            Map<Character, Integer> boughtMap = new HashMap<>();
            Map<Character, Integer> madeMap = new HashMap<>();
            for (int j = 0; j < bought.length(); j++) {
                char c = bought.charAt(j);
                if (boughtMap.containsKey(c)) {
                    boughtMap.put(c, boughtMap.get(c) + 1);
                } else {
                    boughtMap.put(c, 1);
                }
            }
            for (int j = 0; j < made.length(); j++) {
                char c = made.charAt(j);
                if (madeMap.containsKey(c)) {
                    madeMap.put(c, madeMap.get(c) + 1);
                } else {
                    madeMap.put(c, 1);
                }
            }
            int res = 0;
            Set<Character> keys = new TreeSet<>(madeMap.keySet());
            Iterator<Character> it = keys.iterator();
            while (it.hasNext()) {
                char c = it.next();
                if (!boughtMap.containsKey(c)) {
                    System.out.println(-1);
                    return;
                }
                int min = Math.min(boughtMap.get(c), madeMap.get(c));
                res += min;
            }
            System.out.println(res);
        }
    }
}

