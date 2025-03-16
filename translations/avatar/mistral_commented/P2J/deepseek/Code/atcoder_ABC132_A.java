import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.Map;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();

        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char c : S.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }

        Set<Character> uniqueChars = new HashSet<>(frequencyMap.keySet());

        if (uniqueChars.size() != 2) {
            System.out.println("No");
            return;
        }

        for (char c : uniqueChars) {
            if (frequencyMap.get(c) != 2) {
                System.out.println("No");
                return;
            }
        }

        System.out.println("Yes");
    }
}

