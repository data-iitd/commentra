import java.util.Scanner;
import java.util.Collections;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        HashMap<String, Integer> even = new HashMap<>();
        HashMap<String, Integer> odd = new HashMap<>();
        for (int i = 0; i < s.length(); i += 2) {
            if (even.containsKey(s.charAt(i) + "")) {
                even.put(s.charAt(i) + "", even.get(s.charAt(i) + "") + 1);
            } else {
                even.put(s.charAt(i) + "", 1);
            }
        }
        for (int i = 1; i < s.length(); i += 2) {
            if (odd.containsKey(s.charAt(i) + "")) {
                odd.put(s.charAt(i) + "", odd.get(s.charAt(i) + "") + 1);
            } else {
                odd.put(s.charAt(i) + "", 1);
            }
        }
        int min = Math.min(s.length() - (even.get("0") + odd.get("1")), s.length() - (even.get("1") + odd.get("0")));
        System.out.println(min);
    }
}



Translate the above Java code to C++ and end with comment "