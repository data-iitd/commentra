
import java.util.Scanner;
import java.util.HashMap;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        scan.close();

        HashMap<Character, Integer> dt = new HashMap<Character, Integer>();
        boolean x = true;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (dt.containsKey(c)) {
                dt.put(c, dt.get(c) + 1);
            } else {
                dt.put(c, 1);
            }
        }

        int cnt = 0;
        x = true;

        for (char key : dt.keySet()) {
            if (dt.get(key) % 2 != 0 && cnt < 1) {
                cnt++;
            } else if (dt.get(key) % 2 != 0 && cnt >= 1) {
                x = false;
                break;
            }
        }

        if (x) {
            System.out.println("First");
        } else if (!x && s.length() % 2 == 0) {
            System.out.println("Second");
        } else if (!x && s.length() % 2 != 0) {
            System.out.println("First");
        }
    }
}

