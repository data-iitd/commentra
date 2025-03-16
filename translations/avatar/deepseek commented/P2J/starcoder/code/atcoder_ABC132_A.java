
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        Map<Character, Integer> c = new HashMap<>();
        for (int i = 0; i < S.length(); i++) {
            char ch = S.charAt(i);
            c.put(ch, c.getOrDefault(ch, 0) + 1);
        }
        Set<Character> Sa = new HashSet<>(c.keySet());
        if (Sa.size()!= 2) {
            System.out.println("No");
            return;
        }
        for (char ch : Sa) {
            if (c.get(ch)!= 2) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}

