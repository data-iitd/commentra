
import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.Map;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine();
        Map<Character, Integer> c = new HashMap<>();
        Set<Character> Sa = new HashSet<>();

        for (int i = 0; i < S.length(); i++) {
            char ch = S.charAt(i);
            Sa.add(ch);
            if (c.containsKey(ch)) {
                c.put(ch, c.get(ch) + 1);
            } else {
                c.put(ch, 1);
            }
        }

        if (Sa.size() != 2) {
            System.out.println("No");
            return;
        }

        for (char ch : Sa) {
            if (c.get(ch) != 2) {
                System.out.println("No");
                return;
            }
        }

        System.out.println("Yes");
    }
}

