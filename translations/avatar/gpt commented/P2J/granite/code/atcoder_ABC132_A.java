
import java.util.Scanner;
import java.util.HashMap;

public class atcoder_ABC132_A{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        if (map.size()!= 2) {
            System.out.println("No");
            return;
        }
        for (char c : map.keySet()) {
            if (map.get(c)!= 2) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}
