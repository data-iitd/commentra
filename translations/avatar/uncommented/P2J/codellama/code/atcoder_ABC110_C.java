import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String t = sc.nextLine();
        System.out.println(run(s, t));
    }

    public static String run(String s, String t) {
        int[] ss = getCounts(s);
        int[] tt = getCounts(t);
        if (Arrays.equals(ss, tt)) {
            return "Yes";
        } else {
            return "No";
        }
    }

    public static int[] getCounts(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            } else {
                map.put(c, 1);
            }
        }
        Set<Integer> set = new TreeSet<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            set.add(entry.getValue());
        }
        int[] counts = new int[set.size()];
        int i = 0;
        for (Integer count : set) {
            counts[i++] = count;
        }
        return counts;
    }
}

