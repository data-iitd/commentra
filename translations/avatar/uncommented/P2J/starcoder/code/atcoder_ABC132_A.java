import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        Map<Character, Integer> c = new HashMap<Character, Integer>();
        for (int i = 0; i < S.length(); i++) {
            char ch = S.charAt(i);
            if (c.containsKey(ch)) {
                c.put(ch, c.get(ch) + 1);
            } else {
                c.put(ch, 1);
            }
        }
        Set<Character> Sa = c.keySet();
        if (Sa.size()!= 2) {
            System.out.println("No");
            return;
        }
        for (Character ch : Sa) {
            if (c.get(ch)!= 2) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}
