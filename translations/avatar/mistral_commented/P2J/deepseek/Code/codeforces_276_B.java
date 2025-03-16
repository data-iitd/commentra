import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        char[] s = input.toCharArray();

        Map<Character, Integer> dt = new HashMap<>();
        boolean x = true;

        for (char i : s) {
            dt.put(i, dt.getOrDefault(i, 0) + 1);
        }

        int cnt = 0;
        x = true;

        for (Map.Entry<Character, Integer> entry : dt.entrySet()) {
            char key = entry.getKey();
            int value = entry.getValue();

            if (value % 2 != 0 && cnt < 1) {
                cnt++;
            } else if (value % 2 != 0 && cnt >= 1) {
                x = false;
                break;
            }
        }

        if (x) {
            System.out.println("First");
        } else if (!x && s.length % 2 == 0) {
            System.out.println("Second");
        } else if (!x && s.length % 2 != 0) {
            System.out.println("First");
        }
    }
}

