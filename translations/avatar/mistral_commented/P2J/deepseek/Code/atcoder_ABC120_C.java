import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        if (s.chars().distinct().count() == 1) {
            System.out.println(0);
            return;
        }

        Map<Character, Integer> a = new HashMap<>();
        for (char c : s.toCharArray()) {
            a.put(c, a.getOrDefault(c, 0) + 1);
        }

        int ans = Collections.min(a.values()) * 2;
        System.out.println(ans);
    }
}

