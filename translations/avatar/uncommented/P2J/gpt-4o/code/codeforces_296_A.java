import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String[] m = scanner.nextLine().split(" ");
        
        Map<String, Integer> countMap = new HashMap<>();
        boolean possible = true;

        for (String s : m) {
            countMap.put(s, countMap.getOrDefault(s, 0) + 1);
        }

        for (int count : countMap.values()) {
            if (count >= n / 2 + 1) {
                possible = false;
                break;
            }
        }

        System.out.println(possible ? "YES" : "NO");
    }
}
// <END-OF-CODE>
