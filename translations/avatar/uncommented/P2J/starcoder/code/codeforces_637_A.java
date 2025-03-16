import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        Map<Character, Integer> w = new HashMap<>();
        for (int i = 0; i < n; i++) {
            w.put(s.charAt(i), w.getOrDefault(s.charAt(i), 0) + 1);
        }
        int c = -1, a = 0;
        for (char i : w.keySet()) {
            if (w.get(i) == w.values().stream().max(Comparator.naturalOrder()).get()) {
                if (s.lastIndexOf(i) > c) {
                    a = i;
                    c = s.lastIndexOf(i);
                }
            }
        }
        System.out.println(a);
    }
}
