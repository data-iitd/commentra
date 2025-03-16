import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        if (s.length() == new HashSet<>(Arrays.asList(s.split(""))).size()) {
            System.out.println(0);
            return;
        }
        Map<Character, Integer> a = new HashMap<>();
        for (char c : s.toCharArray()) {
            a.put(c, a.getOrDefault(c, 0) + 1);
        }
        int ans = Math.min(a.values().stream().mapToInt(Integer::intValue).toArray()) * 2;
        System.out.println(ans);
    }
}
