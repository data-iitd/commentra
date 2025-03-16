import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int n = s.length();

        Map<Character, Integer> even = new HashMap<>();
        Map<Character, Integer> odd = new HashMap<>();

        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (i % 2 == 0) {
                even.put(ch, even.getOrDefault(ch, 0) + 1);
            } else {
                odd.put(ch, odd.getOrDefault(ch, 0) + 1);
            }
        }

        int count0Even = even.getOrDefault('0', 0);
        int count1Even = even.getOrDefault('1', 0);
        int count0Odd = odd.getOrDefault('0', 0);
        int count1Odd = odd.getOrDefault('1', 0);

        int result = Math.min(n - (count0Even + count1Odd), n - (count1Even + count0Odd));
        System.out.println(result);
    }
}
// <END-OF-CODE>
