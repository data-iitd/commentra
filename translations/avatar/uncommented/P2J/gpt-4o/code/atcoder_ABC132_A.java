import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        
        HashMap<Character, Integer> counter = new HashMap<>();
        HashSet<Character> uniqueChars = new HashSet<>();
        
        for (char c : S.toCharArray()) {
            counter.put(c, counter.getOrDefault(c, 0) + 1);
            uniqueChars.add(c);
        }
        
        if (uniqueChars.size() != 2) {
            System.out.println("No");
            return;
        }
        
        for (char c : uniqueChars) {
            if (counter.get(c) != 2) {
                System.out.println("No");
                return;
            }
        }
        
        System.out.println("Yes");
    }
}
// <END-OF-CODE>
