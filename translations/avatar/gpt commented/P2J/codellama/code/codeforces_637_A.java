import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.Iterator;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String[] s = sc.nextLine().split(" ");
        Map<String, Integer> w = new HashMap<String, Integer>();
        for (int i = 0; i < n; i++) {
            if (w.containsKey(s[i])) {
                w.put(s[i], w.get(s[i]) + 1);
            } else {
                w.put(s[i], 1);
            }
        }
        int c = -1;
        String a = "";
        Set<String> keys = w.keySet();
        Iterator<String> it = keys.iterator();
        while (it.hasNext()) {
            String key = it.next();
            if (w.get(key) == Collections.max(w.values())) {
                if (s.lastIndexOf(key) > c) {
                    c = s.lastIndexOf(key);
                    a = key;
                }
            }
        }
        System.out.println(a);
    }
}

