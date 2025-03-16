// Import the collections module and specifically the Counter class
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Initialize an empty list's' by taking input from the user
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        // Create two dictionaries 'even' and 'odd' to count the frequency of '0' and '1' in the first and second half of the list's' respectively
        Map<String, Integer> even = new HashMap<>();
        Map<String, Integer> odd = new HashMap<>();
        for (int i = 0; i < s.length() / 2; i++) {
            if (even.containsKey(s.charAt(i) + "")) {
                even.put(s.charAt(i) + "", even.get(s.charAt(i) + "") + 1);
            } else {
                even.put(s.charAt(i) + "", 1);
            }
        }
        for (int i = s.length() / 2; i < s.length(); i++) {
            if (odd.containsKey(s.charAt(i) + "")) {
                odd.put(s.charAt(i) + "", odd.get(s.charAt(i) + "") + 1);
            } else {
                odd.put(s.charAt(i) + "", 1);
            }
        }

        // Print the minimum difference between the length of the list's' and the sum of the frequencies of '0' and '1' in either half of the list
        System.out.println(Math.min(s.length() - (even.get("0") + odd.get("1")), s.length() - (even.get("1") + odd.get("0"))));
    }
}

