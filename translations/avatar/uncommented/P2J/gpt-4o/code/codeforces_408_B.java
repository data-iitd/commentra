import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = 1; // Number of test cases
        for (int i = 0; i < t; i++) {
            solution(scanner);
        }
        scanner.close();
    }

    public static void solution(Scanner scanner) {
        String line = scanner.nextLine();
        Map<Character, Integer> boughtCount = countCharacters(line);
        
        line = scanner.nextLine();
        Map<Character, Integer> madeCount = countCharacters(line);
        
        int res = 0;
        for (char color : madeCount.keySet()) {
            if (!boughtCount.containsKey(color)) {
                System.out.println(-1);
                return;
            }
            res += Math.min(boughtCount.get(color), madeCount.get(color));
        }
        System.out.println(res);
    }

    private static Map<Character, Integer> countCharacters(String line) {
        Map<Character, Integer> countMap = new HashMap<>();
        for (char c : line.toCharArray()) {
            countMap.put(c, countMap.getOrDefault(c, 0) + 1);
        }
        return countMap;
    }
}

// <END-OF-CODE>
