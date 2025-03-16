import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        char[] s = input.toCharArray();
        boolean x = true;
        Map<Character, Integer> dt = new HashMap<>();

        // Iterate over each character in the input string and update the frequency count in the dictionary
        for (char i : s) {
            dt.put(i, dt.getOrDefault(i, 0) + 1);
        }

        int cnt = 0;
        x = true;

        // Iterate over the items in the dictionary to determine if there is more than one character with an odd frequency
        for (Map.Entry<Character, Integer> entry : dt.entrySet()) {
            char key = entry.getKey();
            int value = entry.getValue();
            if (value % 2 != 0 && cnt < 1) {
                cnt += 1;
            } else if (value % 2 != 0 && cnt >= 1) {
                x = false;
                break;
            }
        }

        // Determine the output based on the value of cnt and the length of the input string
        if (x) {
            System.out.println("First");
        } else if (!x && s.length % 2 == 0) {
            System.out.println("Second");
        } else if (!x && s.length % 2 != 0) {
            System.out.println("First");
        }
