import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.Map;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        
        Map<Character, Integer> c = new HashMap<>();
        for (char ch : S.toCharArray()) {
            c.put(ch, c.getOrDefault(ch, 0) + 1);
        }
        
        Set<Character> Sa = new HashSet<>();
        for (char ch : S.toCharArray()) {
            Sa.add(ch);
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
